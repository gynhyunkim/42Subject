/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 14:31:17 by gkim              #+#    #+#             */
/*   Updated: 2021/07/08 17:28:40 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	chk_digit(int n)
{
	size_t	digit;

	digit = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		digit++;
	while (n)
	{
		n = n / 10;
		digit++;
	}
	return (digit);
}

static char	*ft_convert(unsigned int n, char *num)
{
	int	i;

	i = (int)ft_strlen(num) - 1;
	if (!n)
		num[i] = '0';
	while (n)
	{
		num[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	return (num);
}

char	*ft_itoa(int n)
{
	unsigned int	num;
	char			*result;
	size_t			digit;

	digit = chk_digit(n);
	result = malloc(digit + 1);
	if (!result)
		return (NULL);
	result = (char *)ft_memset(result, 1, digit);
	result[digit] = '\0';
	if (n < 0)
	{
		num = (unsigned int)(n * -1);
		result[0] = '-';
	}
	else
		num = (unsigned int)n;
	return (ft_convert(num, result));
}
