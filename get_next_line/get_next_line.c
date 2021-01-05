/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 19:39:59 by gkim              #+#    #+#             */
/*   Updated: 2021/01/05 16:04:27 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	int			rsize;
	char		buf[BUFFER_SIZE + 1];
	size_t		len;
	char	*nullp;
	static char	*backup;
	
	if (fd < 0 || (rsize = read(fd, buf, BUFFER_SIZE)) < 0)
		return (-1);
	buf[rsize] = '\0';
	if (rsize == 0 && backup == NULL)
		return (0);
	if (rsize == 0)
	{
		//backup에서 한 줄 잘라서 반환
		nullp = ft_strchr(backup, '\n');
		nullp = nullp == NULL ? &backup[ft_strlen(backup)] : nullp;
		*line = ft_substr(backup, 0, (size_t)(nullp - backup));
		if (*nullp == '\0')
			free(backup);
		else
		{
			nullp = ft_substr(nullp, 0, ft_strlen(backup) - (size_t)(nullp - backup));
			free(backup);
			backup = nullp;
		}
	}
	else
	{
		//buf에 개행문자 있으면 line 할당 후 backup + buf 저장, buf 개행문자 이후 잘라서 backup에 저장
		if (nullp = ft_strchr(buf, '\n'))
		{
			*line = malloc(ft_strlen(backup) + (size_t)(nullp - buf));
			ft_strlcpy(*line, backup, ft_strlen(backup));
			ft_strlcpy(*(line + ft_strlen(backup)), buf, (size_t)(nullp - buf) + 1);
			free(backup);
			backup = ft_substr(nullp, 0, (size_t)(&buf[rsize] - nullp));
		}
		//buf에 개행문자 없을 경우 backup에 이어붙이고 다시 read
		else
		{
			backup = ft_realloc(backup, ft_strlen(backup) + rsize + 1);
			return (get_next_line(fd, line));
		}
	}
	return (1);
}