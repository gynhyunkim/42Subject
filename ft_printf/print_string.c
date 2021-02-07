/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 20:13:47 by gkim              #+#    #+#             */
/*   Updated: 2021/02/07 20:19:24 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_string(va_list ap, t_flags *flags)
{
	char	*str;
	int		cnt;
	int		i;
	int		len;

	cnt = 0;
	i = 0;
	str = va_arg(ap, char *);
	len = flags -> prec > -1 && flags -> prec < (int)ft_strlen(str) ? flags -> prec : (int)ft_strlen(str);
	if (!flags -> minus)
		cnt += print_padding(flags -> width - len, FALSE);
	while (str[i] && len--)
	{
		ft_putchar_fd(str[i], 1);
		cnt++;
		i++;
	}
	if (flags -> minus)
		cnt += print_padding(flags -> width - len, FALSE);
	return (cnt);
}