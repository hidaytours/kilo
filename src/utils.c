#include "utils.h"

void clear_screen()
{
    write(STDOUT_FILENO, "\x1b[2J", 4); //clear the entire screen
	write(STDOUT_FILENO, "\x1b[H", 3); //position the cursor
}