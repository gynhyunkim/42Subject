#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	char test = 'c';
	char *p = &test;
	long long	mem = (long long)p;

	// printf("--------printf--------\n");
	// printf("%0c\n", 3, 'h');
	printf("[%-*.*i]\n", -2, 1, 8);
	ft_printf("[%-*.*i]\n", -2, 1, 8);
	printf("[%-*.*d]\n", -2, 1, 8);
	ft_printf("[%-*.*d]\n", -2, 1, 8);
	printf("[%-4.2d]\n", 8);
	ft_printf("[%-4.2d]\n", 8);
	printf("[%0*.*d]\n", 4, 3, 12);
	ft_printf("[%0*.*d]\n", 4, 3, 12);
	printf("[%-*.*d]\n", 4, 3, -12);
	ft_printf("[%-*.*d]\n", 4, 3, -12);
	printf("[%-010d]\n", 12);
	ft_printf("[%-010d]\n", 12);
	printf("[%.*d]\n", -4, 12);
	ft_printf("[%.*d]\n", -4, 12);
	printf("[%.*s]\n", -4, "hello");
	ft_printf("[%.*s]\n", -4, "hello");
	printf("[%-*.*u]\n", 0, 0, 8);
	ft_printf("[%-*.*u]\n", 0, 0, 8);
	ft_printf("[%x]\n", 4294967285);
	ft_printf("[%X]\n", 4294967285);
	ft_printf("[%p]\n", p);
	// printf("[%15x]\n", 123456);
	// printf("[%15X]\n", 123456);
	// printf("[%-15x]\n", 123456);
	// printf("[%-15X]\n", 123456);
	// printf("[%.15x]\n", 123456);
	// printf("[%.15X]\n", 123456);
	// printf("[%015x]\n", 123456);
	// printf("[%015X]\n", 123456);
	// printf("[%16.15x]\n", 123456);
	// printf("[%16.15X]\n", 123456);
	// printf("[%-015x]\n", 123456);
	// printf("[%-015X]\n", 123456);
	// ft_printf("-------ft_printf------\n");
	// ft_printf("[%15x]\n", 123456);
	// ft_printf("[%15X]\n", 123456);
	// ft_printf("[%-15x]\n", 123456);
	// ft_printf("[%-15X]\n", 123456);
	// ft_printf("[%.15x]\n", 123456);
	// ft_printf("[%.15X]\n", 123456);
	// ft_printf("[%015x]\n", 123456);
	// ft_printf("[%015X]\n", 123456);
	// ft_printf("[%16.15x]\n", 123456);
	// ft_printf("[%16.15X]\n", 123456);
	// ft_printf("[%-015x]\n", 123456);
	// ft_printf("[%-015X]\n", 123456);
	// ft_printf("%15u\n", 4294967297);
	// ft_printf("%15s\n", "hello");
	// ft_printf("%-5s\n", "happy day");
	// ft_printf("%-.5s\n", "happy day");
	// ft_printf("%.20s\n", "happy day");
	return (0);
}