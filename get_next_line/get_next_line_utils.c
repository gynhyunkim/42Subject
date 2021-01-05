/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 13:37:53 by gkim              #+#    #+#             */
/*   Updated: 2021/01/05 16:53:50 by gkim             ###   ########.fr       */
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

char	*ft_strdup(const char *s1)
{
	char	*cpystr;
	int		i;

	cpystr = (char *)malloc(ft_strlen(s1) + 1);
	if (cpystr == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		cpystr[i] = s1[i];
		i++;
	}
	cpystr[i] = '\0';
	return (cpystr);
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


int		ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	if (c == 0)
		return (ft_strlen(s));
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (0);
}

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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *result;

	if (!(s1 && s2))
		return (NULL);
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	result = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (result == NULL)
		return (result);
	ft_strlcpy(result, s1, ft_strlen(s1) + 1);
	ft_strlcat(result, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	return (result);
}
