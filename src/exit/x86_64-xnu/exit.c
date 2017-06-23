#include <stdlib.h>
#include <stdint.h>
#include "libc.h"

extern void __stdio_exit(void);

_Noreturn void exit(int code)
{
	__stdio_exit();
	_Exit(code);
}
