/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 16:56:20 by gkim              #+#    #+#             */
/*   Updated: 2020/12/21 20:20:29 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *tmp;
	unsigned char *s;

	tmp = dst;
	s = (unsigned char *)src;
	if (dst < src)
	{
		while (len--)
		{
			*tmp = *s;
			tmp++;
			s++;
		}
	}
	else if (dst > src)
	{
		while (--len)
			*(tmp + len) = *(s + len);
	}
	dst = ft_memcpy(dst, tmp, ft_strlen((const char *)tmp));
	return (dst);
}