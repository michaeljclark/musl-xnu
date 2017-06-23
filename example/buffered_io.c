#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main(int argc, char **argv)
{
	FILE *file = NULL;
	char line_buf[256], *buf;

	if (argc != 2) {
		printf("usage: %s <filename>\n", argv[0]);
		exit(1);
	}
	if ((file = fopen(argv[1], "r")) == NULL) {
		printf("error: %s\n", strerror(errno));
		exit(1);
	}

	while ((buf = fgets(line_buf, sizeof(line_buf), file)) != NULL) {
		printf("%s", buf);
	}

	fclose(file);
	return 0;
}
