#include <signal.h>
#include <errno.h>

int sigaddset(sigset_t *set, int sig)
{
	return (set->__bits[0] |= __sigbits(sig), 0);
}
