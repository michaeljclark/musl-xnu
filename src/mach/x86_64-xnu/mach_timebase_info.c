#include <mach/mach_time.h>
#include "syscall.h"
#include "mach_syscall.h"

int mach_timebase_info(struct mach_timebase_info *info)
{
	return mach_syscall(MACH_mach_timebase_info_trap, info);
}
