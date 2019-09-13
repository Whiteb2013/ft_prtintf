#include <stdio.h>
#include "ft_printf.h"
#include <wchar.h>
#include <locale.h>

int main()
{
	int str[8] = {0x00D8, 0x06D1, 0x00D8, 0x06D1, 0x00D8, 0x06D1, 0x00D8, 0};
	setlocale(LC_ALL, "en_US.UTF-8");
	int n, m;
	int j = 0;

	//printf("test || %.0s\n", "abcd");
	n = ft_printf("%C\n", 0x00D8);
	m = ft_printf("p9 %.9S\n", str);
	m = ft_printf("p8 %.8S\n", str);
	m = ft_printf("p7 %.7S\n", str);
	m = ft_printf("p6 %.6S\n", str);
	m = ft_printf("p5 %.5S\n", str);
	m = ft_printf("p4 %.4S\n", str);
	m = ft_printf("p3 %.3S\n", str);
	m = ft_printf("p2 %.2S\n", str);
	m = ft_printf("p1 %.1S\n", str);
	m = ft_printf("p0 %.0S\n", str);
	printf("len(C) = %d\nlen(S) = %d\n", n, m);
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

