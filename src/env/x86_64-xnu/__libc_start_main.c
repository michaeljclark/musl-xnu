#include <elf.h>
#include <poll.h>
#include <fcntl.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include "syscall.h"
#include "atomic.h"
#include "libc.h"

extern uintptr_t __mmap_base;
extern void __init_ssp(void *p);
extern uintptr_t __arch_entropy();
extern uintptr_t __env_entropy(char **envp);
extern void __init_tls();

typedef void (*__init_fn)(int, char **, char **, char **);
extern __init_fn  __init_start  __asm("section$start$__DATA$__mod_init_func");
extern __init_fn  __init_end    __asm("section$end$__DATA$__mod_init_func");

static void __init_mod(int argc, char **argv, char **envp, char **applep)
{
        for (__init_fn *p = &__init_start; p < &__init_end; ++p) {
                (*p)(argc, argv, envp, applep);
        }
}

void __init_libc(char **envp, char *pn)
{
	size_t i;
	__environ = envp;
	for (i=0; envp[i]; i++);

	if (pn) {
		__progname = __progname_full = pn;
		for (i=0; pn[i]; i++) if (pn[i]=='/') __progname = pn+i+1;
	}

	__init_tls();

	struct pollfd pfd[3] = { {.fd=0}, {.fd=1}, {.fd=2} };
	__syscall(SYS_poll, pfd, 3, 0);
	for (i=0; i<3; i++) if (pfd[i].revents&POLLNVAL)
		if (__sys_open("/dev/null", O_RDWR)<0)
			a_crash();
	libc.secure = 1;
}

uintptr_t __apple_stack_guard(char **applep)
{
	uintptr_t entropy = 0;
	while (*applep != 0) {
		if (strncmp(*applep, "stack_guard=0x", 14) == 0) {
			entropy = strtoull(*applep + 14, NULL, 16);
			return entropy;
		}
		applep++;
	}
	abort();
}

int __libc_start_main(int (*main)(int,char **,char **,char **), int argc, char **argv)
{
	char **envp = argv+argc+1;
	char **applep = envp;
	while (*applep != 0) applep++;
	applep++;

	uintptr_t entropy = __apple_stack_guard(applep);
	__mmap_base += __arch_entropy() & 0xffff000;

	__init_ssp((void*)&entropy);
	__init_mod(argc, argv, envp, applep);
	__init_libc(envp, argv[0]);

	/* Pass control to the application */
	exit(main(argc, argv, envp, applep));
	return 0;
}
