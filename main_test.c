#include <stdio.h>
#include "ft_printf.h"

int ft_printf(const char *str, ...);

int main()
{
    puts("test2");
    puts("printf");
    printf("%5%");
    puts("");
    puts("ft_printf");
    ft_printf("%5%");
    puts("");
    puts("");

    return (0);
}