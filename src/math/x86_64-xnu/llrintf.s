.global _llrintf
_llrintf:
	cvtss2si %xmm0,%rax
	ret
