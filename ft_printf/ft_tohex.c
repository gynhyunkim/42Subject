/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tohex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 20:23:52 by gkim              #+#    #+#             */
/*   Updated: 2021/02/07 21:39:44 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	check_len(unsigned long long n)
{
	size_t len;

	len = 0;
	while (n)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

char			*ft_tohex(unsigned long long n, char *set)
{
	size_t	len;
	char	*hex;

	if (n == 0)
		return (ft_strdup("0"));
	len = check_len(n);
	hex = (char *)malloc(len + 1);
	hex[len--] = '\0';
	if (n == 0)
		hex[len] = '0';
	while (n)
	{
		hex[len--] = set[(int)(n % 16)];
		n = n / 16;
	}
	printf("%s\n", hex);
	return (hex);
}
