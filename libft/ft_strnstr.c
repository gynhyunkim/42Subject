/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 14:18:37 by gkim              #+#    #+#             */
/*   Updated: 2020/12/23 14:35:06 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *niddle, size_t len)
{
	int i;

	i = 0;
	if (ft_strlen(niddle) == 0)
		return ((char *)haystack);
	while (i < (int)len && haystack[i])
	{
		if (haystack[i] == niddle[0])
		{
			if (ft_strncmp(haystack + i, niddle, ft_strlen(niddle)) == 0)
				return ((char *)(haystack + i));
		}
		i++;
	}
	return (NULL);
}
