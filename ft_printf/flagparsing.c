/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flagparsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 17:16:13 by gkim              #+#    #+#             */
/*   Updated: 2021/02/07 19:25:01 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	init_flags(t_flags **flags)
{
	(*flags) -> zero = FALSE;
	(*flags) -> minus = FALSE;
	(*flags) -> width = 0;
	(*flags) -> prec = -1;
}

void	set_prec(const char **format, t_flags *flg)
{
	(*format)++;
	flg -> prec = 0;
	while (ft_isdigit(**format))
	{
		flg -> prec = (flg -> prec * 10) + (**format - '0');
		(*format)++;
	}
	(*format)--;
}

void	set_width(const char **format, va_list ap, t_flags *flg)
{
	flg -> width = 0;
	if (**format == '*')
	{
		flg -> width = va_arg(ap, int);
	}
	else
	{
		while (ft_isdigit(**format))
		{
			flg -> width = (flg -> width * 10) + (**format - '0');
			(*format)++;
		}
		(*format)--;
	}
	
}


void	parse_flags(const char **format, va_list ap, t_flags **flg)
{
	init_flags(flg);
	while (!ft_isalpha(**format))
	{
		if (**format == '-')
			(*flg) -> minus = TRUE;
		else if (**format == '0' && !(*flg) -> minus)
			(*flg) -> zero = TRUE;
		else if (**format == '.')
			set_prec(format, *flg);
		else if ((**format != '0' && ft_isdigit(**format)) || **format == '*')
			set_width(format, ap, *flg);
		(*format)++;
	}
	(*flg) -> type = **format;
	if ((*flg) -> type != 'd' && (*flg) -> minus && (*flg) -> zero)
		(*flg) -> zero = FALSE;
}

