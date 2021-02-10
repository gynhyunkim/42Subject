/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 20:20:35 by gkim              #+#    #+#             */
/*   Updated: 2021/02/10 20:29:46 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_char(va_list ap, t_flags *flags)
{
	int		c;
	int		cnt;

	cnt = 1;
	if (flags -> type == 'c')
		c = va_arg(ap, int);
	else
		c = '%';
	if (!flags-> minus)
		cnt += print_padding(flags -> width - 1, flags -> zero);
	ft_putchar_fd(c, 1);
	if (flags -> minus)
		cnt += print_padding(flags -> width - 1, FALSE);
	return (cnt);
}
