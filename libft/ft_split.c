/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 13:59:57 by gkim              #+#    #+#             */
/*   Updated: 2020/12/22 14:34:11 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_cnt(char const *s, char c)
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

char		**ft_split(char const *s, char c)
{
	int		cnt;
	int		i;
	int		j;
	char	**strs;
	size_t	size;

	cnt = word_cnt(s, c);
	strs = (char **)malloc(sizeof(char *) * (cnt + 1));
	i = 0;
	j = 0;
	size = 0;
	while (j < cnt)
	{
		if (s[i] == c || s[i] == 0)
		{
			if (size != 0)
				strs[j++] = ft_substr(s, i - size, size);
			size = 0;
		}
		else
			size++;
		i++;
	}
	strs[j] = NULL;
	return (strs);
}
