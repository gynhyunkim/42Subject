CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = push_swap
INCLUDES = ./include
SRCS = command.c\
		sort.c\
		listcmd.c\
		push_swap.c\
		stack.c\
		check_input.c\
		array.c\

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS) 
	$(MAKE) all -C ./libft
	$(CC) $^ -o $@ -lft -L./libft -IINCLUDES

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
