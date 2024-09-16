#ifndef TERMINAL_H
# define TERMINAL_H

# include <unistd.h>
# include <termios.h>
# include <stdlib.h>

# include "error.h"

typedef struct termios t_termios;

void enableRawMode(void);
void disableRawMode(void);

#endif
