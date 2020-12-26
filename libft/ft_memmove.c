/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 16:56:20 by gkim              #+#    #+#             */
/*   Updated: 2020/12/23 14:30:30 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*tmp;
	unsigned char	*s;
	int				i;

	tmp = (unsigned char *)dst;
	s = (unsigned char *)src;
	i = 0;
	if (dst < src)
	{
		while (len--)
		{
			tmp[i] = s[i];
			i++;
		}
	}
	else if (dst > src)
	{
		while (len--)
			*(tmp + len) = *(s + len);
	}
	return (dst);
}
