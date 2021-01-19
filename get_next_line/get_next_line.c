/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 19:39:59 by gkim              #+#    #+#             */
/*   Updated: 2021/01/19 22:28:00 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	cut_line(char **line, int cut_idx, char **tocut, char *buf)
{
	char	*tmp;

	if (buf)
	{
		free(buf);
		buf = NULL;
	}
	(*tocut)[cut_idx] = '\0';
	if (!(*line = ft_strdup(*tocut)) ||
		!(tmp = ft_strdup(*tocut + cut_idx + 1)))
	{
		free(*tocut);
		*tocut = NULL;
		return (-1);
	}
	free(*tocut);
	*tocut = tmp;
	return (1);
}

int	end_line(char **line, char **str, char *buf, int rsize)
{
	int cut_idx;

	if (*buf)
	{
		free(buf);
		buf = NULL;
	}
	if (!*str)
		return (0);
	if ((cut_idx = ft_strchr(*str, '\n')) >= 0)
		return (cut_line(line, cut_idx, str, buf));
	else if (*str)
	{
		if (!(*line = ft_strdup(*str)))
			return (-1);
	}
	free(*str);
	*str = NULL;
	return (1);
}

int	get_next_line(int fd, char **line)
{
	size_t		rsize;
	char		*buf;
	char		*tmp;
	int			cut_idx;
	static char *backup[OPEN_MAX];

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
		if ((cut_idx = ft_strchr(backup[fd], '\n')) >= 0)
			return (cut_line(line, cut_idx, &backup[fd], buf));
	}
	return (end_line(line, &backup[fd], buf, rsize));
}
