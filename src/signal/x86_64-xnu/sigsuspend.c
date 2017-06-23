#include <signal.h>
#include "syscall.h"
#include "libc.h"

int sigsuspend(const sigset_t *mask)
{
	return syscall(SYS_sigsuspend, mask);
}
