/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 13:37:53 by gkim              #+#    #+#             */
/*   Updated: 2021/01/19 21:59:09 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t len;

	len = 0;
	while(str[len])
		len++;
	return (len);
}

char	*ft_strdup(const char *str)
{
	unsigned int	i;
	char			*newstr;

	if (!(newstr = malloc(ft_strlen(str) + 1)))
		return (NULL);
	i = 0;
	while(str[i])
	{
		newstr[i] = str[i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}

int		ft_strchr(const char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*joined;
	int		s1len;
	int		s2len;

	if (s1 == NULL && s2)
		return (ft_strdup(s2));
	else if (s2 == NULL && s1)
		return (ft_strdup(s1));
	if (!(joined = malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	s1len = 0;
	while (s1[s1len])
	{
		joined[s1len] = s1[s1len];
		s1len++;
	}
	s2len = 0;
	while (s2[s2len])
	{
		joined[s1len + s2len] = s2[s2len];
		s2len++;
	}
	joined[s1len + s2len] = '\0';
	return (joined);
}
