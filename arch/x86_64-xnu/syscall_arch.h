#define __SYSCALL_LL_E(x) (x)
#define __SYSCALL_LL_O(x) (x)

#define MACH_SYSCALL 0x1000000
#define UNIX_SYSCALL 0x2000000
#define ARCH_SYSCALL 0x3000000

struct kern_return
{
	long ret;
	long err;
};

static __inline long __syscall0(long n)
{
	unsigned long ret;
	__asm__ __volatile__ ("syscall; jae 1f; negq %%rax; 1:" : "=a"(ret) : "a"(UNIX_SYSCALL + n) : "rcx", "r11", "memory");
	return ret;
}

static __inline long __syscall1(long n, long a1)
{
	unsigned long ret;
	__asm__ __volatile__ ("syscall; jae 1f; negq %%rax; 1:" : "=a"(ret) : "a"(UNIX_SYSCALL + n), "D"(a1) : "rcx", "r11", "memory");
	return ret;
}

static __inline long __syscall2(long n, long a1, long a2)
{
	unsigned long ret;
	__asm__ __volatile__ ("syscall; jae 1f; negq %%rax; 1:" : "=a"(ret) : "a"(UNIX_SYSCALL + n), "D"(a1), "S"(a2)
						  : "rcx", "r11", "memory");
	return ret;
}

static __inline long __syscall3(long n, long a1, long a2, long a3)
{
	unsigned long ret;
	__asm__ __volatile__ ("syscall; jae 1f; negq %%rax; 1:" : "=a"(ret) : "a"(UNIX_SYSCALL + n), "D"(a1), "S"(a2),
						  "d"(a3) : "rcx", "r11", "memory");
	return ret;
}

static __inline long __syscall4(long n, long a1, long a2, long a3, long a4)
{
	unsigned long ret;
	register long r10 __asm__("r10") = a4;
	__asm__ __volatile__ ("syscall; jae 1f; negq %%rax; 1:" : "=a"(ret) : "a"(UNIX_SYSCALL + n), "D"(a1), "S"(a2),
						  "d"(a3), "r"(r10): "rcx", "r11", "memory");
	return ret;
}

static __inline long __syscall5(long n, long a1, long a2, long a3, long a4, long a5)
{
	unsigned long ret;
	register long r10 __asm__("r10") = a4;
	register long r8 __asm__("r8") = a5;
	__asm__ __volatile__ ("syscall; jae 1f; negq %%rax; 1:" : "=a"(ret) : "a"(UNIX_SYSCALL + n), "D"(a1), "S"(a2),
						  "d"(a3), "r"(r10), "r"(r8) : "rcx", "r11", "memory");
	return ret;
}

static __inline long __syscall6(long n, long a1, long a2, long a3, long a4, long a5, long a6)
{
	unsigned long ret;
	register long r10 __asm__("r10") = a4;
	register long r8 __asm__("r8") = a5;
	register long r9 __asm__("r9") = a6;
	__asm__ __volatile__ ("syscall; jae 1f; negq %%rax; 1:" : "=a"(ret) : "a"(UNIX_SYSCALL + n), "D"(a1), "S"(a2),
						  "d"(a3), "r"(r10), "r"(r8), "r"(r9) : "rcx", "r11", "memory");
	return ret;
}

static __inline long __mach_syscall0(long n)
{
	unsigned long ret;
	__asm__ __volatile__ ("syscall" : "=a"(ret) : "a"(MACH_SYSCALL + n) : "rcx", "r11", "memory");
	return ret;
}

static __inline long __mach_syscall1(long n, long a1)
{
	unsigned long ret;
	__asm__ __volatile__ ("syscall" : "=a"(ret) : "a"(MACH_SYSCALL + n), "D"(a1) : "rcx", "r11", "memory");
	return ret;
}

static __inline long __mach_syscall2(long n, long a1, long a2)
{
	unsigned long ret;
	__asm__ __volatile__ ("syscall" : "=a"(ret) : "a"(MACH_SYSCALL + n), "D"(a1), "S"(a2)
						  : "rcx", "r11", "memory");
	return ret;
}

static __inline long __mach_syscall3(long n, long a1, long a2, long a3)
{
	unsigned long ret;
	__asm__ __volatile__ ("syscall" : "=a"(ret) : "a"(MACH_SYSCALL + n), "D"(a1), "S"(a2),
						  "d"(a3) : "rcx", "r11", "memory");
	return ret;
}

static __inline long __mach_syscall4(long n, long a1, long a2, long a3, long a4)
{
	unsigned long ret;
	register long r10 __asm__("r10") = a4;
	__asm__ __volatile__ ("syscall" : "=a"(ret) : "a"(MACH_SYSCALL + n), "D"(a1), "S"(a2),
						  "d"(a3), "r"(r10): "rcx", "r11", "memory");
	return ret;
}

static __inline long __mach_syscall5(long n, long a1, long a2, long a3, long a4, long a5)
{
	unsigned long ret;
	register long r10 __asm__("r10") = a4;
	register long r8 __asm__("r8") = a5;
	__asm__ __volatile__ ("syscall" : "=a"(ret) : "a"(MACH_SYSCALL + n), "D"(a1), "S"(a2),
						  "d"(a3), "r"(r10), "r"(r8) : "rcx", "r11", "memory");
	return ret;
}

static __inline long __mach_syscall6(long n, long a1, long a2, long a3, long a4, long a5, long a6)
{
	unsigned long ret;
	register long r10 __asm__("r10") = a4;
	register long r8 __asm__("r8") = a5;
	register long r9 __asm__("r9") = a6;
	__asm__ __volatile__ ("syscall" : "=a"(ret) : "a"(MACH_SYSCALL + n), "D"(a1), "S"(a2),
						  "d"(a3), "r"(r10), "r"(r8), "r"(r9) : "rcx", "r11", "memory");
	return ret;
}
