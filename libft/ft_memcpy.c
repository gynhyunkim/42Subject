/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 16:18:24 by gkim              #+#    #+#             */
/*   Updated: 2020/12/25 15:31:44 by gkim             ###   ########.fr       */
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
