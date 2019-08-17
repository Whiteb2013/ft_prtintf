#include <stdio.h>
#include "ft_printf.h"

int ft_printf(const char *str, ...);

int main()
{
    puts("test0");
    puts("printf");
    printf("%lld", 9223372036854775807);
    puts("");
    puts("ft_printf");
    ft_printf("%lld", 9223372036854775807);
    puts("");
    puts("");

    puts("test1");
    puts("printf");
    printf("%lld", -9223372036854775808);
    puts("");
    puts("ft_printf");
    ft_printf("%lld", -9223372036854775808);
    puts("");
    puts("");

    return (0);
}