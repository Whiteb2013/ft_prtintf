#include "ft_printf.h"

char    *ft_itoa_base(unsigned long long int2convert, size_t base)
{
    char    *str;
    size_t	i;
    char	values[16] = "0123456789abcdef";
    
    printf("\nint2convert = %i\n", int2convert);
    i = int_length(int2convert, base);
    if (!(str = ft_strnew(i)))
        return (NULL);
    str[i] = '\0';
    while (int2convert / base)
    {
        str[--i] = values[int2convert % base];
        int2convert = int2convert / base;
    }
    str[--i] = values[int2convert % base];
    printf("\nstr = %s\n", str);
    return (str);
}