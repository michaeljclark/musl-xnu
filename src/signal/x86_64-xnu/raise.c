#include <signal.h>
#include <stdint.h>
#include "syscall.h"

int raise(int sig)
{
	int tid, ret;
	sigset_t set;
	//__block_app_sigs(&set);
	tid = __syscall(SYS_getpid);
	ret = syscall(SYS_kill, tid, sig);
	//__restore_sigs(&set);
	return ret;
}
