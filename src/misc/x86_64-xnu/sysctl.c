#include <stdlib.h>
#include <sys/utsname.h>
#include <bits/sysctl.h>
#include "syscall.h"

int sysctl(int *name, unsigned namelen, void *oldp, size_t *oldlenp, void *newp, size_t newlen)
{
	return syscall(SYS_sysctl, name, namelen, oldp, oldlenp, newp, newlen);
}
