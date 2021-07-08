/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 16:18:24 by gkim              #+#    #+#             */
/*   Updated: 2021/01/01 17:25:10 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*tmp;
	const unsigned char	*s;

	tmp = dest;
	s = src;
	if (!(dest || src))
		return (NULL);
	while (n--)
		*tmp++ = *s++;
	return (dest);
}
