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
LIBFT_DIR = libft/

all : $(NAME)

$(NAME) : $(OBJS) 
	$(MAKE) all -C ./libft
	$(CC) $(CFLAGS) $^ -o $@ -lft -L$(LIBFT_DIR) -I$(INCLUDES)

%.o : %.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(MAKE) clean -C ./libft
	rm -rf $(OBJS)

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re : fclean all
