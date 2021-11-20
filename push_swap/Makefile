CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = push_swap
INCLUDES = ./include
SRCS = array.c\
		check_input.c\
		cmd_parsing.c\
		command.c\
		five_param.c\
		listcmd.c\
		partition.c\
		ps_atoi.c\
		push_swap.c\
		sort.c\
		stack.c\

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
