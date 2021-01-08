/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 19:39:59 by gkim              #+#    #+#             */
/*   Updated: 2021/01/08 18:42:19 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	cut_line(int fd, char **line, char **tocut)
{
	int		i;
	int		len;
	char	*tmp;

	len = ft_strchr(*tocut, '\n');
	len = len == 0 ? ft_strlen(*tocut) : len + 2;
	tmp = NULL;
	*line = ft_strdup(*tocut, len);
	if (len != ft_strlen(*tocut))
		tmp = ft_strdup(&*tocut[ft_strlen(*line)], ft_strlen(*tocut) - ft_strlen(*line));
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
	while ((rsize = read(fd, buf, BUFFER_SIZE)) >= 0)
	{
		if ((rsize = read(fd, buf, BUFFER_SIZE)) == 0 && backup[fd] == NULL)
			return (0);
		if (backup[fd] == NULL)
			backup[fd] = ft_strdup("", 1);
		buf[rsize] = '\0';
		if (rsize > 0)
		{
			tmp = ft_strjoin(backup[fd], buf);
			free(backup[fd]);
			backup[fd] = tmp;
		}
		if (ft_strchr(backup[fd], '\n') != 0 || rsize < BUFFER_SIZE)
		{
			cut_line(fd, line, &backup[fd]);
			return (1);
		}
	}
}
