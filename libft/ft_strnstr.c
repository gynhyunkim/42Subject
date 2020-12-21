/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 14:18:37 by gkim              #+#    #+#             */
/*   Updated: 2020/12/21 14:33:25 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 || *s2)
	{
		if (*s1 != *s2)
			return (0);
		s1++;
		s2++;
	}
	return (1);
}

char		*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t i;

	i = 0;
	while (i < len && big[i])
	{
		if (big[i] == little[0])
		{
			if (ft_strcmp(&big[i], little))
				return (big + i);
		}
		i++;
	}
	return (NULL);
}