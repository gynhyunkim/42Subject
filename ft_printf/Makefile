CC = gcc
CFLAGS = -Wall -Werror -Wextra
AFLAGS = rcs
NAME = libftprintf.a
SRCS =	flagparsing.c \
		ft_printf.c \
OBJS = %(SRCS:.c=.o)

$(NAME) : $(OBJS)
	$(MAKE) all -C ./libft
	cp libft/libft.a $(NAME)
	$(AR) $(AFLAGS) $@ $^

all : $(NAME)

clean :
	$(MAKE) clean -C ./libft
	rm -rf $(OBJS)

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean 
	

