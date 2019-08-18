#include <stdio.h>
#include "ft_printf.h"

int ft_printf(const char *str, ...);

int main()
{
    puts("test0");
    puts("printf");
    printf("@main_ftprintf: %###-#0000 33...12..#0+0d", 256);
    puts("");
    puts("ft_printf");
    ft_printf("@main_ftprintf: %###-#0000 33...12..#0+0d", 256);
    puts("");
    puts("");

    return (0);
}