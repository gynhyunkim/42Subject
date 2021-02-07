/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 20:21:49 by gkim              #+#    #+#             */
/*   Updated: 2021/02/07 23:36:45 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*get_arg(va_list ap, t_flags *flags)
{
	if (flags -> type == 'd' || flags -> type == 'i')
		return (ft_itoa(va_arg(ap, int)));
	else if (flags -> type == 'u')
		return (ft_u_itoa(va_arg(ap, unsigned int)));
	else if (flags -> type == 'x')
	{
		return (ft_tohex(va_arg(ap, unsigned int), "0123456789abcdef"));
	}
	else if (flags -> type == 'X')
		return (ft_tohex(va_arg(ap, unsigned int), "0123456789ABCDEF"));
	return (NULL);
}

int			print_negative(char *num, t_flags *flags)
{
	int	len;
	int cnt;

	cnt = 1;
	len = flags -> prec <= (int)ft_strlen(num) ? (int)ft_strlen(num)  : flags -> prec;
	ft_putchar_fd(*num, 1);
	num++;
	if (!flags -> minus)
		cnt += print_padding(flags -> width - len, flags -> zero);
	cnt += print_padding(len - ft_strlen(num) - 1, TRUE);
	ft_putstr_fd(num, 1);
	if (flags -> minus)
		cnt += print_padding(flags -> width - len, FALSE);
	return (cnt);
}

int			print_num(va_list ap, t_flags *flags)
{
	int		cnt;
	int		len;
	char	*num;

	cnt = 0;
	num = get_arg(ap, flags);
	if (*num == '-')
		return (print_negative(num, flags));
	len = flags -> prec <= (int)ft_strlen(num) ? (int)ft_strlen(num) : flags -> prec;
	if (flags -> prec == 0 && *num == '0')
		len = 0;
	if (!flags -> minus)
		cnt += print_padding(flags -> width - len, flags -> zero);
	cnt += print_padding(len - ft_strlen(num), TRUE);
	if (!(*num == '0' && flags -> prec == 0))
	{
		ft_putstr_fd(num, 1);
		cnt += ft_strlen(num);
	}
	if (flags -> minus)
		cnt += print_padding(flags -> width - len, FALSE);
	free(num);
	return (cnt);
}