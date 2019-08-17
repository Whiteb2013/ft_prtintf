#include <stdio.h>
#include "ft_printf.h"

int ft_printf(const char *str, ...);

int main()
{
    puts("test2");
    puts("printf");
    printf("%10x", 42);
    puts("");
    puts("ft_printf");
    ft_printf("%10x", 42);
    puts("");
    puts("");

    puts("test3");
    puts("printf");
    printf("%-10X", 42);
    puts("");
    puts("ft_printf");
    ft_printf("%-10X", 42);
    puts("");
    puts("");

    return (0);
}