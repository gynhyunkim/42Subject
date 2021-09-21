#ifndef SERVER_H
# define SERVER_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

typedef struct	s_list
{
	struct s_list	*next;
	char	content;
}	t_list;

typedef struct	s_msg
{
	t_list	*msg_list;
	int	bit_cnt;
	char	buf;
}	t_msg;

void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *str, int fd);
t_list	*ft_lstnew(char content);
t_list	*ft_lstlast(t_list *lst);

# endif