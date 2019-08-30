#include <stdio.h>
#include "ft_printf.h"

int ft_printf(const char *str, ...);

// int main()
// {
//     int i = 0;

//     //i = printf("%s\n", NULL);
//     //printf("\ni = %i\n", i);
//     puts("test0");
//     puts("printf");
//     printf("%s", "abc");
//     puts("");
//     puts("ft_printf");
//     ft_printf("%s", "abc");
//     puts("");
//     puts("");

//     return (0);
// }

int				main(void)
{
   ft_printf("%20.15d\n", 54321);
//   ft_printf("%-10d\n", 3);
//   ft_printf("% d\n", 3);
//   ft_printf("%+d\n", 3);
//   ft_printf("%010d\n", 1);
  return (0);
}
