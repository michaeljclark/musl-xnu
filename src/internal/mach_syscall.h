#ifndef _INTERNAL_MACH_SYSCALL_H
#define _INTERNAL_MACH_SYSCALL_H

#define __mach_syscall1(n,a) __mach_syscall1(n,__scc(a))
#define __mach_syscall2(n,a,b) __mach_syscall2(n,__scc(a),__scc(b))
#define __mach_syscall3(n,a,b,c) __mach_syscall3(n,__scc(a),__scc(b),__scc(c))
#define __mach_syscall4(n,a,b,c,d) __mach_syscall4(n,__scc(a),__scc(b),__scc(c),__scc(d))
#define __mach_syscall5(n,a,b,c,d,e) __mach_syscall5(n,__scc(a),__scc(b),__scc(c),__scc(d),__scc(e))
#define __mach_syscall6(n,a,b,c,d,e,f) __mach_syscall6(n,__scc(a),__scc(b),__scc(c),__scc(d),__scc(e),__scc(f))

#define __mach_syscall(...) __SYSCALL_DISP(__mach_syscall,__VA_ARGS__)
#define mach_syscall(...) __syscall_ret(__mach_syscall(__VA_ARGS__))

#endif
