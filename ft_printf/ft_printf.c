/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 22:38:06 by gkim              #+#    #+#             */
/*   Updated: 2021/02/11 18:18:32 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_type(va_list ap, t_flags *flags)
{
	int type;

	type = flags->type;
	if (type == 'c')
		return (print_char(ap, flags));
	else if (type == 's')
		return (print_string(ap, flags));
	else if (type == 'd' || type == 'i' || type == 'u'
			|| type == 'x' || type == 'X')
		return (print_num(ap, flags));
	else if (type == 'p')
		return (print_memaddress(ap, flags));
	else if (type == '%')
		return (print_char(ap, flags));
	return (-1);
}

static int	print_format(const char *format, va_list ap, t_flags *flags)
{
	int	cnt;
	int	check_return;

	cnt = 0;
	while (*format)
	{
		if (*format == '%')
		{
			++format;
			parse_flags(&format, ap, &flags);
			if ((check_return = print_type(ap, flags)) == -1)
				return (-1);
			cnt += check_return;
		}
		else
		{
			ft_putchar_fd(*format, 1);
			cnt++;
		}
		format++;
	}
	return (cnt);
}

int			ft_printf(const char *format, ...)
{
	va_list ap;
	t_flags *flags;
	int		cnt;

	va_start(ap, format);
	flags = (t_flags *)malloc(sizeof(t_flags));
	cnt = print_format(format, ap, flags);
	free(flags);
	va_end(ap);
	return (cnt);
}
