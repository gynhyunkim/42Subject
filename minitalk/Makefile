CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = server
NAME2 = client
S_SRCS = server.c \
		list.c \
		ft_put.c
S_OBJS = server.o \
		list.o \
		ft_put.o
C_SRCS = minitalk.c \
		utils.c
C_OBJS = minitalk.o \
		utils.o

all : $(NAME) $(NAME2)

$(NAME) : $(S_OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(S_OBJS) : $(S_SRCS)
	$(CC) -c $^

$(NAME2) : $(C_OBJS)
	$(CC) $(CFLAGS) $^ -o $@  

$(C_OBJS) : $(C_SRCS)
	$(CC) -c $^

clean : 
	rm -rf $(S_OBJS) $(C_OBJS)

fclean :
	rm -rf $(NAME) $(NAME2)

re : fclean all
