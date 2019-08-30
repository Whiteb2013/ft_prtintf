#include <stdio.h>
#include "ft_printf.h"

int ft_printf(const char *str, ...);

int main()
{
	int a = -42;
	
	printf("%llu\n", a);
	ft_printf("%llu\n", a);
	puts("");
	
	printf("%llu\n", (unsigned long long)a);
	ft_printf("%llu\n", (unsigned long long)a);
	puts("");

	return (0);
}