#include <signal.h>
#include <errno.h>

int sigdelset(sigset_t *set, int sig)
{
	return (set->__bits[0] &= ~__sigbits(sig), 0);
}
