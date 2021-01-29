#include "ft_printf.h"
#include "libft/libft.h"

void	print_char(va_list ap, t_flags *check)
{
	char	ch;
	int		space;

	if (check->zero || check->minus)
		return ;
	else if (check -> wildcard > 1)
		space = check->wildcard;
	while (--space)
		write(1, " ", 1);
	ch = va_arg(ap, int);
	ft_putchar_fd(ch, 1);
}

t_flags	*set_flags(const char **format, va_list ap)
{
	t_flags *flags;
	int i = 0;

	flags = (t_flags *)malloc(sizeof(t_flags));
	flags->zero = FALSE;
	flags->minus = FALSE;
	flags->wildcard=-1;
	flags->precision=-1;
	while (!ft_isalpha(**format) && **format)
	{
		if (**format == '0')
			flags->zero = TRUE;
		else if (**format == '-')
			flags->minus = TRUE;
		else if (**format == '*')
			flags->wildcard = va_arg(ap, int);
		else if (**format == '.')
		{
			(*format)++;
			flags->precision = atoi(*format);
			break ;
		}
		else if (**format >= 0 && **format <= 9)
		{
			flags->wildcard = atoi(*format);
			break ;
		}
		(*format)++;
		i++;
		if (i > 10)
			break ;
	}
	return (flags);
}

int		ft_printf(const char *format, ...) //%와 flags체크 후 포맷에 따라 함수 호출
{
	va_list ap;
	char 	test;
	t_flags	*check;
	int		cnt;

	cnt = 0;
	va_start(ap, format); //가변인자의 주소를 알기 위해 고정매개변수를 인자로 사용
	while (*format)
	{
		if (*format == '%')
		{
			++format;
			check = set_flags(&format, ap);//%뒤의 문자를 확인하는 함수
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
	return (0);
}
