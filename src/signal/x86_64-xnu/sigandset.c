#define _GNU_SOURCE
#include <signal.h>

int sigandset(sigset_t *dest, const sigset_t *left, const sigset_t *right)
{
	dest->__bits[0] = left->__bits[0] & right->__bits[0];
	return 0;
}

