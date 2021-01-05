/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 19:39:59 by gkim              #+#    #+#             */
/*   Updated: 2021/01/05 16:50:10 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	int			rsize;
	int			idx;
	char		buf[BUFFER_SIZE + 1];
	char		*tmp;
	static char	*backup;
	
	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	if ((rsize = read(fd, buf, BUFFER_SIZE)) == 0 && !backup)
		return (0);
	if (rsize == 0 && backup)
	{
		idx = ft_strchr(backup, '\n');
		if (!idx)
		{
			*line = ft_strdup(backup);
			free(backup);
		}
		else
		{
			*line = ft_substr(backup, 0, idx);
			tmp = ft_strdup(backup + idx);
			free(backup);
			backup = tmp;
		}
	}
	else
	{
		tmp = ft_strjoin(backup, buf);
		if (backup)
			free(backup);
		backup = tmp;
		idx = ft_strchr(backup, '\n');
		if (!idx)
			return (get_next_line(fd, line));
		else
		{
			*line = ft_substr(backup, 0, idx + 1);
			tmp = ft_substr(backup + idx, 0, ft_strlen(backup) - idx - 1);
			free(backup);
			backup = tmp;
		}
	}
	return (1);
}