#ifndef MAIN_H
# define MAIN_H

# include <unistd.h>
# include <ctype.h>
# include <errno.h>
# include <stdio.h>
# include <stdbool.h>

# include "utils.h"
# include "error.h"
# include "terminal.h"

# define CTRL_KEY(k) ((k) & 0x1f)

#endif
