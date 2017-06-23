#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

static volatile int running;

void signal_handler(int signum, siginfo_t *info, void *uap)
{
	printf("got signal\n");
	running = 0;
}

int main(int argc, char **argv)
{
	struct sigaction sigaction_handler;
	memset(&sigaction_handler, 0, sizeof(sigaction_handler));
	sigaction_handler.sa_sigaction = &signal_handler;
	sigaction_handler.sa_flags = SA_SIGINFO;
	if (sigaction(SIGHUP, &sigaction_handler, NULL) < 0) {
		printf("sigaction failed\n");
	}

	sigset_t set;
	sigemptyset(&set);
	sigaddset(&set, SIGHUP);
	if (sigprocmask(SIG_UNBLOCK, &set, NULL) < 0) {
		printf("sigprocmask failed\n");
	}

	printf("pid %d\n", getpid());

	running = 1;
	kill(getpid(), SIGHUP);
	while(running);
	printf("exiting\n");

	return 0;
}
