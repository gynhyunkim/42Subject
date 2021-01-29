  
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

char			*ft_strnstr(const char *hay, const char *nee, size_t len)
{
	size_t		n;
    if (!*hay)
        return (NULL);
	if (!(n = ft_strlen(nee)))
		return ((char *)hay);
	while (len >= n && *hay)
	{
		if (!(ft_strncmp(hay, nee, n)))
			return ((char *)hay);
		hay++;
		len--;
	}
	return (NULL);
}
