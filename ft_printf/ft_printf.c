/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 16:50:57 by gkim              #+#    #+#             */
/*   Updated: 2021/02/10 13:38:07 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print(va_list ap, t_flags *flags)
{
	int type;

	type = flags -> type;
	if (type == 'c')
		return (print_char(ap, flags));
	else if (type == 's')
		return (print_string(ap, flags));
	else if (type == 'd' || type == 'i' || type == 'u' || type == 'x' || type == 'X')
		return (print_num(ap, flags));
	else if (type == 'p')
		return (print_memaddress(ap, flags));
	return (-1);
}

int		ft_printf(const char *format, ...) //%와 flags체크 후 포맷에 따라 함수 호출
{
	va_list ap;
	t_flags	*flags;
	int		cnt;

	cnt = 0;
	flags = (t_flags *)malloc(sizeof(t_flags));
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			++format;
			parse_flags(&format, ap, &flags);
			cnt += print(ap, flags);
		}
		else
		{
			write(1, format, 1);
			cnt++;
		}
		format++;
	}
	va_end(ap);
	free(flags);
	return (cnt);
}
