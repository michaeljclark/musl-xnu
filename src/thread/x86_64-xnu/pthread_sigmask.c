#include <signal.h>
#include <pthread.h>
#include "syscall.h"

int pthread_sigmask(int how, const sigset_t * restrict set, sigset_t * restrict oset)
{
	return syscall(SYS___pthread_sigmask, how, set, oset);
}
