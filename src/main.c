#include "main.h"

static char	char_read_key()
{
	int		nread;
	char	c;

	while (true)
	{
		nread = read(STDIN_FILENO, &c, 1);
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

	c = char_read_key();
	if (c == CTRL_KEY('q'))
		exit(0);
}

int	main(void)
{
	enable_raw_mode();
	while (true)
		editor_process_keypress();
	return (0);
}
