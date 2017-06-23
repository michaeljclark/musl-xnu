.global _logl
_logl:
	fldln2
	fldt 8(%rsp)
	fyl2x
	ret
