/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 17:45:13 by gkim              #+#    #+#             */
/*   Updated: 2021/10/04 23:14:50 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_signal(int pid, char *bit, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		usleep(50);
		kill(pid, SIGUSR1 + bit[i]);
		i++;
	}
}

static void	convert_to_bit(int c, char *c_bit, int len)
{
	int	i;

	i = len - 1;
	while (i >= 0)
	{
		c_bit[len - i - 1] = (c >> i) & 1;
		i--;
	}
}

static void	sig_handler(int signo)
{
	if (signo == SIGUSR2)
	{
		write(2, "client : error!\n", 17);
		exit(0);
	}
}

int			main(int argc, char *argv[])
{
	int		pid;
	char	*str;
	char	bit[32];

	if (argc != 3)
		write(2, "arguments error!\n", 17);
	else
	{
		if (signal(SIGUSR1, sig_handler)
			|| signal(SIGUSR2, sig_handler))
			write(2, "signal error!\n", 14);
		pid = ft_atoi(argv[1]);
		str = argv[2];
		convert_to_bit(ft_strlen(str), bit, 32);
		send_signal(pid, bit, 32);
		while (*str)
		{
			convert_to_bit(*str, bit, 8);
			send_signal(pid, bit, 8);
			str++;
		}
	}
}
