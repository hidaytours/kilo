#include "error.h"

void	die(const char *s)
{
	clear_screen();
	perror(s);
	exit(1);
}
