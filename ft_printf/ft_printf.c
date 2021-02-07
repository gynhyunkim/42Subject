/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 16:50:57 by gkim              #+#    #+#             */
/*   Updated: 2021/02/07 19:25:02 by gkim             ###   ########.fr       */
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
	len = flags -> prec > -1 && flags -> prec < (int)ft_strlen(str) ? flags -> prec : (int)ft_strlen(str);
	if (!flags -> minus)
		cnt += print_padding(flags -> width - len, FALSE);
	while (str[i])
	{
		if (i >= flags -> prec)
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

	cnt = 0;
	c = va_arg(ap, int);
	if (flags-> minus)
		ft_putchar_fd(c, 1);
	print_padding(flags -> width - 1, FALSE);
	if (!flags -> minus)
		ft_putchar_fd(c, 1);
	return (cnt);
}

char	*ft_tohex(long long n, char *set)
{
	int		len;
	long long temp;
	char	*hex;

	len = n == 0 ? 1 : 0;
	temp = n;
	while (temp)
	{
		temp = temp / 16;
		len++;
	}
	hex = (char *)malloc(len + 1);
	hex[len--] = '\0';
	if (n == 0)
		hex[len] = '0';
	while (n)
	{
		hex[len--] = set[n % 16];
		n = n / 16;
	}
	return (hex);
}

char	*ft_u_tohex(unsigned int n, char *set)
{
	int				len;
	unsigned int	temp;
	char			*hex;

	len = n == 0 ? 1 : 0;
	temp = n;
	while (temp)
	{
		temp = temp / 16;
		len++;
	}
	hex = (char *)malloc(len + 1);
	hex[len--] = '\0';
	if (n == 0)
		hex[len] = '0';
	while (n)
	{
		hex[len--] = set[n % 16];
		n = n / 16;
	}
	return (hex);
}

int		print_num(va_list ap, t_flags *flags)
{
	int		cnt;
	int		len;
	char	*num;

	cnt = 0;
	if (flags -> type == 'd' || flags -> type == 'i')
		num = ft_itoa(va_arg(ap, int));
	else if (flags -> type == 'u')
		num = ft_u_itoa(va_arg(ap, unsigned int));
	else if (flags -> type == 'x')
		num = ft_u_tohex(va_arg(ap, unsigned int), "0123456789abcde");
	else if (flags -> type == 'X')
		num = ft_u_tohex(va_arg(ap, unsigned int), "0123456789ABCDE");
	len = flags -> prec <= (int)ft_strlen(num) ? (int)ft_strlen(num) : flags -> prec;
	if (!flags -> minus)
		cnt += print_padding(flags -> width - len, flags -> zero);
	cnt += print_padding(len - ft_strlen(num), TRUE);
	ft_putstr_fd(num, 1);
	cnt += ft_strlen(num);
	if (flags -> minus)
		cnt += print_padding(flags -> width - len, flags -> zero);
	free(num);
	return (cnt);
}

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
		return (print_memory(ap, flags));
	return (0);
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
