/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 19:39:59 by gkim              #+#    #+#             */
/*   Updated: 2021/01/21 19:51:45 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	cut_backup(char **line, char **backup, char *cutptr)
{
	char	*line;
	char	*tmp;

	*cutptr = '\0';
	if (!(line = ft_strdup(*backup)) || !(tmp = ft_strdup(cutptr + 1)))
	{
		free(*backup);
		*backup = NULL;
		return (-1);
	}
	free(*backup);
	*backup = tmp;
	return (1);
}

int	get_line(char **line, char **backup, char *cutptr)
{
	if (cutptr)
		return (cut_backup(line, backup, cutptr));
	if (!*backup)
	{
		if (!(*line = ft_strdup("")))
			return (-1);
	}
	else
	{
		*line = *backup;
		*backup = NULL;
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	size_t		rsize;
	char		*buf;
	char		*tmp;
	static char *backup[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	if (!(buf = (char *)malloc(BUFFER_SIZE + 1)))
		return (-1);
	while(!(tmp = ft_strchr(backup[fd], '\n')) &&
	(rsize = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[rsize] = '\0';
		if (!(tmp = ft_strjoin(backup[fd], buf)))
			return (-1);
		if (backup[fd])
			free(backup[fd]);
		backup[fd] = tmp;
	}
	free(buf);
	buf = 0;
	if (rsize < 0)
		return (-1);
	return (get_line(line, &backup[fd], tmp));
}
