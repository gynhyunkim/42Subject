/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 17:34:02 by gkim              #+#    #+#             */
/*   Updated: 2020/12/06 18:47:08 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_file.h"

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_display_file(char *argv)
{
	int 	fd;
	int		i;
	int		len;
	char 	text[400];

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		ft_putstr(NO_READ);
	else
	{
		len = read(fd, text, 400);
		i = 0;
		while (i < len)
		{
			write(1, text + i, 1);
			i++;
		}
		write(1, "\n", 1);
	}
	close(fd);
}
