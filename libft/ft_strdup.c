/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 18:00:23 by gkim              #+#    #+#             */
/*   Updated: 2020/12/21 21:56:48 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	cpystr[i] = 0;
	return (cpystr);
}
