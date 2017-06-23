.global _log2l
_log2l:
	fld1
	fldt 8(%rsp)
	fyl2x
	ret
