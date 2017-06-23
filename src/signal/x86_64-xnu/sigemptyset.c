#include <signal.h>
#include <string.h>

int sigemptyset(sigset_t *set)
{
	set->__bits[0] = 0;
	return 0;
}
