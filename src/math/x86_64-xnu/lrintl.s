.global _lrintl
_lrintl:
	fldt 8(%rsp)
	fistpll 8(%rsp)
	mov 8(%rsp),%rax
	ret
