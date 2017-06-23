.global _lrintf
_lrintf:
	cvtss2si %xmm0,%rax
	ret
