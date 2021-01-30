#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

typedef struct	s_flags {
	char		zero;
	char		minus;
	char		wildcard;
	char		dot;
}				t_flags; //init함수 필요

int				ft_printf(const char *format, ...);

#endif