#include "stdio_impl.h"

extern FILE *volatile __stdin_used;
extern FILE *volatile __stdout_used;

static void close_file(FILE *f)
{
	if (!f) return;
	FFINALLOCK(f);
	if (f->wpos > f->wbase) f->write(f, 0, 0);
	if (f->rpos < f->rend) f->seek(f, f->rpos-f->rend, SEEK_CUR);
}

void __stdio_exit(void)
{
	FILE *f;
	for (f=*__ofl_lock(); f; f=f->next) close_file(f);
	close_file(__stdin_used);
	close_file(__stdout_used);
}
