#include <stdio.h>
#include "ft_printf.h"

int ft_printf(const char *str, ...);

int main()
{
	//int i = 0;

	printf("%o\n", -4646);
	ft_printf("%o\n", -4646);
	puts("");

	printf("stnd:null %c and text\n", 0);
	ft_printf("cust:null %c and text\n", 0);
	puts("");

	printf("stnd:%.2s is a string\n", "");
	ft_printf("cust:%.2s is a string\n", "");
	puts("");

	printf("stnd:%#.x %#.0x %.0x %5.0x.here.\n", 00, 00, 00, 00);
	ft_printf("cust:%#.x %#.0x %.0x %5.0x.here.\n", 00, 00, 00, 00);
	puts("");

	printf("stnd:%.0o %5.0o.here.\n", 00, 00);
	ft_printf("stnd:%.0o %5.0o.here.\n", 00, 00);
	puts("");

	printf("stnd:%#.o %#.0o.here.\n", 00, 00);
	ft_printf("stnd:%#.o %#.0o.here.\n", 00, 00);
	puts("");

	printf("stnd:%.0d %5.0d.here.\n", 0, 0);
	ft_printf("cust:%.0d %5.0d.here.\n", 0, 0);
	puts("");

	printf("%p\n", NULL);
	ft_printf("%p\n", NULL);
	puts("");
	
	printf("|%2c|\n", 0);
 	ft_printf("|%2c|\n", 0);
	printf("|%2c|\n", 56);
 	ft_printf("|%2c|\n", 56);
	puts("");

	// puts("test0");
	// puts("printf");
	// i = printf("%.x", 0, 0);
	// printf("\ni = %i\n", i);
	// puts("");
	// puts("ft_printf");
	// i = ft_printf("%.x", 0, 0);
	// printf("\ni = %i\n", i);
	// puts("");
	// 

	// puts("test0");
	// puts("printf");
	// printf("@moulitest: %.x %.0x", 0, 0);
	// puts("");
	// puts("ft_printf");
	// ft_printf("@moulitest: %.x %.0x", 0, 0);
	// puts("");
	// puts("");

	// puts("test0");
	// puts("printf");
	// printf("@moulitest: %5.x %5.0x", 0, 0);
	// puts("");
	// puts("ft_printf");
	// ft_printf("@moulitest: %5.x %5.0x", 0, 0);
	// puts("");
	// puts("");

	return (0);
}