.global _sqrtl
_sqrtl:	fldt 8(%rsp)
	fsqrt
	ret
