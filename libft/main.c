#include <stdio.h>
#include "libft.h"

int		main(void)
{
	char	**test;
	int		i = 0;
	test = ft_split("12345 6789 10 11 112", ' ');
	while (test[i] != 0)
	{
		printf("%s\n", test[i]);
		i++;
	}
}