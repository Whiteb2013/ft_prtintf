#include <stdio.h>
#include "srcs/ft_printf.h"
#include <wchar.h>
#include <locale.h>

int main()
{
	int str[8] = {0x00D8, 0x06D1, 0x00D8, 0x06D1, 0x00D8, 0x06D1, 0x00D8, 0};
	int str2[4] = {0x00D8, 0x06D1, 0x00D8, 0};
	setlocale(LC_ALL, "en_US.UTF-8");
	int n, m;
	int a, b, c, d, e, f;
	int j = 0;

	// printf("test || %.0s\n", "abcd");
	// n = ft_printf("%C\n", 0x00D8);
	// m = ft_printf("p9 %.9S\n", str);
	// m = ft_printf("p8 %.8S\n", str);
	// m = ft_printf("p7 %.7S\n", str);
	// m = ft_printf("p6 %.6S\n", str);
	// m = ft_printf("p5 %.5S\n", str);
	// m = ft_printf("p4 %.4S\n", str);
	// m = ft_printf("p3 %.3S\n", str);
	// m = ft_printf("p2 %.2S\n", str);
	// m = ft_printf("p1 %.1S\n", str);
	// m = ft_printf("p0 %.0S\n", str);
	// printf("len(C) = %d\nlen(S) = %d\n", n, m);

	//    n = printf("std: %2s -\n", "abc");
	// printf("len = %i\n", n);
	// n = ft_printf("ft_: %2s -\n", "abc");
	// printf("len = %i\n", n);
	// n = ft_printf("uni: %2S -\n", str2);
	// printf("len = %i\n", n);
	//    n = printf("std: %2c -\n", 'd');
	// printf("len = %i\n", n);
	// n = ft_printf("ft_: %2c -\n", 'd');
	// printf("len = %i\n", n);
	// n = ft_printf("uni: %2C -\n", 0x00D8);
    // printf("len = %i\n", n);

	// ft_printf("ft_: %.3S -\n", str2);

	   n = printf("{% 03d}", 0);
	m = ft_printf("{% 03d}", 0);
	printf("\nn = %i\nm = %i\n", n ,m);

	n = printf("green");
	m = ft_printf("{green}green{eoc}");
	printf("\nn = %i\nm = %i\n", n ,m);
	return (0);
}

// int				main(void)
// {
//    ft_printf("%20.15d\n", 54321);
//   ft_printf("%-10d\n", 3);
//   ft_printf("% d\n", 3);
//   ft_printf("%+d\n", 3);
//   ft_printf("%010d\n", 1);
//   return (0);
// }

