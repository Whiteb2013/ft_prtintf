#include "ft_printf.h"

char    *ft_itoa_base(size_t b, size_t base, t_format *format, char *str)
{
    size_t	i;
    char	values[16] = "0123456789abcdef";
    
    i = format->length;
    str[i] = '\0';
    while (b / base)
    {
        str[--i] = values[b % base];
        b = b / base;
    }
    str[--i] = values[b % base];
    return (str);
}