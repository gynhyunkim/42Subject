/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 14:18:37 by gkim              #+#    #+#             */
/*   Updated: 2020/12/25 16:49:23 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *niddle, size_t len)
{
	if (ft_strlen(niddle) == 0)
		return ((char *)haystack);
	while (len-- && *haystack)
	{
		if (*haystack == niddle[0] && len + 1 >= ft_strlen(niddle))
		{
			if (ft_memcmp(haystack, niddle, ft_strlen(niddle)) == 0)
				return ((char *)haystack);
		}
		haystack++;
	}
	return (NULL);
}
