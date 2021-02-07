/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_padding.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 20:17:50 by gkim              #+#    #+#             */
/*   Updated: 2021/02/07 23:37:21 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_padding(int n, t_bool zero)
{
	int		cnt;
	char	c;

	cnt = 0;
	c = zero ? '0' : ' ';
	while (cnt < n)
	{
		ft_putchar_fd(c, 1);
		cnt++;
	}
	return (cnt);
}
