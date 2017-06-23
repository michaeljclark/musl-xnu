#ifndef	_SYS_UTSNAME_H
#define	_SYS_UTSNAME_H

#ifdef __cplusplus
extern "C" {
#endif

#include <features.h>

#if defined (__APPLE__)
struct  utsname {
	char sysname[256];
	char nodename[256];
	char release[256];
	char version[256];
	char machine[256];
};
#else
struct utsname {
	char sysname[65];
	char nodename[65];
	char release[65];
	char version[65];
	char machine[65];
#ifdef _GNU_SOURCE
	char domainname[65];
#else
	char __domainname[65];
#endif
};
#endif

int uname (struct utsname *);

#ifdef __cplusplus
}
#endif

#endif
