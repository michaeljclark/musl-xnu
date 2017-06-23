#include <limits.h>
#include <stdint.h>
#include <errno.h>
#include <sys/mman.h>
#include "libc.h"
#include "syscall.h"

extern uint64_t __mmap_base;

/* This function returns true if the interval [old,new]
 * intersects the 'len'-sized interval below &libc.auxv
 * (interpreted as the main-thread stack) or below &b
 * (the current stack). It is used to defend against
 * buggy brk implementations that can cross the stack. */

static int traverses_stack_p(uintptr_t old, uintptr_t new)
{
	const uintptr_t len = 8<<20;
	uintptr_t a, b;

	b = (uintptr_t)libc.auxv;
	a = b > len ? b-len : 0;
	if (new>a && old<b) return 1;

	b = (uintptr_t)&b;
	a = b > len ? b-len : 0;
	if (new>a && old<b) return 1;

	return 0;
}

void *mmap(void *, size_t, int, int, int, off_t);

/* Expand the heap in-place if brk can be used, or otherwise via mmap,
 * using an exponential lower bound on growth by mmap to make
 * fragmentation asymptotically irrelevant. The size argument is both
 * an input and an output, since the caller needs to know the size
 * allocated, which will be larger than requested due to page alignment
 * and mmap minimum size rules. The caller is responsible for locking
 * to prevent concurrent calls. */

void *__expand_heap(size_t *pn)
{
	static unsigned mmap_step;
	size_t n = *pn;

	if (n > SIZE_MAX/2 - PAGE_SIZE) {
		errno = ENOMEM;
		return 0;
	}
	n += -n & PAGE_SIZE-1;

	size_t min = (size_t)PAGE_SIZE << mmap_step/2;
	if (n < min) n = min;
	void *area = mmap((void*)__mmap_base, n, PROT_READ|PROT_WRITE,
		MAP_PRIVATE|MAP_ANONYMOUS, -1, 0);
	if (area == MAP_FAILED) return 0;
	__mmap_base += n;
	*pn = n;
	mmap_step++;
	return area;
}
