#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	char test = 'c';

	// printf("--------printf--------\n");
	// printf("%0c\n", 3, 'h');
	printf("-------ft_printf------\n");
	printf("%c\n", 128);
	ft_printf("[%10.03d]\n", 12345);
	// ft_printf("%15s\n", "hello");
	// ft_printf("%-5s\n", "happy day");
	// ft_printf("%-.5s\n", "happy day");
	// ft_printf("%.20s\n", "happy day");
	return (0);
}