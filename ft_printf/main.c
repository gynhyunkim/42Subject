#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	char test = 'c';

	printf("--------printf--------\n");
	printf("%0c\n", 3, 'h');
	printf("-------ft_printf------\n");
	ft_printf("%0c\n", 3, 'h');
	// ft_printf("%-5s\n", "happy day");
	// ft_printf("%-.5s\n", "happy day");
	// ft_printf("%.20s\n", "happy day");
	return (0);
}