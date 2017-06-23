.global _llrint
_llrint:
	cvtsd2si %xmm0,%rax
	ret
