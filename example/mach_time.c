#include <stdio.h>
#include <mach/mach_time.h>

int main(int argc, char **argv)
{
	mach_timebase_info_data_t timebaseInfo;
	mach_timebase_info(&timebaseInfo);
	uint64_t timebase = timebaseInfo.numer / timebaseInfo.denom;
	uint64_t time = mach_absolute_time();
	printf("time=%llu (timebase=%lluns)\n", time, timebase);
	return 0;
}
