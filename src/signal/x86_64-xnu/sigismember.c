#include <signal.h>

int sigismember(const sigset_t *set, int sig)
{
	return ((set->__bits[0] & __sigbits(sig)) != 0);
}
