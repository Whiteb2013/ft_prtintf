#include <stdio.h>
#include "ft_printf.h"

int ft_printf(const char *str, ...);

int main()
{
    puts("test1");
    puts("printf");
    printf("%d", 1);
    puts("");
    puts("ft_printf");
    ft_printf("%d", 1);
    puts("");
    puts("");
//   CHK_FT_PRINTF_LIST+=("d" "%4.15d|42")
//   CHK_FT_PRINTF_LIST+=("d" "%.2d|4242")
//   CHK_FT_PRINTF_LIST+=("d" "%.10d|4242")
//   CHK_FT_PRINTF_LIST+=("d" "%10.5d|4242")
//   CHK_FT_PRINTF_LIST+=("d" "%-10.5d|4242")
//   CHK_FT_PRINTF_LIST+=("d" "% 10.5d|4242")
//   CHK_FT_PRINTF_LIST+=("d" "%+10.5d|4242")
//   CHK_FT_PRINTF_LIST+=("d" "%-+10.5d|4242")
//   CHK_FT_PRINTF_LIST+=("d" "%03.2d|0")
//   CHK_FT_PRINTF_LIST+=("d" "%03.2d|1")
//   CHK_FT_PRINTF_LIST+=("d" "%03.2d|-1")
//   CHK_FT_PRINTF_LIST+=("d" "@moulitest: %.10d|-42")
//   CHK_FT_PRINTF_LIST+=("d" "@moulitest: %.d %.0d|42|43")
//   CHK_FT_PRINTF_LIST+=("d" "@moulitest: %.d %.0d|0|0")
//   CHK_FT_PRINTF_LIST+=("d" "@moulitest: %5.d %5.0d|0|0")

    return (0);
}