/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 20:21:49 by gkim              #+#    #+#             */
/*   Updated: 2021/02/10 14:00:15 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*get_arg(va_list ap, t_flags *flags)
{
	if (flags -> type == 'd' || flags -> type == 'i')
		return (ft_itoa(va_arg(ap, int)));
	else if (flags -> type == 'u')
		return (ft_uitoa_base(va_arg(ap, unsigned int), "0123456789"));
	else if (flags -> type == 'x')
	{
		return (ft_uitoa_base(va_arg(ap, unsigned int), "0123456789abcdef"));
	}
	else if (flags -> type == 'X')
		return (ft_uitoa_base(va_arg(ap, unsigned int), "0123456789ABCDEF"));
	return (NULL);
}

int			print_positive(char *num, t_flags *flags)
{
	int len;
	int cnt;

	cnt = ft_strlen(num);
	len = cnt < flags -> prec ? flags -> prec : cnt;
	if (!flags -> minus)
		cnt += print_padding(flags -> width - len, flags -> zero);
	cnt += print_padding(flags -> prec - ft_strlen(num), TRUE);
	ft_putstr_fd(num, 1);
	if (flags -> minus)
		cnt += print_padding(flags -> width - len, FALSE);
	return (cnt);
}

int			print_negative(char *num, t_flags *flags)
{
	int	len;
	int	cnt;

	cnt = ft_strlen(num);
	len = flags -> prec > cnt ? flags -> prec : cnt;
	if (!flags -> minus && !flags -> zero)
		cnt += print_padding(flags -> width - len, FALSE);
	ft_putchar_fd(*num, 1);
	num++;
	if (!flags -> minus && flags -> zero)
		cnt += print_padding(flags -> width - len, TRUE);
	cnt += print_padding(flags -> prec - ft_strlen(num), TRUE);
	ft_putstr_fd(num, 1);
	if (flags -> minus)
		cnt += print_padding(flags -> width - cnt, FALSE);
	return (cnt);
}

int			print_num(va_list ap, t_flags *flags)
{
	char	*num;

	num = get_arg(ap, flags);
	if (flags -> prec == 0 && *num == '0')
		return (0);
	if (*num == '-')
		return (print_negative(num, flags));
	else
		return (print_positive(num, flags));
	free(num);
	return (0);
}