NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = push_swap.c \
instructions.c \
instructions2.c \
errors.c \
errors2.c \
help_tools.c \
help_tools2.c \
help_tools3.c \
libft_tools.c \
libft_tools2.c \

RM = rm -f

all: $(NAME)

CLR_RMV:= \033[0m
RED:= \033[1;31m
GREEN:= \033[1;32m
YELLOW:= \033[1;33m
BLUE:= \033[1;34m
CYAN:= \033[1;36m

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	@$(CC) $^ -o $@
	@echo "$(GREEN)Compiled successfully! ✔️$(CLR_RMV)"

clean:
	@$(RM) $(OBJS)
	@echo "$(YELLOW)Object files removed. ✔️$(CLR_RMV)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)Binary file removed. ✔️$(CLR_RMV)"

re: fclean all
	@echo "$(BLUE)Recompiling...$(CLR_RMV)"