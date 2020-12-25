CC = gcc
CFLAGS = -Wall -Wextra -Werror
AFLAGS = rsc
NAME = libft.a
SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:.c=.o)

$(NAME) : $(OBJECTS)
	ar $(AFLAGS) $@ $^

all : $(NAME)

so:
	$(CC) -fPIC $(CFLAGS) $(SOURCES)
	gcc -shared -o libft.so $(OBJECTS)

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@


clean :
	rm -f $(OBJECTS)

fclean : clean
	rm -f $(NAME)

re : fclean all



.PHONY : all clean fclean re
