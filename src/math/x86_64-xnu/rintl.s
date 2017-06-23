.global _rintl
_rintl:
	fldt 8(%rsp)
	frndint
	ret
