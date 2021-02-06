/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 16:50:48 by gkim              #+#    #+#             */
/*   Updated: 2021/02/07 00:57:09 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef char	t_bool;
# define TRUE 1
# define FALSE 0

typedef struct	s_flags {
	t_bool		zero;
	t_bool		minus;
	int			width;
	int			prec;
	int			type;
}				t_flags;

int				ft_printf(const char *format, ...);
void			parse_flags(const char **format, va_list ap, t_flags **flg);

#endif
