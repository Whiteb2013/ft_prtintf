#include <stdio.h>
#include "ft_printf.h"

int ft_printf(const char *str, ...);

int main()
{
    int i = 0;

    puts("test0");
    puts("printf");
    i = printf("%.x", 0, 0);
    printf("\ni = %i\n", i);
    puts("");
    puts("ft_printf");
    i = ft_printf("%.x", 0, 0);
    printf("\ni = %i\n", i);
    puts("");
    puts("");

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