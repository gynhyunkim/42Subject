/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 13:44:26 by gkim              #+#    #+#             */
/*   Updated: 2020/12/27 13:27:56 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dlen;
	size_t	len;
	int		i;

	dlen = ft_strlen(dst);
	i = 0;
	if (size <= dlen)
		return (ft_strlen(src) + size);
	len = ft_strlen(src) + dlen;
	while (src[i] && i < (int)(size - dlen - 1))
	{
		dst[i + dlen] = src[i];
		i++;
	}
	if (size > 0)
		dst[i + dlen] = 0;
	return (len);
}
