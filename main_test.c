#include <stdio.h>
#include "ft_printf.h"

int ft_printf(const char *str, ...);

int main()
{
    puts("test1");
    puts("printf");
    printf("%hd", 32767);
    puts("");
    puts("ft_printf");
    ft_printf("%hd", 32767);
    puts("");
    puts("");


    return (0);
}