CC        = cc
CFLAGS    = -g -Wall -Wextra -Werror -Iincludes -Ilibft
RM        = rm -rf

NAME      = pipex

LIBFT_DIR = libft
LIBFT_A   = $(LIBFT_DIR)/libft.a
SRC_DIR   = srcs
BONUS_DIR = bonus
OBJ_DIR   = obj


SRCS = $(SRC_DIR)/main.c \
       $(SRC_DIR)/arg_man.c \
       $(SRC_DIR)/error_man.c \
       $(SRC_DIR)/pipex.c

BONUS_SRCS = $(BONUS_DIR)/main_bonus.c \
             $(BONUS_DIR)/arg_man_bonus.c \
             $(BONUS_DIR)/error_man_bonus.c \
             $(BONUS_DIR)/pipex_bonus.c \
			 $(BONUS_DIR)/here_doc_bonus.c \


OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
BONUS_OBJS = $(BONUS_SRCS:$(BONUS_DIR)/%.c=$(OBJ_DIR)/%.o)


all: $(NAME)


$(NAME): $(LIBFT_A) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) -o $(NAME)



bonus: $(LIBFT_A) $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT_A) -o $(NAME)_bonus


$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c includes/pipex.h | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(BONUS_DIR)/%.c includes/pipex_bonus.h | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@


$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)


clean:
	$(RM) $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean


fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean


re: fclean all

.PHONY: all clean fclean re bonus
