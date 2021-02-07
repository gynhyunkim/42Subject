/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tohex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 20:23:52 by gkim              #+#    #+#             */
/*   Updated: 2021/02/07 20:25:02 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
