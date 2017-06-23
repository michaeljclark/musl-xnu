.global _fabsl
_fabsl:
	fldt 8(%rsp)
	fabs
	ret
