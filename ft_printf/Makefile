CC = gcc
CFLAGS = -Wall -Werror -Wextra
AFLAGS = rcs
NAME = libftprintf.a
SRCS =	ft_printf.c\
		ft_ulltoa_base.c\
		parse_flags.c\
		print_char.c\
		print_memaddress.c\
		print_num.c\
		print_padding.c\
		print_string.c\

OBJS = $(SRCS:.c=.o)

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

.PHONY : all clean fclean re

