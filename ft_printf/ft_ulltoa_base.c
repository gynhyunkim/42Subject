/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 21:25:07 by gkim              #+#    #+#             */
/*   Updated: 2021/02/11 11:31:54 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	check_len(unsigned long long n, unsigned int base)
{
	size_t len;

	len = 0;
	while (n)
	{
		n = n / base;
		len++;
	}
	return (len);
}

char			*ft_ulltoa_base(unsigned long long n, char *set)
{
	size_t			len;
	unsigned int	base;
	char			*result;

	base = ft_strlen(set);
	if (n == 0)
		return (ft_strdup("0"));
	len = check_len(n, base);
	if (!(result = (char *)malloc(len + 1)))
		return (NULL);
	result[len--] = '\0';
	while (n)
	{
		result[len--] = set[n % base];
		n = n / base;
	}
	return (result);
}
