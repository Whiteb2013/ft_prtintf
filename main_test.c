#include <stdio.h>
#include "ft_printf.h"

int ft_printf(const char *str, ...);

int main()
{
    int i = 0;

    i = printf("%s\n", NULL);
    printf("\ni = %i\n", i);
    puts("test0");
    puts("printf");
    i = printf("@moulitest: %s", NULL);
    //i = printf("%.x", 0, 0);
    printf("\ni = %i\n", i);
    puts("");
    puts("ft_printf");
    i = ft_printf("@moulitest: %s", NULL);
    //i = ft_printf("%.x", 0, 0);
    printf("\ni = %i\n", i);
    puts("");
    puts("");

    return (0);
}