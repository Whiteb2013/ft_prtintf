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
	// printf("std:%f", -0.0);
	// puts("");
	// ft_printf("cst:%f", -0.0);
	// puts("");
	// printf("std:%f", -0.0/0.0);
	// puts("");
	// ft_printf("cst:%f", -0.0/0.0);
	// puts("");
	// printf("std:%f", -0.123/0.0);
	// puts("");
	ft_printf("cst:%g", 0/0);
	puts("");
	ft_printf("cst:%g", 0/0);
	puts("");
	printf("std:%g", 0/0);
	puts("");
	printf("std:%g", 0/0);
	puts("");

	// printf("%f", RLIM_INFINITY);
	// puts("");
	// ft_printf("%f", RLIM_INFINITY);
	// puts("");
	// printf("%g", RLIM_INFINITY/RLIM_INFINITY);
	// puts("");
	// ft_printf("%g", RLIM_INFINITY/RLIM_INFINITY);
	// puts("");
	// printf("%d", -LONG_MAX);
	// puts("");
	// ft_printf("%d", -LONG_MAX);
	// puts("");
	// printf("%d", -INT_MAX);
	// puts("");
	// ft_printf("%d", -INT_MAX);
	// puts("");
	// printf("%d", -LONG_MIN);
	// puts("");
	// ft_printf("%d", -LONG_MIN);
	// puts("");
	// printf("%d", -INT_MIN);
	// puts("");
	// ft_printf("%d", -INT_MIN);
	// puts("");
	// printf("%.310g", RLIM_INFINITY/RLIM_INFINITY);
	// puts("");
	// ft_printf("%.310g", RLIM_INFINITY/RLIM_INFINITY);
	// puts("");
	return (0);
}
