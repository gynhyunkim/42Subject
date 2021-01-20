/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 19:39:59 by gkim              #+#    #+#             */
/*   Updated: 2021/01/19 17:15:18 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

void	cut_line(char **line, char **tocut)
{
	int		len;
	char	*tmp;

	tmp = NULL;
	len = ft_strchr(*tocut, '\n');
	printf("%d\n", len);
	*line = ft_strdup(*tocut, len + 1);
	if (len < ft_strlen(*tocut) - 1)
		tmp = ft_strdup(*tocut + len + 1, ft_strlen(*tocut) - len);
	free(*tocut);
	*tocut = tmp;
}

int	get_next_line(int fd, char **line)
{
	int 		rsize;
	char		buf[BUFFER_SIZE + 1];
	char		*tmp;
	static char *backup[FOPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	while((rsize = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		printf("%d\n", rsize);
		buf[BUFFER_SIZE] = '\0';
		if (backup[fd] == NULL)
			backup[fd] = ft_strdup("", 1);
		tmp = ft_strjoin(backup[fd], buf);
		free(backup[fd]);
		backup[fd] = tmp;
		if (ft_strchr(backup[fd], '\n') != 0)
		{
			cut_line(line, &backup[fd]);
			break;
		}
	}
	if (backup[fd] == NULL)
		return (0);
	else
		cut_line(line, &backup[fd]);	
	return (1);	
}
