#include "ft_printf.h"
#include "libft/libft.h"

void	print_char(va_list ap, t_flags check)
{
	char	ch;

	check.dot = '.';
	ch = va_arg(ap, int);
	ft_putchar_fd(ch, 1);
}



int		ft_printf(const char *format, ...) //%와 flags체크 후 포맷에 따라 함수 호출
{
	va_list ap;
	char 	test;
	t_flags check;

	va_start(ap, format); //가변인자의 주소를 알기 위해 고정매개변수를 인자로 사용
	while (*format)
	{
		if (*format == '%')
		{
			//%뒤의 문자를 확인하는 함수
			++format;
			if (*format == 'c')
				print_char(ap, check);
			else if (*format == 's')
			{
				char* str = va_arg(ap, char*);
				ft_putstr_fd(str, 1);
			}
		}
		else
			write(1, format, 1);
//		write(1, "\n", 1);
		format++;
	}
	va_end(ap);
}

