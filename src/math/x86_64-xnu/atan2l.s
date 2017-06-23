.global _atan2l
_atan2l:
	fldt 8(%rsp)
	fldt 24(%rsp)
	fpatan
	ret
