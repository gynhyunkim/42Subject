/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <40_90@naver.com>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 00:39:20 by gkim              #+#    #+#             */
/*   Updated: 2020/11/25 17:39:54 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putchex(unsigned char c, int minsize)
{
	char hex;

	if (c == 0 && minsize <= 0)
		return ;
	else if (c == 0)
		hex = '0';
	else if (c % 16 < 10)
		hex = (char)(c % 16 + 48);
	else
		hex = (char)(c % 16 + 87);
	ft_putchex(c / 16, minsize - 1);
	ft_putchar(hex);
}

int		is_printable(char c)
{
	if (c > 31 && c < 127)
		return (1);
	return (0);
}

void	ft_putstr_non_printable(char *str)
{
	while (*str)
	{
		if (is_printable(*str))
			ft_putchar(*str);
		else
		{
			ft_putchar('\\');
			ft_putchex((unsigned char)*str, 2);
		}
		str++;
	}
	ft_putchar(*str);
}
