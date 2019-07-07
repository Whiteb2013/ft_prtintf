#include "ft_printf.h"
#include <stdio.h>

size_t  display_buffer(const char **str, size_t i)
{
    write(1, *str, i);
    *str = *str + i;
    return (0);
}

int     display_parameter(const char **str, va_list ap)
{
    const char  *temp;
    int         i;
    t_format    *format;

    if (!(format = (t_format *)ft_memalloc(sizeof(t_format))))
        return (0);
    if ((i = get_type(*str, format)) < 0)
        return (0);
    //get_options(*str, i, format);
    //printf("Detected values. i = %d, type = %c", i, format->type);
    //this is just for testing. Printing '%' and moving pointer further the string
    if (format->type == '%')
        write(1, *(str + i), 1);
    *str = *str + i + 1;
    return (1);
}  

int     ft_printf(const char *str, ...)
{
    size_t  i;
    va_list ap;
    
    va_start(ap, str);
    i = 0;
    while (str[i])
    {
        if (str[i] == '%')
            {
                if (i)
                    i = display_buffer(&str, i);
                str++;
                if (!display_parameter(&str, ap))
                    return (0);
            }
        else if (i == 256)
            i = display_buffer(&str, i);
        else
            i++;
    }
    display_buffer(&str, i);
    va_end(ap);
    return (1);
}