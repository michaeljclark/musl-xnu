#define _GNU_SOURCE
#include <signal.h>

#define SST_SIZE (_NSIG/8/sizeof(long))

int sigorset(sigset_t *dest, const sigset_t *left, const sigset_t *right)
{
	dest->__bits[0] = left->__bits[0] | right->__bits[0];
	return 0;
}

