/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 17:19:56 by gkim              #+#    #+#             */
/*   Updated: 2021/11/21 00:16:01 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*tmp;
	const unsigned char	*s;

	tmp = dst;
	s = src;
	while (n--)
	{
		*tmp++ = *s++;
		if (*(s - 1) == (unsigned char)c)
			return (tmp);
	}
	return (NULL);
}
