/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 20:20:35 by gkim              #+#    #+#             */
/*   Updated: 2021/02/10 15:18:28 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_char(va_list ap, t_flags *flags)
{
	int		c;
	int		cnt;

	cnt = 1;
	c = va_arg(ap, int);
	if (flags-> minus)
		ft_putchar_fd(c, 1);
	cnt += print_padding(flags -> width - 1, FALSE);
	if (!flags -> minus)
		ft_putchar_fd(c, 1);
	return (cnt);
}
