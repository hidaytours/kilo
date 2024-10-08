#include "terminal.h"

static t_termios	g_original;

void	enable_raw_mode(void)
{
	t_termios	raw;

	if (tcgetattr(STDIN_FILENO, &g_original) == -1)
		die("tcgetattr");
	atexit(disable_raw_mode);
	raw = g_original;
	raw.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
	raw.c_oflag &= ~(OPOST);
	raw.c_cflag |= (CS8);
	raw.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
	raw.c_cc[VMIN] = 0;
	raw.c_cc[VTIME] = 1;
	if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw) == -1)
		die("tcsetattr");
}

void disable_raw_mode(void)	{
	if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &g_original) == -1)
		die("tcsetattr");
}
