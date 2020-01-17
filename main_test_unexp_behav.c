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
	printf("%jlx", 4294967295);
	puts("");
	ft_printf("%jlx", 4294967295);
	puts("");
	return (0);
}
