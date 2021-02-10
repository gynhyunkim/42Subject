/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 20:13:47 by gkim              #+#    #+#             */
/*   Updated: 2021/02/10 14:28:53 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_string(va_list ap, t_flags *flags)
{
	char	*str;
	int		cnt;
	int		i;
	int		len;

	i = 0;
	str = va_arg(ap, char *);
	cnt = ft_strlen(str);
	len = flags -> prec > -1 && flags -> prec < cnt ? flags -> prec : cnt;
	cnt = len;
	if (!flags -> minus)
		cnt += print_padding(flags -> width - len, FALSE);
	while (str[i] && i < len)
	{
		ft_putchar_fd(str[i], 1);
		i++;
	}
	if (flags -> minus)
		cnt += print_padding(flags -> width - cnt, FALSE);
	return (cnt);
}