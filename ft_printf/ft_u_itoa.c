#include "ft_printf.h"

static size_t	chk_u_digit(unsigned long n)
{
	size_t	digit;

	digit = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 10;
		digit++;
	}
	return (digit);
}

static char		*ft_u_convert(unsigned long n, char *num)
{
	unsigned int	i;

	i = ft_strlen(num) - 1;
	if (!n)
		num[i] = '0';
	while (n)
	{
		num[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	return (num);
}

char			*ft_u_itoa(unsigned long n)
{
	char			*result;
	size_t			digit;

	digit = chk_u_digit(n);
	if (!(result = (char *)malloc(digit + 1)))
		return (NULL);
	result = (char *)ft_memset(result, 1, digit);
	result[digit] = 0;
	return (ft_u_convert(n, result));
}
