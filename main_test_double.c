#include <stdio.h>
#include "ft_printf.h"

int ft_printf(const char *str, ...);

int main()
{
    printf("std:%f", 123.123);
    puts("");
    ft_printf("cst:%e", 123.123);
    puts("");
    printf("std:%f", -123.123);
    puts("");
    ft_printf("cst:%e", -123.123);
    puts("");
	printf("std:%f", -0.0);
    puts("");
    ft_printf("cst:%e", -0.0);
    puts("");

	/*
	printf("std:%#.0f", 123.123);
    puts("");
    ft_printf("cst:%#.0e", 123.123);
    puts("");
    printf("std:%f", -123.123);
    puts("");
    ft_printf("cst:%e", -123.123);
    puts("");
    printf("std:%.20f", 123456.6666666);
    puts("");
    ft_printf("cst:%.20e", 123456.6666666);
    puts("");
	*/

    return (0);
}