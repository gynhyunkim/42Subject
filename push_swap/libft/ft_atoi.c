/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 14:39:22 by gkim              #+#    #+#             */
/*   Updated: 2021/11/21 00:15:32 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	jump_space(const char *str, int *idx)
{
	while (str[*idx] == '\n' || str[*idx] == '\t' || str[*idx] == '\v'
		|| str[*idx] == '\r' || str[*idx] == '\f' || str[*idx] == ' ')
		(*idx)++;
}

static void	chk_mark(const char c, int *mark, int *idx)
{
	if (c == '-')
	{
		*mark = -1;
		(*idx)++;
	}
	else if (c == '+')
		(*idx)++;
}

int	ft_atoi(const char *nptr)
{
	int	mark;
	int	num;
	int	i;

	i = 0;
	mark = 1;
	num = 0;
	jump_space(nptr, &i);
	chk_mark(nptr[i], &mark, &i);
	while (ft_isdigit(nptr[i]))
	{
		num = num * 10 + (nptr[i] - '0') * mark;
		i++;
	}
	return (num);
}
