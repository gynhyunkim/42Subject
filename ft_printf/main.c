#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	char test = 'c';

	// printf("--------printf--------\n");
	// printf("%s\n", "hello World");
	// printf("%*c\n", 3, 'h');
	// printf("how many printed %d\n", printf("%3c", 'h'));
	// printf("%3c\n", 'h');
	printf("-------ft_printf------\n");
	ft_printf("%3c %c\n", 'h', 'a');
	return (0);
}