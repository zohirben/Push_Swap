NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = push_swap.c instructions.c errors.c help_tools.c \

RM = rm -f
LIBFT = libft/libft.a

all: $(NAME)

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS) $(LIBFT)
	@$(CC) $(LIBFT) $^ -o $@

$(LIBFT):
	@make -C libft
	@make -C libft bonus

clean:
	$(RM) $(OBJS)
	make -C libft clean

fclean: clean
	make -C libft fclean
	$(RM) $(NAME)

re: fclean all