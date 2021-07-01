CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = push_swap
SRCS = command.c\
		command2.c\
		listcmd.c\
		push_swap.c\
		stack.c\

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	$(MAKE) all -C ./libft
	$(CC) $^ -o $@ -lft -L./libft -I./

$(OBJS) : $(SRCS)
	$(CC) -c $^

all : $(NAME)

clean :
	$(MAKE) clean -C ./libft
	rm -rf $(OBJS)

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re : fclean all
