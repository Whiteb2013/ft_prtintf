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

	n = ft_printf("%C\n", 0x00D8);
	m = ft_printf("%S\n", str);
	printf("n = %d || m = %d\n", n, m);
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

