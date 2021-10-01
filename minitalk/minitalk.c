/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 17:45:13 by gkim              #+#    #+#             */
/*   Updated: 2021/09/25 16:24:33 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signal(int pid, char *bit)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		kill(pid, SIGUSR1 + bit[i]);
		usleep(100);
		i++;
	}	
}

void	char_to_bit(char c, char *c_bit)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		c_bit[7 - i] = (c >> i) & 1;
		i--;
	}
}

int	main(int argc, char *argv[])
{
	int		pid;
	char	*str;
	char	bit[8];

	if (argc != 3)
		write(2, "ARGUMENT ERROR!\n", 7);
	pid = ft_atoi(argv[1]);
	str = argv[2];
	while (*str)
	{
		char_to_bit(*str, bit);
		send_signal(pid, bit);
		str++;
	}
	char_to_bit(*str, bit);
	send_signal(pid, bit);
}
