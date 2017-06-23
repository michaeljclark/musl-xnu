#if defined(_POSIX_SOURCE) || defined(_POSIX_C_SOURCE) \
 || defined(_XOPEN_SOURCE) || defined(_GNU_SOURCE) || defined(_BSD_SOURCE)

#if defined(_XOPEN_SOURCE) || defined(_GNU_SOURCE) || defined(_BSD_SOURCE)
#define MINSIGSTKSZ 2048
#define SIGSTKSZ 8192
#endif

#ifdef _GNU_SOURCE
#define REG_R8          0
#define REG_R9          1
#define REG_R10         2
#define REG_R11         3
#define REG_R12         4
#define REG_R13         5
#define REG_R14         6
#define REG_R15         7
#define REG_RDI         8
#define REG_RSI         9
#define REG_RBP         10
#define REG_RBX         11
#define REG_RDX         12
#define REG_RAX         13
#define REG_RCX         14
#define REG_RSP         15
#define REG_RIP         16
#define REG_EFL         17
#define REG_CSGSFS      18
#define REG_ERR         19
#define REG_TRAPNO      20
#define REG_OLDMASK     21
#define REG_CR2         22
#endif

typedef struct {
	unsigned long __space[32];
} mcontext_t;

struct sigaltstack {
	void *ss_sp;
	size_t ss_size;
	int ss_flags;
};

typedef struct __ucontext {
	int uc_onstack;
	sigset_t uc_sigmask;
	struct sigaltstack uc_stack;
	struct __ucontext *uc_link;
	size_t uc_mcsize;
	mcontext_t *uc_mcontext;
	mcontext_t __mcontext_data;
} ucontext_t;

#define SA_ONSTACK      0x0001
#define SA_RESTART      0x0002
#define SA_RESETHAND    0x0004
#define SA_NOCLDSTOP    0x0008
#define SA_NODEFER      0x0010
#define SA_NOCLDWAIT    0x0020
#define SA_SIGINFO      0x0040
#define SA_USERTRAMP    0x0100
#define SA_64REGSET     0x0200

#endif

#define SIGHUP  1
#define SIGINT  2
#define SIGQUIT 3
#define SIGILL  4
#define SIGTRAP 5
#define SIGABRT 6
#define SIGPOLL 7
#define SIGFPE  8
#define SIGKILL 9
#define SIGBUS  10
#define SIGSEGV 11
#define SIGSYS  12
#define SIGPIPE 13
#define SIGALRM 14
#define SIGTERM 15
#define SIGURG  16
#define SIGSTOP 17
#define SIGTSTP 18
#define SIGCONT 19
#define SIGCHLD 20
#define SIGTTIN 21
#define SIGTTOU 22
#define SIGIO   23
#define SIGXCPU 24
#define SIGXFSZ 25
#define SIGVTALRM 26
#define SIGPROF 27
#define SIGWINCH 28
#define SIGINFO 29
#define SIGUSR1 30
#define SIGUSR2 31

#define _NSIG 32

#define UC_TRAD 1
#define UC_FLAVOR 30
