#include <stdint.h>

uintptr_t __arch_entropy()
{
	uintptr_t entropy;
	__asm__(
		"	movl    $1, %%eax \n"   /* cpuid leaf 1 */
		"	cpuid   \n"
		"	btl     $30, %%ecx \n"  /* ecx.bit[30] rdrand? */
		"	jnc     2f \n"
		"1:	rdrand  %%rax \n"
		"	jnc     1b \n"
		"2: \n"
	  : "=a"(entropy)
	  :
	  : "rbx", "rcx", "rdx"
	);
	return entropy;
}
