#include "main.h"

int	main(void)
{
	char	c;

	enableRawMode();
	while (true)
	{
		c = '\0';
		if (read(STDIN_FILENO, &c, 1) == -1 && errno != EAGAIN)
			die("read");
		if (iscntrl(c))
			printf("%d\r\n", c);
		else
			printf("%d ('%c')\r\n", c, c);
		if (c == 'q')
			break;
	}
	return (0);
}
