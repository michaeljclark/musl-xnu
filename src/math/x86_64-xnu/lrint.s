.global _lrint
_lrint:
	cvtsd2si %xmm0,%rax
	ret
