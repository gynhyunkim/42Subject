/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <40_90@naver.com>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 01:34:51 by gkim              #+#    #+#             */
/*   Updated: 2020/11/25 17:45:54 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_able(char *str, unsigned int s)
{
	int	i;

	i = 0;
	while (s < 15)
	{
		ft_putchar(' ');
		s++;
	}
	while (i < 16)
	{
		if (*(str + i) > 31 && *(str + i) < 127)
			ft_putchar(*(str + i));
		else
			ft_putchar('.');
		if (*(str + i) == 0)
			break ;
		i++;
	}
	write(1, "\n", 1);
}

void	ft_puthex(long long n, int size)
{
	char hex;

	if (n == 0 && size == 0)
		return ;
	else if (n == 0)
		hex = '0';
	else if (n % 16 < 10)
		hex = (char)(n % 16 + 48);
	else
		hex = (char)(n % 16 + 87);
	ft_puthex(n / 16, size - 1);
	ft_putchar(hex);
	if (size == 16)
		write(1, ": ", 2);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int		i;
	char				*p;

	p = (char *)addr;
	i = 0;
	while (size > 0)
	{
		if (i == 0)
			ft_puthex((long long)(p + i), 16);
		ft_puthex((long long)*(p + i), 2);
		if (i % 2 == 1)
			ft_putchar(' ');
		if ((i % 15 == 0 && i != 0) || size == 1 || *(p + i) == 0)
		{
			ft_print_able(p, i);
			if (*(p + i) == 0)
				break ;
			p = p + 16;
			i = -1;
		}
		i++;
		size--;
	}
	return (addr);
}
