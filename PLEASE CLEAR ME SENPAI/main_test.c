#include <stdio.h>
#include "ft_printf.h"

int main()
{
	//i = printf("%s\n", NULL);
    //printf("\ni = %i\n", i);
    // puts("test0");
    // puts("printf");
    printf("%1$d:%3$*.*d:%d:%3$d:%d\n", 1, 2, 3, 4, 5);
    // puts("");
    // puts("printf");
    // printf("%1$10d:%2$10d:%03$d:%-4$d:%5$d\n", 1, 2, 3, 4, 5);
    // puts("");
    puts("ft_printf");
    //ft_printf("%1$d:%2$d:%3$d:%4$d:%5$d\n", 1, 2, 3, 4, 5);
    //ft_printf("%10.f\n", 12.34);
    puts("");
    puts("");

    return (0);
}

// int				main(void)
// {
//    ft_printf("%20.15d\n", 54321);
// //   ft_printf("%-10d\n", 3);
// //   ft_printf("% d\n", 3);
// //   ft_printf("%+d\n", 3);
// //   ft_printf("%010d\n", 1);
//   return (0);
// }
