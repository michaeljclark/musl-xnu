#include <sys/mman.h>
#include "syscall.h"
#include "libc.h"

int munmap(void *start, size_t len)
{
	return syscall(SYS_munmap, start, len);
}

