.global _atanl
_atanl:
	fldt 8(%rsp)
	fld1
	fpatan
	ret
