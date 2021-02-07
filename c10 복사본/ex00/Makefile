CC = gcc
CFLAGS = -Wall -Wextra -Werror
TARGET = ft_display_file
OBJS = main.o ft_display_file.o
H = ft_file.h

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

%.o : %.c $(H)
	$(CC) $(CFLAGS) -c $<

clean : 
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

