#include <stdio.h>
#include "ft_printf.h"



int main()
{
    //exceptions to handle
	printf("%f", -0.0);
	puts("");
	ft_printf("%e", -1010.23456789);
	puts("");
	printf("%.20Lf", 101010.9999999L);
	puts("");
	ft_printf("%.20Lf", 101010.9999999L);
	puts("");
	printf("%f", +0.0);
	puts("");
	printf("%f", (double)1010/0);
	puts("");
	//

	printf("%e", 1010.23456789);
	puts("");
	printf("%E", 1010.23456789);
	puts("");
	printf("%#.0e", (double)-1010);
	puts("");
	printf("%e", -1010.23456789);
	puts("");
	printf("%.0e", -1010.23456789);
	puts("");
	printf("%10.10e", 101.23456789);
	puts("");
	printf("% 020.20e", 101.23456789);
    puts("");
	printf("% 020e", 101.23456789);
    puts("");
	printf("% -20e", 101.23456789);
    puts("");
	printf("% -20e", 10111111111111112312412.2345678912412412412421);
    puts("");
	printf("%g", 1010.23456789);
	puts("");
	printf("%g", -1010.23456789);
	puts("");
	printf("%.0g", -1010.23456789);
	puts("");
	printf("%10.10g", 101.23456789);
	puts("");
	printf("% 020.20g", 101.23456789);
    puts("");
	printf("% 020g", 101.23456789);
    puts("");
	printf("% -20g", 101.23456789);
    puts("");
	printf("% -20g", 10111111111111112312412.2345678912412412412421);
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

