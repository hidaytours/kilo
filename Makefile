CC			=	cc
NAME		=	kilo
INCLUDES	=	-I ./include -I $(DIR_RL)/include
CFLAGS		=	-Wall -Wextra -Werror -pedantic -std=c99 $(INCLUDES)
LFLAGS		=	-lreadline

DIR_SRC		=	./src
SRCS		=	$(DIR_SRC)/main.c	\
				$(DIR_SRC)/terminal.c	\
				$(DIR_SRC)/error.c

OBJS		=	$(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(LFLAGS)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: clean fclean re
