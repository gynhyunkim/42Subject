#ifndef SERVER_H
# define SERVER_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

typedef struct s_msg
{
	struct sigaction	sa[2];
	char				buf;
	char				*msg_buf;
	int					msg_len;
	int					msg_idx;
	int					bit_cnt;
	int					cur_pid;
}	t_msg;

void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *str, int fd);
void	print_msg(int pid, char *str);

#endif
