/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 19:39:59 by gkim              #+#    #+#             */
/*   Updated: 2021/01/20 19:31:21 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	cut_line(char **line, char **backup, char *buf, char *cutp)
{
	char *tmp;

	if (buf)
	{
		free(buf);
		buf = NULL;
	}
	if (!*backup)
	{
		*line = ft_strdup("");
		return (0);
	}
	if (cutp)
	{
		*cutp = '\0';
		*line = ft_strdup(*backup);
		tmp = ft_strdup(cutp);
		free(*backup);
		*backup = tmp;	
	}
	else
	{
		*line = ft_strdup(*backup);
		free(*backup);
		*backup = NULL;
	}
	return (1);
}

int	get_next_line(int fd, char **line)
{
	size_t		rsize;
	char		*buf;
	char		*tmp;
	char		*cutp;
	static char *backup[FOPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	if (!(buf = (char *)malloc(BUFFER_SIZE + 1)))
		return (-1);
	while((rsize = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[rsize] = '\0';
		if (!(tmp = ft_strjoin(backup[fd], buf)))
			return (-1);
		if (backup[fd])
			free(backup[fd]);
		backup[fd] = tmp;
		if (!(cutp = ft_strchr(backup[fd], '\n')))
			break;
	}
	return (cut_line(line, &backup[fd], buf, cutp));
}
