
#include "include/push_swap.h"

// input값 체크를 위한 custom atoi~!

long long	ps_atoi(const char *s)
{
	long long	num;
	int			mark;
	int			i;
	int			len;

	num = 0;
	i = 0;
	mark = 1;
	len = ft_strlen(s);
	if (s[i] == "-")
	{
		mark *= -1;
		i++;
	}
	while (ft_isdigit(s[i]))
	{
		num *= 10;
		num += s[i++] - '0';
	}
	if (i < len)
		return ()


}