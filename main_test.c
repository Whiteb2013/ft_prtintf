#include <stdio.h>
#include "ft_printf.h"

int ft_printf(const char *str, ...);

int main()
{
    puts("test4");
    puts("printf");
    printf("% c", 0);
    puts("");
    puts("ft_printf");
    ft_printf("% c", 0);
    puts("");
    puts("");

    return (0);
}