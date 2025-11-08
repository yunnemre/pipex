CC        = cc
CFLAGS    = -Wall -Wextra -Werror -Iincludes -Ilibft
RM        = rm -rf

NAME      = pipex

LIBFT_DIR = libft
LIBFT_A   = $(LIBFT_DIR)/libft.a


SRC_DIR   = srcs
OBJ_DIR   = obj

SRCS      = $(SRC_DIR)/main.c \
			$(SRC_DIR)/arg_man.c \
			$(SRC_DIR)/error_man.c \

OBJS      = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(LIBFT_A) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) -o $(NAME)

$(LIBFT_A):
	@$(MAKE) -C $(LIBFT_DIR)


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c includes/pipex.h | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@$(RM) $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus