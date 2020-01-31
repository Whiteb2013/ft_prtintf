#include <stdio.h>
#include "srcs/ft_printf.h"
#include <math.h>

//int ft_printf(const char *str, ...);

int main()
{
	printf("std:%.10g", 0.001);
	puts("");
	ft_printf("cst:%.10g", 0.001);
	puts("");
	printf("std:%.9g", 0.001);
	puts("");
	ft_printf("cst:%.9g", 0.001);
	puts("");
	printf("std:%.8g", 0.001);
	puts("");
	ft_printf("cst:%.8g", 0.001);
	puts("");
	printf("std:%.7g", -0.001);
	puts("");
	ft_printf("cst:%.7g", -0.001);
	puts("");
	printf("std:%#.7g", -0.001);
	puts("");
	ft_printf("cst:%#.7g", -0.001);
	puts("");
	printf("std:%2.7g", -0.001);
	puts("");
	ft_printf("cst:%2.7g", -0.001);
	puts("");
	printf("std:%#2.7g", -0.001);
	puts("");
	ft_printf("cst:%#2.7g", -0.001);
	puts("");
	printf("std:%.6g", 0.001);
	puts("");
	ft_printf("cst:%.6g", 0.001);
	puts("");
	printf("std:%.5g", 0.001);
	puts("");
	ft_printf("cst:%.5g", 0.001);
	puts("");
	printf("std:%.4g", 0.001);
	puts("");
	ft_printf("cst:%.4g", 0.001);
	puts("");
	printf("std:%.3g", 0.001);
	puts("");
	ft_printf("cst:%.3g", 0.001);
	puts("");
	printf("std:%.2g", 0.001);
	puts("");
	ft_printf("cst:%.2g", 0.001);
	puts("");
	printf("std:%.1g", 0.001);
	puts("");
	ft_printf("cst:%.1g", 0.001);
	puts("");
	printf("std:%.0g", 0.001);
	puts("");
	ft_printf("cst:%.0g", 0.001);
	puts("");
	printf("std:%#.6g", -1.0);
	puts("");
	ft_printf("cst:%#.6g", -1.0);
	puts("");
	printf("std:%.6g", -1.0);
	puts("");
	ft_printf("cst:%.6g", -1.0);
	puts("");
	printf("std:%g", -0.0);
	puts("");
	ft_printf("cst:%g", -0.0);
	puts("");
	printf("std:%.0g", -0.3);
	puts("");
	ft_printf("cst:%.0g", -0.3);
	puts("");
	printf("std:%.1g", 123456.6666666);
	puts("");
	ft_printf("cst:%.1g", 123456.6666666);
	puts("");
	printf("std:%.0g", 123456.6666666);
	puts("");
	ft_printf("cst:%.0g", 123456.6666666);
	puts("");
	printf("std:%.3g", 123456.6666666);
	puts("");
	ft_printf("cst:%.3g", 123456.6666666);
	puts("");
	printf("std:%#.0g", -1.0);
	puts("");
	ft_printf("cst:%#.0g", -1.0);
	puts("");
	printf("std:%.0g", -1.0);
	puts("");
	ft_printf("cst:%.0g", -1.0);
	puts("");
	printf("std:%.23g", 123456.6666666);
	puts("");
	ft_printf("cst:%.23g", 123456.6666666);
	puts("");
	printf("std:%.1g", -0.3);
	puts("");
	ft_printf("cst:%.1g", -0.3);
	puts("");
	printf("std:%.0g", 0.000887);
	puts("");
	ft_printf("cst:%.0g", 0.000887);
	puts("");
	printf("std:%.6g", 0.000887);
	puts("");
	ft_printf("cst:%.6g", 0.000887);
	puts("");
	printf("std:%g", 0.00000999);
	puts("");
	ft_printf("cst:%g", 0.00000999);
	puts("");
	printf("std:%.23g", 999364567890123456999000.6666666);
	puts("");
	ft_printf("cst:%.23g", 999364567890123456999000.6666666);
	puts("");
	printf("std:%.6g", -1.0);
	puts("");
	ft_printf("cst:%.6g", -1.0);
	puts("");
	printf("std:%+040.20g", 1.005);
	puts("");
	ft_printf("cst:%+040.20g", 1.005);
	puts("");
	printf("std:%.20g", 1.01);
	puts("");
	ft_printf("cst:%.20g", 1.01);
	puts("");
	printf("std:%.20g", 1.09);
	puts("");
	ft_printf("cst:%.20g", 1.09);
	puts("");
	printf("std:%.28g", 0.1);
	puts("");
	ft_printf("cst:%.28g", 0.1);
	puts("");
	printf("std:%.28g", 0.888);
	puts("");
	ft_printf("cst:%.28g", 0.888);
	puts("");
	printf("std:%.28g", 0.098765);
	puts("");
	ft_printf("cst:%.28g", 0.098765);
	puts("");
	printf("std:%.28g", 0.001);
	puts("");
	ft_printf("cst:%.28g", 0.001);
	puts("");
	printf("std:%.2g", 0.001);
	puts("");
	ft_printf("cst:%.2g", 0.001);
	puts("");
	printf("std:%.21g", 123123.6666666);
	puts("");
	ft_printf("cst:%.21g", 123123.6666666);
	puts("");
	printf("std:%.20g", 1.1236666666);
	puts("");
	ft_printf("cst:%.20g", 1.1236666666);
	puts("");
	printf("std:%#10.6g", 1.123/0);
	puts("");
	ft_printf("cst:%#10.6g", 1.123/0);
	puts("");
	printf("std:%#10.6g", -1.123/0);
	puts("");
	ft_printf("cst:%#10.6g", -1.123/0);
	puts("");
	printf("std:%g", 123.123);
	puts("");
	ft_printf("cst:%g", 123.123);
	puts("");
	printf("std:%g", -123.123);
	puts("");
	ft_printf("cst:%g", -123.123);
	puts("");
	printf("std:%#.0g", 123.123);
	puts("");
	ft_printf("cst:%#.0g", 123.123);
	puts("");
	printf("std:%g", -123.123);
	puts("");
	ft_printf("cst:%g", -123.123);
	puts("");
	printf("std:%g", -0.98);
	puts("");
	ft_printf("cst:%g", -0.98);
	puts("");
	return (0);
}
