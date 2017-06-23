#include <signal.h>
#include <limits.h>

int sigfillset(sigset_t *set)
{
	set->__bits[0] = 0xffffffff;
	return 0;
}
