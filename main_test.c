#include <stdio.h>
#include "srcs/ft_printf.h"
#include <wchar.h>
#include <locale.h>
#include <limits.h>

// #define ULONG_MAX 0xFFFFFFFFUL
// #define ULLONG_MAX 18446744073709551615ULL
// #define SHRT_MAX 32767


int main()
{
	int str[8] = {0x00D8, 0x06D1, 0x00D8, 0x06D1, 0x00D8, 0x06D1, 0x00D8, 0};
	int str2[4] = {0x00D8, 0x06D1, 0x00D8, 0};
	setlocale(LC_ALL, "en_US.UTF-8");
	int n, m;
	int a, b, c, d, e, f;
	int j = 0;

	// printf("%hhx\n", UCHAR_MAX + 42);
	// ft_printf("%hhx\n", UCHAR_MAX + 42);

	// printf("%hhx\n", UCHAR_MAX + 1);
	// ft_printf("%hhx\n", UCHAR_MAX + 1);

	// printf("%hhx\n", UCHAR_MAX);
	// ft_printf("%hhx\n", UCHAR_MAX);

	// printf("%hhx\n", UCHAR_MAX - 42);
	// ft_printf("%hhx\n", UCHAR_MAX - 42);

	// printf("%o, %ho, %hho\n", -42, -42, -42);
	// ft_printf("%o, %ho, %hho\n", -42, -42, -42);

	// printf("%hhu, %hhu\n", 0, UCHAR_MAX);
	// ft_printf("%hhu, %hhu\n", 0, UCHAR_MAX);

	// printf("%hu, %hu\n", 0, USHRT_MAX);
	// ft_printf("%hu, %hu\n", 0, USHRT_MAX);

	// printf("%hhu / %hhu\n", SHRT_MAX - 42, SHRT_MAX - 4200);
	// ft_printf("%hhu / %hhu\n", SHRT_MAX - 42, SHRT_MAX - 4200);

	// printf("{%f}\n{%lf}\n{%Lf}\n", -1444565444646.6465424242242454654, -1444565444646.6465424242242454654, -1444565444646.6465424242242454654l);
	// ft_printf("{%f}\n{%lf}\n{%Lf}\n", -1444565444646.6465424242242454654, -1444565444646.6465424242242454654, -1444565444646.6465424242242454654l);

	// m = printf("{%f}{%lf}{%Lf}", 1.42, 1.42, 1.42l);
	// printf(" || m = %d\n", m);
	// m = ft_printf("{%f}{%lf}{%Lf}", 1.42, 1.42, 1.42l);
	// printf(" || m = %d\n", m);

	// m = printf("{%f}\n{%lf}\n{%Lf}\n", 1444565444646.6465424242242, 1444565444646.6465424242242, 1444565444646.6465424242242l);
	// printf(" || m = %d\n", m);
	// m = ft_printf("{%f}\n{%lf}\n{%Lf}\n", 1444565444646.6465424242242, 1444565444646.6465424242242, 1444565444646.6465424242242l);
	// printf(" || m = %d\n", m);

	// printf("%llo\n", ULLONG_MAX);
	// ft_printf("%llo\n", ULLONG_MAX);

	// printf("%.0p, %.p\n", 0, 0);
	// printf("std: {%*c}\n", -3, 0);
	// // printf("%.p\n", 0, 0);
	// // ft_printf("%.0p, %.p\n", 0, 0);
	// ft_printf("ft_: {%*c}\n", -3, 0);
	// ft_printf("%.p\n", 0, 0);
	//printf("{%-15c}\n", 0);

	// puts("");

	// printf("%.5p\n", 0);
	// ft_printf("%.5p\n", 0);

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
	// m = ft_printf("%-3c", 0);
	// m =    printf("%-2c\n", 0);
	// m = ft_printf("%-2c\n", 0);
	//puts("");

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

	ft_printf("ft_: %.3S -\n", str2);

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

