/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 18:08:13 by gkim              #+#    #+#             */
/*   Updated: 2020/12/22 18:15:32 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;

	if (start > ft_strlen(s))
		return (ft_calloc(1, 1));
	result = (char *)malloc(len + 1);
	if (result == NULL)
		return (result);
	ft_strlcpy(result, s + start, len + 1);
	return (result);
}
