#include <stdio.h>
#include <stdlib.h>

static const char *text = "";

int main(int argc, char **argv, char **envp, char **applep)
{
	printf("prog=%s\n", argv[0]);
	printf("argc=%d\n", argc);
	for (size_t i = 1; i < argc; i++) {
		printf("argv[%zu]=\"%s\"\n", i, argv[i]);
	}
	while (*applep != NULL) {
		printf("apple: %s\n", *applep++);
	}
	void *p = malloc(128);
	printf("text  : %p\n", text);
	printf("stack : %p\n", argv);
	printf("heap  : %p\n", p);
	free(p);
	exit(1);
}
