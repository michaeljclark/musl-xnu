#include <time.h>
#include <errno.h>
#include <stdint.h>
#include "syscall.h"
#include "libc.h"
#include "atomic.h"

int clock_gettime(clockid_t clk, struct timespec *ts)
{
	int r;

	if (clk == CLOCK_REALTIME) {
		__syscall(SYS_gettimeofday, ts, 0);
		ts->tv_nsec = (int)ts->tv_nsec * 1000;
		return 0;
	}
	r = -EINVAL;
	return __syscall_ret(r);
}
