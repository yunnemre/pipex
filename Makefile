CC= cc
CFLAGS= -Wall -Wextra -Werror
RM= rm -rf
SRCS=

OBJS=$(SRCS:.c=.o)

NAME=pipex.a

all=$(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)
fclean:clean
	$(RM) $(NAME)
re:fclean all

.PHONY: all clean fclean re
