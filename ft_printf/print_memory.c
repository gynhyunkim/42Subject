/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 20:25:15 by gkim              #+#    #+#             */
/*   Updated: 2021/02/07 20:25:36 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_memory(va_list ap, t_flags *flags)
{
	int			cnt;
	long long	mem;
	char		*hex;

	cnt = 2;
	mem = va_arg(ap, long long);
	hex = ft_tohex(mem, "0123456789abcdef");
	cnt += ft_strlen(hex);
	if (!flags -> minus && !flags -> zero)
		cnt += print_padding(flags -> width - cnt, FALSE);
	ft_putstr_fd("0x", 1);
	if (flags -> zero)
		cnt += print_padding(flags -> width - cnt, TRUE);
	ft_putstr_fd(hex, 1);
	if (flags -> minus)
		cnt += print_padding(flags -> width - cnt, FALSE);
	free(hex);
	return (cnt);
}
