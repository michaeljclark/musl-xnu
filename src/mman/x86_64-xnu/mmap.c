#include <unistd.h>
#include <sys/mman.h>
#include <errno.h>
#include <stdint.h>
#include <limits.h>
#include "syscall.h"
#include "libc.h"

#define UNIT SYSCALL_MMAP2_UNIT
#define OFF_MASK ((-0x2000ULL << (8*sizeof(long)-1)) | (UNIT-1))

void *mmap(void *start, size_t len, int prot, int flags, int fd, off_t off)
{
	if (off & OFF_MASK) {
		errno = EINVAL;
		return MAP_FAILED;
	}
	if (len >= PTRDIFF_MAX) {
		errno = ENOMEM;
		return MAP_FAILED;
	}
	return (void *)syscall(SYS_mmap, start, len, prot, flags, fd, off);
}
