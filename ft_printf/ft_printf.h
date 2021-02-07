/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkim <gkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 16:50:48 by gkim              #+#    #+#             */
/*   Updated: 2021/02/07 21:35:04 by gkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
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
int				print_memory(va_list ap, t_flags *flags);
char			*ft_u_itoa(unsigned long n);
int				print_string(va_list ap, t_flags *flags);
int				print_padding(int n, t_bool zero);
int				print_char(va_list ap, t_flags *flags);
int				print_num(va_list ap, t_flags *flags);
char			*ft_tohex(unsigned long long n, char *set);
int				print_memory(va_list ap, t_flags *flags);

#endif
