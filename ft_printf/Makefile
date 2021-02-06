CC = gcc
CFLAGS = -Wall -Werror -Wextra
AFLAGS = rcs
NAME = libftprintf.a
SRCS =	flagparsing.c \
		ft_printf.c \

OBJS = $(SRCS:.c=.o)


$(NAME) : $(OBJS)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	$(AR) $(AFLAGS) $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@

all : $(NAME)

clean :
	$(MAKE) clean -C ./libft
	rm -rf $(OBJS)

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean 
	

