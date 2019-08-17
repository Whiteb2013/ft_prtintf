#include <stdio.h>
#include "ft_printf.h"

int ft_printf(const char *str, ...);

int main()
{
    puts("test1");
    puts("printf");
    printf("% Z|test");
    puts("");
    puts("ft_printf");
    ft_printf("% Z|test");
    puts("");
    puts("");
  
    printf("%llu\n", 111285212672);
    printf("%i\n", 111285212672);

    return (0);
}