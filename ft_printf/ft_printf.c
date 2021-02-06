/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 16:50:57 by gkim              #+#    #+#             */
/*   Updated: 2021/02/06 19:41:38 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	print_padding(int n, t_bool zero)
{
	char	c;

	c = zero ? '0' : ' ';
	while (n-- > 0)
		ft_putchar_fd(c, 1);
}

int		print_string(va_list ap, t_flags *check_f)
{
	char	*str;
	char	*tmp;
	int		padding;
	int		len;

	tmp = NULL;
	str = va_arg(ap, char *);
	len = (check_f -> prec < ft_strlen(str) && check_f -> prec > -1) ? check_f -> prec : ft_strlen(str) + 1;
	if (check_f -> prec < ft_strlen(str))
	{
		if (!(tmp = ft_substr(str, 0, check_f -> prec)))
			return (0);
		str = tmp;
	}
	if (check_f -> minus == TRUE)
		ft_putstr_fd(str, 1);
	padding = (check_f -> width) - ft_strlen(str);
	len += padding > 0 ? padding : 0;
	print_padding(padding, FALSE);
	if (check_f -> minus == FALSE)
		ft_putstr_fd(str, 1);
	free(tmp);
	return (len);
}

int		print_char(va_list ap, t_flags *check_f)
{
	int		c;
	int		cnt;
	int		padding;

	c = va_arg(ap, int);
	cnt = check_f -> width > 1 ? check_f -> width : 1;
	if (check_f -> minus == TRUE)
		ft_putchar_fd(c, 1);
	if ((padding = check_f -> width) > 1)
	{
		while (--padding)
			write(1, " ", 1);
	}
	if (check_f -> minus == FALSE)
		ft_putchar_fd(c, 1);
	return (cnt);
}

int		print_num(va_list ap, t_flags *check_f)
{
	int		cnt;
	int		len;
	int		padding;
	char	*num;
	char	fillc;

	num = ft_itoa(va_arg(ap, int));
	len = ft_strlen(num);
	cnt = len;
	fillc = ' ';
	if (check_f -> width < len && check_f -> prec < len)
		ft_putstr_fd(num, 1);
	else if (check_f -> width > len && check_f -> prec > len)
	{
		padding = check_f -> width - check_f -> prec;
		while (padding-- > 0)
			write(1, " ", 1);
		padding = check_f -> prec - len;
		while (padding -- > 0)
			write(1, "0", 1);
		ft_putstr_fd(num, 1);
		
	}
	else if ((padding = check_f -> width - len) > 0)
	{
		if (!(check_f -> minus) && check_f -> zero)
			fillc = '0';
		if (check_f -> minus)
			ft_putstr_fd(num, 1);
		while (padding -- > 0)
			write(1, &fillc, 1);
		if (!(check_f -> minus))
			ft_putstr_fd(num, 1);
		len = check_f -> width;
	}
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
	va_start(ap, format); //가변인자의 주소를 알기 위해 고정매개변수를 인자로 사용
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
//		write(1, "\n", 1);
		format++;
	}
	va_end(ap);
	free(flags);
	return (0);
}
