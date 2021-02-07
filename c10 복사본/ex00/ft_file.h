/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 17:57:29 by gkim              #+#    #+#             */
/*   Updated: 2020/12/03 19:00:21 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILE_H

# define FT_FILE_H

# include <unistd.h>
# include <fcntl.h>
# define NO_ARGC "File name missing.\n"
# define MANY_ARGC "Too many arguments.\n"
# define NO_READ "Cannot read file.\n"
void	ft_display_file(char *argv);
void	ft_putstr(char *str);

#endif
