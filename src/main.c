#include "main.h"

static char	editor_read_key()
{
	int		nread;
	char	c;

	while (true)
	{
		nread = read(STDIN_FILENO, &c, sizeof(c));
		if (nread == 1)
			break ;
		if (nread == -1 && errno != EAGAIN)
			die("read");
	}
	return (c);
}

static void	editor_process_keypress()
{
	char	c;

	c = editor_read_key();
	if (c == CTRL_KEY('q'))
	{
		clear_screen();
		exit(0);
	}
}

static void	editor_refresh_screen()
{
	clear_screen();
}

int	main(void)
{
	enable_raw_mode();
	while (true)
	{
		editor_refresh_screen();
		editor_process_keypress();
	}
	return (0);
}
