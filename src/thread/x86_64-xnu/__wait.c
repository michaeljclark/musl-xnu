#include "pthread_impl.h"

void __wait(volatile int *addr, volatile int *waiters, int val, int priv)
{
	for (;;) {
		if (*addr==val) a_spin();
		else return;
	}
}
