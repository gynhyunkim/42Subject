/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 17:38:38 by gkim              #+#    #+#             */
/*   Updated: 2020/12/25 15:40:26 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *m1;
	unsigned char *m2;

	m1 = (unsigned char *)s1;
	m2 = (unsigned char *)s2;
	while (n--)
	{
		if (*m1 != *m2)
			return (*m1 - *m2);
		m1++;
		m2++;
	}
	return (0);
}
