#include "ft_printf.h"
#include <stdio.h>

void	init_flags(t_flags **flags)
{
	(*flags) -> zero = FALSE;
	(*flags) -> minus = FALSE;
	(*flags) -> width = -1;
	(*flags) -> prec = -1;
}


void	set_flags(const char **format, va_list ap, t_flags **flg)
{
	init_flags(flg);
	while (!ft_isalpha(**format))
	{
		if (**format != '0' && ft_isdigit(**format))
		{
			(*flg) -> width = ft_atoi(*format);
			while (ft_isdigit(**format))
				(*format)++;
			(*format)--;
		}
		else if (**format == '*')
			(*flg) -> width = va_arg(ap, int);
		else if (**format == '-')
			(*flg) -> minus = TRUE;
		else if (**format == '0')
			(*flg) -> zero = TRUE;
		else if (**format == '.')
		{
			(*flg) -> prec = ft_atoi(++(*format));
			while (ft_isdigit(**format))
				(*format)++;
			(*format)--;
		}
		(*format)++;
	}
}

int		print(va_list ap, t_flags flags)
{
	int		count;


}

int		ft_printf(const char *format, ...) //%와 flags체크 후 포맷에 따라 함수 호출
{
	va_list ap;
	char 	test;
	t_flags	*check_f;
	int		cnt;

	cnt = 0;
	va_start(ap, format);
	check_f = (t_flags *)malloc(sizeof(t_flags));
	while (*format)
	{
		if (*format == '%')
		{
			++format;
			set_flags(&format, ap, &check_f);
			check_f -> type = *format;
			
		}
		else
			ft_putchar_fd(*format, 1);
		format++;
	}
	printf("cnt = %d\n", cnt);
	va_end(ap);
	free(check_f);
	return (0);
}
