/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 13:59:57 by gkim              #+#    #+#             */
/*   Updated: 2020/12/25 16:51:45 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cnt_word(char const *s, char c)
{
	int		cnt;
	int		size;
	int		i;

	i = 0;
	size = 0;
	cnt = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			if (size != 0)
				cnt++;
			size = 0;
		}
		else
			size++;
		i++;
	}
	if (size != 0)
		cnt++;
	return (cnt);
}

static char	**free_strs(char **strs, int j)
{
	while (j--)
	{
		free(strs[j]);
	}
	free(strs);
	return (NULL);
}

static char	**splitword(char *s, char c, char **strs, int cnt)
{
	int		i;
	int		j;
	size_t	size;

	i = 0;
	j = 0;
	size = 0;
	while (j < cnt)
	{
		if (s[i] == c || s[i] == 0)
		{
			if (size != 0)
			{
				if ((strs[j] = ft_substr(s, i - size, size)) == NULL)
					return (free_strs(strs, j));
				j++;
			}
			size = 0;
		}
		else
			size++;
		i++;
	}
	return (strs);
}

char		**ft_split(char const *s, char c)
{
	char	**strs;
	int		cnt;

	if (s == NULL)
		return (NULL);
	cnt = cnt_word(s, c);
	strs = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (strs == NULL)
		return (NULL);
	strs[cnt] = NULL;
	return (splitword((char *)s, c, strs, cnt));
}
