#include <stdio.h>
#include "srcs/ft_printf.h"
#include <wchar.h>
#include <locale.h>

#define ULONG_MAX 0xFFFFFFFFUL

int main()
{
	int str[8] = {0x00D8, 0x06D1, 0x00D8, 0x06D1, 0x00D8, 0x06D1, 0x00D8, 0};
	int str2[4] = {0x00D8, 0x06D1, 0x00D8, 0};
	setlocale(LC_ALL, "en_US.UTF-8");
	int n, m;
	int a, b, c, d, e, f;
	int j = 0;

	// m = printf("%010.5s", "abcdefg");
	// printf(" || m = %d\n", m);
	// m = printf("%05.10s", "abcdefg");
	// printf(" || m = %d\n", m);
	// m = printf("%010.5c", 'c');
	// printf(" || m = %d\n", m);
	// m = printf("%05.10c", 'c');
	// printf(" || m = %d\n", m);
	// puts("");

	// m = ft_printf("%010.5s", "abcdefg");
	// printf(" || m = %d\n", m);
	// m = ft_printf("%05.10s", "abcdefg");
	// printf(" || m = %d\n", m);
	// m = ft_printf("%010.5c", 'c');
	// printf(" || m = %d\n", m);
	// m = ft_printf("%05.10c", 'c');
	// printf(" || m = %d\n", m);
	// puts("");

	// m = ft_printf("%010.5S", str);
	// printf(" || m = %d\n", m);
	// m = ft_printf("%05.10S", str);
	// printf(" || m = %d\n", m);
	// m = ft_printf("%010.5C", 0x00D8);
	// printf(" || m = %d\n", m);
	// m = ft_printf("%05.10C", 0x00D8);
	// printf(" || m = %d\n", m);

	// m = ft_printf("%010.5C", 0x00D8);
	// printf(" || m = %d\n", m);
	// m = ft_printf("%05.10C", 0x00D8);
	// printf(" || m = %d\n", m);
	// puts("");

// mouli test40
	// m =    printf("%lo, %lo", 0ul, ULONG_MAX);
	// printf(" || m = %d\n", m);
	// m = ft_printf("%lo, %lo", 0ul, ULONG_MAX);
	// printf(" || m = %d\n", m);
	// puts("");

	// m =    printf("%lx, %lx", 0ul, ULONG_MAX);
	// printf(" || m = %d\n", m);
	// m = ft_printf("%lx, %lx", 0ul, ULONG_MAX);
	// printf(" || m = %d\n", m);
	// puts("");

	// m =    printf("%lX, %lX", 0ul, ULONG_MAX);
	// printf(" || m = %d\n", m);
	// m = ft_printf("%lX, %lX", 0ul, ULONG_MAX);
	// printf(" || m = %d\n", m);
	// puts("");
//

// mouli wildcard
	// m = printf("%-3c", 0);
	m = ft_printf("%-3c", 0);
	// m =    printf("%-2c\n", 0);
	// m = ft_printf("%-2c\n", 0);
	puts("");

	// m =    printf("{%*c}", -15, 0);
	// // printf(" || m = %d\n", m);
	// m = ft_printf("{%*c}", -15, 0);
	// // printf(" || m = %d\n", m);
	// puts("");

	// m =    printf("{%*c}", -15, '0');
	// // printf(" || m = %d\n", m);
	// m = ft_printf("{%*c}", -15, '0');
	// // printf(" || m = %d\n", m);
	// puts("");

	// m =    printf("{%*c}", -15, 'a');
	// printf(" || m = %d\n", m);
	// m = ft_printf("{%*c}", -15, 'a');
	// printf(" || m = %d\n", m);
	// puts("");

	// m =    printf("{%05.*d}", -15, 42);
	// printf(" || m = %d\n", m);
	// m = ft_printf("{%05.*d}", -15, 42);
	// printf(" || m = %d\n", m);
	// puts("");

	// m =    printf("{%05.*d}", -15, 42);
	// printf(" || m = %d\n", m);
	// m = ft_printf("{%05.*d}", -15, 42);
	// printf(" || m = %d\n", m);
	// puts("");

	// m =    printf("{%05.20.-15d}", 42);
	// printf(" || m = %d\n", m);
	// m = ft_printf("{%05.20.-15d}", 42);
	// printf(" || m = %d\n", m);
	// puts("");
//

	// m = ft_printf("%C", 0x00D8);
	// printf(" || m = %d\n", m);
	// m = ft_printf("%C", 217);
	// printf(" || m = %d\n", m);
	// puts("");
	// m = ft_printf("p9 %.9S", str);
	// printf(" || m = %d\n", m);
	// m = ft_printf("p8 %.8S", str);
	// printf(" || m = %d\n", m);
	// m = ft_printf("p7 %.7S", str);
	// printf(" || m = %d\n", m);
	// m = ft_printf("p6 %.6S", str);
	// printf(" || m = %d\n", m);
	// m = ft_printf("p5 %.5S", str);
	// printf(" || m = %d\n", m);
	// m = ft_printf("p4 %.4S", str);
	// printf(" || m = %d\n", m);
	// m = ft_printf("p3 %.3S", str);
	// printf(" || m = %d\n", m);
	// m = ft_printf("p2 %.2S", str);
	// printf(" || m = %d\n", m);
	// m = ft_printf("p1 %.1S", str);
	// printf(" || m = %d\n", m);
	// m = ft_printf("p0 %.0S", str);
	// printf(" || m = %d\n", m);

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

	//    n = printf("std: {%0 3d}\n", 0);
	// m = ft_printf("ft_: {%0 3d}\n", 0);
	//printf("\nn = %i\nm = %i\n", n ,m);

	// n = printf("green");
	// m = ft_printf("{green}green{eoc}");
	// printf("\nn = %i\nm = %i\n", n ,m);
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

