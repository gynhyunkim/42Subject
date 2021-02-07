#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	char test = 'c';
	char *p = &test;
	long long	mem = (long long)p;

	// printf("--------printf--------\n");
	// printf("%0c\n", 3, 'h');

	printf("[%15x]\n", 123456);
	printf("[%15X]\n", 123456);
	printf("[%-15x]\n", 123456);
	printf("[%-15X]\n", 123456);
	printf("[%.15x]\n", 123456);
	printf("[%.15X]\n", 123456);
	printf("[%015x]\n", 123456);
	printf("[%015X]\n", 123456);
	printf("[%16.15x]\n", 123456);
	printf("[%16.15X]\n", 123456);
	printf("[%-015x]\n", 123456);
	printf("[%-015X]\n", 123456);
	ft_printf("-------ft_printf------\n");
	ft_printf("[%15x]\n", 123456);
	ft_printf("[%15X]\n", 123456);
	ft_printf("[%-15x]\n", 123456);
	ft_printf("[%-15X]\n", 123456);
	ft_printf("[%.15x]\n", 123456);
	ft_printf("[%.15X]\n", 123456);
	ft_printf("[%015x]\n", 123456);
	ft_printf("[%015X]\n", 123456);
	ft_printf("[%16.15x]\n", 123456);
	ft_printf("[%16.15X]\n", 123456);
	ft_printf("[%-015x]\n", 123456);
	ft_printf("[%-015X]\n", 123456);
	// ft_printf("%15u\n", 4294967297);
	// ft_printf("%15s\n", "hello");
	// ft_printf("%-5s\n", "happy day");
	// ft_printf("%-.5s\n", "happy day");
	// ft_printf("%.20s\n", "happy day");
	return (0);
}