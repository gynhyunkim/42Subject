/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 14:18:37 by gkim              #+#    #+#             */
/*   Updated: 2021/07/07 17:00:44 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *nee, size_t len)
{
	size_t	n;

	if (!*hay)
		return (NULL);
	n = ft_strlen(nee);
	if (!n)
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
