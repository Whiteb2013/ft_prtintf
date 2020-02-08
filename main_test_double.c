#include <stdio.h>
#include "srcs/ft_printf.h"
#include <math.h>

//int ft_printf(const char *str, ...);

int main()
{
	printf("{%f}{%lf}{%Lf}", -1444565444646.6465424242242, -1444565444646.6465424242242, -1444565444646.6465424242242l);
	puts("");
	ft_printf("{%f}{%lf}{%Lf}", -1444565444646.6465424242242, -1444565444646.6465424242242, -1444565444646.6465424242242l);
	puts("");
	printf("{%f}{%lf}{%Lf}", 1.42, 1.42, 1.42l);
	puts("");
	ft_printf("{%f}{%lf}{%Lf}", 1.42, 1.42, 1.42l);
	puts("");
	printf("{%f}{%lf}{%Lf}", -1.42, -1.42, -1.42l);
	puts("");
	ft_printf("{%f}{%lf}{%Lf}", -1.42, -1.42, -1.42l);
	puts("");
	printf("{%f}{%lf}{%Lf}", 1444565444646.6465424242242, 1444565444646.6465424242242, 1444565444646.6465424242242l);
	puts("");
	ft_printf("{%f}{%lf}{%Lf}", 1444565444646.6465424242242, 1444565444646.6465424242242, 1444565444646.6465424242242l);
	puts("");
	printf("{%f}{%lf}{%Lf}", -1444565444646.6465424242242, -1444565444646.6465424242242, -1444565444646.6465424242242l);
	puts("");
	ft_printf("{%f}{%lf}{%Lf}", -1444565444646.6465424242242, -1444565444646.6465424242242, -1444565444646.6465424242242l);
	puts("");
	printf("std:%.20f", 1.005);
	puts("");
	ft_printf("cst:%.20f", 1.005);
	puts("");
	printf("std:%.6f", -1.0);
	puts("");
	ft_printf("cst:%.6f", -1.0);
	puts("");
	printf("std:%.6f", -0.001);
	puts("");
	ft_printf("cst:%.6f", -0.001);
	puts("");
	printf("std:%.23f", 999364567890123456999000.6666666);
	puts("");
	ft_printf("cst:%.23f", 999364567890123456999000.6666666);
	puts("");
	printf("std:%f", -0.0);
	puts("");
	ft_printf("cst:%f", -0.0);
	puts("");
	printf("std:%.20f", 1.01);
	puts("");
	ft_printf("cst:%.20f", 1.01);
	puts("");
	printf("std:%.20f", 1.09);
	puts("");
	ft_printf("cst:%.20f", 1.09);
	puts("");
	printf("std:%.28f", 0.1);
	puts("");
	ft_printf("cst:%.28f", 0.1);
	puts("");
	printf("std:%.28f", 0.888);
	puts("");
	ft_printf("cst:%.28f", 0.888);
	puts("");
	printf("std:%.28f", 0.098765);
	puts("");
	ft_printf("cst:%.28f", 0.098765);
	puts("");
	printf("std:%.28f", 0.001);
	puts("");
	ft_printf("cst:%.28f", 0.001);
	puts("");
	printf("std:%.6f", 0.000887);
	puts("");
	ft_printf("cst:%.6f", 0.000887);
	puts("");
	printf("std:%f", 0.00000999);
	puts("");
	ft_printf("cst:%f", 0.00000999);
	puts("");
	printf("std:%.21f", 123123.6666666);
	puts("");
	ft_printf("cst:%.21f", 123123.6666666);
	puts("");
	printf("std:%.20f", 1.1236666666);
	puts("");
	ft_printf("cst:%.20f", 1.1236666666);
	puts("");
	printf("std:%#10.6f", 1.123/0);
	puts("");
	ft_printf("cst:%#10.6f", 1.123/0);
	puts("");
	printf("std:%f", 123.123);
	puts("");
	ft_printf("cst:%f", 123.123);
	puts("");
	printf("std:%f", -123.123);
	puts("");
	ft_printf("cst:%f", -123.123);
	puts("");
	printf("std:%#.0f", 123.123);
	puts("");
	ft_printf("cst:%#.0f", 123.123);
	puts("");
	printf("std:%f", -123.123);
	puts("");
	ft_printf("cst:%f", -123.123);
	puts("");
	printf("std:%.20f", 123456.6666666);
	puts("");
	ft_printf("cst:%.20f", 123456.6666666);
	puts("");
	printf("std:%f", -0.98);
	puts("");
	ft_printf("cst:%f", -0.98);
	puts("");
	return (0);
}
