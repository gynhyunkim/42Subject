/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 13:37:53 by gkim              #+#    #+#             */
/*   Updated: 2021/01/03 17:54:15 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	int	i;

	i = 0;
	if (src == NULL)
		return (0);
	while (i < (int)(size - 1) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	if (size > 0)
		dst[i] = 0;
	return (ft_strlen(src));
}

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	if (c == 0)
		return ((char *)&s[ft_strlen(s)]);
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;

	if (!s)
		return (NULL);
	result = (char *)malloc(len + 1);
	if (result == NULL)
		return (result);
	ft_strlcpy(result, s + start, len + 1);
	return (result);
}

char	*ft_realloc(char *str, size_t size)
{
	char *newalloc;

	if (!(newalloc = malloc(size)))
		return (NULL);
	ft_strlcpy(newalloc, str, ft_strlen(str) + 1);
	free(str);
	return (newalloc);
}
