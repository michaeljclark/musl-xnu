#include <signal.h>
#include <errno.h>
#include "syscall.h"

int sigprocmask(int how, const sigset_t *restrict set, sigset_t *restrict old)
{
	int r = syscall(SYS_sigprocmask, how, set, old);
	if (!r) return r;
	errno = r;
	return -1;
}
