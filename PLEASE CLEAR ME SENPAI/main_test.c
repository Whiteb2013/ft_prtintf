#include <stdio.h>
#include "ft_printf.h"

int ft_printf(const char *str, ...);

int main()
{
    int i = 0;

    //i = printf("%s\n", NULL);
    //printf("\ni = %i\n", i);
    puts("test0");
    puts("printf");
    printf("%.2s", NULL);
    puts("");
    puts("ft_printf");
    ft_printf("%.2s", NULL);
    puts("");
    puts("");

    return (0);
}