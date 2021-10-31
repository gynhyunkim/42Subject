/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 17:45:13 by gkim              #+#    #+#             */
/*   Updated: 2021/08/17 17:13:31 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	convert(char c, char *b)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		b[7 - i] = (c >> i) & 1;
		i--;
	}
}

int	main(int argc, char *argv[])
{
	int		pid;
	int		cnt;
	char	c[8];
	char	*str;

	if (argc != 3)
		write(0, "ERROR!\n", 7);
	pid = ft_atoi(argv[1]);
	cnt = 0;
	str = argv[2];
	while (*str)
	
	{
		convert(*str, c);
		for (int i = 0; i < 8; i++) {
				kill(pid, SIGUSR1 + c[i]);
				usleep(100);
		}
		str++;
	}
	for (int i = 0; i < 8; i++) {
		kill(pid, SIGUSR1);
		usleep(100);
	}
}