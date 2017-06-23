.text
.global ___set_thread_area
___set_thread_area:
	movl $0,%esi            /* 0 as the 2nd arg */
	movl $0x3000003,%eax    /* machine dependent syscall 3 */
	syscall                 /* machine_set_tsd_base(arg, 0) */
	ret
