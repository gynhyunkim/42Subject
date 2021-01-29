#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

typedef char	t_bool;
# define TRUE 1
# define FALSE 0

typedef struct	s_flags {
	t_bool		zero;
	t_bool		minus;
	int			wildcard;
	int			precision;
}				t_flags;

int				ft_printf(const char *format, ...);

#endif