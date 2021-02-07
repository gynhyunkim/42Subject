/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <40_90@naver.com>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 02:10:32 by gkim              #+#    #+#             */
/*   Updated: 2020/11/20 02:48:59 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd>
#include <stdio.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_while(char n)
{
	while (n < 58)
	{
		ft_putchar(n);
		n = n + 1;
	}
}

void ft_print_combn(int n)
{
	char n[9];
	int cnt;

	n[0] = 48;
	while (n[0] != 10-n)
	{
		cnt = 0;
		while(cnt < n)
		{
			ft_while(n[cnt]cnt < n)
			{
			}
		}
	}
}
