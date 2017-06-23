#define _GNU_SOURCE
#include <signal.h>
#include <string.h>

int sigisemptyset(const sigset_t *set)
{
	return set->__bits[0] == 0;
}
