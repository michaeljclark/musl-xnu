#include <signal.h>
#include <errno.h>
#include <string.h>
#include "syscall.h"
#include "libc.h"

static void __sigtramp(
        union __sigaction_u   __sigaction_u,
        int                     sigstyle,
        int                     sig,
        siginfo_t               *sinfo,
        ucontext_t              *uctx)
{
	sa_sigaction(sig, sinfo, uctx);
	syscall(SYS_sigreturn, uctx, UC_FLAVOR);
}

int sigaction(int sig, const struct sigaction *restrict sa, struct sigaction *restrict old)
{
	((struct sigaction *)sa)->sa_tramp = &__sigtramp;
	return syscall(SYS_sigaction, sig, sa, old);
}
