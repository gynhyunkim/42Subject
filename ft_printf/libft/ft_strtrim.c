/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 18:19:25 by gkim              #+#    #+#             */
/*   Updated: 2020/12/27 13:35:45 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	unsigned int	end;
	size_t			len;

	if (!s1)
		return (NULL);
	start = 0;
	len = 0;
	while (ft_strchr(set, s1[start]) != NULL && s1[start])
		start++;
	if (start == ft_strlen(s1))
		return (ft_calloc(1, 1));
	end = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[end]) != NULL)
		end--;
	len = end - start + 1;
	return (ft_substr(s1, start, len));
}
