#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/ioctl.h>

int main(int argc, char **argv)
{
	struct winsize wsz;
	int ret = ioctl(fileno(stdin), TIOCGWINSZ, &wsz);
	if (ret < 0) {
		fprintf(stderr, "ioctl: %s\n", strerror(errno));
		exit(9);
	}
	printf("ws_row=%d\n", wsz.ws_row);
	printf("ws_col=%d\n", wsz.ws_col);
	return 0;
}
