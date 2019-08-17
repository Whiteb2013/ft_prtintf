#include <stdio.h>
#include "ft_printf.h"

int ft_printf(const char *str, ...);

int main()
{
    printf("%f\n", -1.245);
    puts("");
    ft_printf("%f\n", -1.245);
    puts("");
    printf("%f\n", 1.245);
    puts("");
    ft_printf("%f\n", 1.245); 

    return (0);
}