/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 18:19:25 by gkim              #+#    #+#             */
/*   Updated: 2020/12/21 20:18:23 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	chk_size(char const *s1, char const *set)
{
	int		i;
	size_t	size;

	i = 0;
	size = 0;
	while (s1[i])
	{
		if (ft_strchr(set, s1[i]) == NULL)
			size++;
		i++;
	}
	return (size);
}

static	void	ft_trim(char const *s1, char const *set, char *result)
{
	int		i;

	i = 0;
	while (s1[i])
	{
		if (ft_strchr(set, s1[i]) == NULL)
			ft_strlcat(result, s1 + i, ft_strlen(result) + 2);
		i++;
	}
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char 	*result;
	size_t	size;
	
	size = chk_size(s1, set);
	result = (char *)malloc(size + 1);
	result[0] = 0;
	ft_trim(s1, set, result);
	return (result);
}