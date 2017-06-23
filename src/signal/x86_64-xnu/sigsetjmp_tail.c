#include <setjmp.h>
#include <signal.h>
#include "syscall.h"

__attribute__((__visibility__("hidden")))
int __sigsetjmp_tail(sigjmp_buf jb, int ret)
{
	void *p = jb->__ss;
	__syscall(SYS_sigprocmask, SIG_SETMASK, ret?p:0, ret?0:p);
	return ret;
}
