/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 17:45:13 by gkim              #+#    #+#             */
/*   Updated: 2021/10/02 02:57:40 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signal(int pid, char *bit, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		kill(pid, SIGUSR1 + bit[i]);
		usleep(100);
		i++;
	}	
}

void	convert_to_bit(int c, char *c_bit, int len)
{
	int i;

	i = len - 1;
	while (i >= 0)
	{
		c_bit[len - i - 1] = (c >> i) & 1;
		i--;
	}
}

void	sig_handler2(int signo)
{
	if (signo == SIGUSR1)
		write(1, "Success to sending a message!\n", 31);
	exit(0);
}

void	sig_handler1(int signo)
{
	if (signo == SIGUSR1)
		write(1, "Success to seding a length!\n", 29);
}

int		ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	main(int argc, char *argv[])
{
	int		pid;
	char	*str;
	char	bit[32];

	if (argc != 3)
		write(2, "ERROR!\n", 6);
	else
	{
		pid = ft_atoi(argv[1]);
		str = argv[2];
		signal(SIGUSR1, sig_handler1);
		convert_to_bit(ft_strlen(str), bit, 32);
		send_signal(pid, bit, 32);
		pause();
		signal(SIGUSR1, sig_handler2);
		while (*str)
		{
			convert_to_bit(*str, bit, 8);
			send_signal(pid, bit, 8);
			str++;
		}
	}
}
