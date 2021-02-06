/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 16:50:57 by gkim              #+#    #+#             */
/*   Updated: 2021/02/07 00:07:11 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

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

int		print_string(va_list ap, t_flags *flags)
{
	char	*str;
	int		cnt;
	int		i;
	int		len;

	cnt = 0;
	i = 0;
	str = va_arg(ap, char *);
	len = flags -> prec > -1 && flags -> prec < ft_strlen(str) ? flags -> prec : ft_strlen(str);
	if (!flags -> minus)
		cnt += print_padding(flags -> width - len, FALSE);
	while (str[i])
	{
		if (flags -> prec > -1 && i >= flags -> prec)
			break;
		ft_putchar_fd(str[i], 1);
		cnt++;
		i++;
	}
	if (flags -> minus)
		cnt += print_padding(flags -> width - len, FALSE);
	return (cnt);
}

int		print_char(va_list ap, t_flags *flags)
{
	int		c;
	int		cnt;
	int		padding;

	c = va_arg(ap, int);
	if (flags-> minus)
		ft_putchar_fd(c, 1);
	print_padding(flags -> width - 1, FALSE);
	if (!flags -> minus)
		ft_putchar_fd(c, 1);
	return (cnt);
}

int		print_num(va_list ap, t_flags *flags)
{
	int		cnt;
	int		len;
	char	*num;

	cnt = 0;
	num = ft_itoa(va_arg(ap, int));
	len = flags -> prec <= ft_strlen(num) ? ft_strlen(num) : flags -> prec;
	if (!flags -> minus)
		cnt += print_padding(flags -> width - len, FALSE);
	cnt += print_padding(len - ft_strlen(num), TRUE);
	ft_putstr_fd(num, 1);
	cnt += ft_strlen(num);
	if (flags -> minus)
		cnt += print_padding(flags -> width - len, FALSE);
	return (cnt);
}


int		print(va_list ap, t_flags *flags)
{
	int type;

	type = flags -> type;
	if (type == 'c')
		return (print_char(ap, flags));
	else if (type == 's')
		return (print_string(ap, flags));
	else if (type == 'd' || type == 'i')
		return (print_num(ap, flags));	
}

int		ft_printf(const char *format, ...) //%와 flags체크 후 포맷에 따라 함수 호출
{
	va_list ap;
	char 	test;
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
			flags -> type = *format;
			cnt += print(ap, flags);
		}
		else
			write(1, format, 1);
		format++;
	}
	va_end(ap);
	free(flags);
	return (cnt);
}
