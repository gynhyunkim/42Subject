CC = gcc
CFLAGS = -Wall -Wextra -Werror
AFLAGS = rc
NAME = libft.a
SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:.c=.o)

$(NAME) : $(OBJECTS)
	ar $(AFLAGS) $@ $^

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean :
	rm -f $(OBJECTS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
