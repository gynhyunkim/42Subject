/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 12:37:36 by gkim              #+#    #+#             */
/*   Updated: 2021/11/20 23:49:11 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

long long	ps_atoi(const char *s, char *err_flag)
{
	long long	num;
	int			mark;
	int			i;
	int			len;

	num = 0;
	i = 0;
	mark = 1;
	if (s[i] == '-')
	{
		mark *= -1;
		i++;
	}
	while (ft_isdigit(s[i]))
	{
		num *= 10;
		num += s[i++] - '0';
	}
	num *= mark;
	if (s[i] || num < INT32_MIN || num > INT32_MAX)
	{
		*err_flag = 1;
		return (0);
	}
	return (num);
}
