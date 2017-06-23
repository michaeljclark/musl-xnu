#include <fcntl.h>
#include <stdarg.h>
#include <errno.h>
#include <string.h>
#include "syscall.h"
#include "libc.h"

int open(const char *filename, int flags, ...)
{
	mode_t mode = 0;

	if (flags & O_CREAT) {
		va_list ap;
		va_start(ap, flags);
		mode = va_arg(ap, mode_t);
		va_end(ap);
	}

	int fd = __syscall(SYS_open_nocancel, filename, flags, mode);
	return __syscall_ret(fd);
}
