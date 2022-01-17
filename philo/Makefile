CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = philo
SRCDIR = ./src/
SRC = main.c ft_utils.c init.c error.c\
		philo.c monitoring.c
SRCS = $(addprefix ${SRCDIR}, ${SRC})
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm $(OBJS)

fclean : clean
	rm $(NAME)

re : fclean all

.PHONY : all clean fclean re
