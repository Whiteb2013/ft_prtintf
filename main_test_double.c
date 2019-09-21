#include <stdio.h>
#include "ft_printf.h"
#include <math.h>

int ft_printf(const char *str, ...);

int main()
{
    printf("std:%.200f", 123123123.123);
    puts("");
    ft_printf("cst:%.20e", 123123123.123);
    puts("");
    /*
    printf("std:%.23f", 999364567890123456999000.6666666);
    puts("");
    ft_printf("cst:%.20e", 999364567890123456999000.6666666);
    puts("");
    ft_printf("cst:%.20e", 123123.6666666);
    puts("");
    ft_printf("cst:%.20e", 122.1236666666);
    puts("");
    ft_printf("cst:%.20e", 1.1236666666);
    puts("");
    ft_printf("cst:%.20e", 0.1236666666);
    puts("");
    ft_printf("cst:%#10.6e", 1.123/0);
    puts("");
	*/
    /*
	printf("std:%#10.6f", 1.123/0);
    puts("");
    printf("std:%f", -0.0);
    puts("");
    ft_printf("cst:%e", -0.0);
    puts("");
	printf("std:%f", 123.123);
    puts("");
    ft_printf("cst:%e", 123.123);
    puts("");
    printf("std:%f", -123.123);
    puts("");
    ft_printf("cst:%e", -123.123);
    puts("");
	
	printf("std:%f", -1.0);
    puts("");
    ft_printf("cst:%e", -1.0);
    puts("");
	printf("std:%f", -0.98);
    puts("");
    ft_printf("cst:%e", -0.98);
    puts("");
	*/

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