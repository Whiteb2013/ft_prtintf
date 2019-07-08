#include "ft_printf.h"

/* simply send last i symbols to show on screen: 0 - succesfully executed*/
size_t  display_buffer(const char **str, size_t i)
{
    if (i)
    {
        write(1, *str, i);
        *str = *str + i;
    }
    return (0);
}

/* extracting paramter and displaying settings: 1 - ok, 0 - error encountered while exctracting*/
int     display_parameter(const char **str, va_list ap)
{
    int         i;
    t_format    *format;

    if (!(format = (t_format *)ft_memalloc(sizeof(t_format))))
        return (0);
    /*taking out parameter type: c, s, p, d, i, o, u, x, X or %. 
    Returning i < 0 if none of these types detected or type character index i value */
    if ((i = get_type(*str, format)) < 0)
        return (0);
    /*everything between current string index and i value is considered as list of optional parameters:
    flag, width, precision. Filling these values to t_format structure.
    if i = 0, then obviously no options, because type symbol is next to '%' */
    if (i)
        get_options(*str, format, i);
    /* this is just for testing. Printing to the display should be moved out to a separate function*/
    printf ("format extracted. format->type = %c, format->flag = |%s|, format->width = %zu, format->precision = %zu", format->type, format->flag, format->width, format->precision);
    // -> replace this on 10.07 with proper formatting of standard output stream. Following 2 rows are just for testing.
    if (format->type == '%')
        write(1, *str + i, 1);
    /*moving pointer to the index next to parameter type definition */
    *str = *str + i + 1;
    free(format);
    return (1);
}  

/* project function: 1 - successful processing, 0 - error encountered */
int     ft_printf(const char *str, ...)
{
    size_t  i;
    va_list ap;
    
    /*initializing list of undefinined arguments, man 3 stdarg */
    va_start(ap, str);
    i = 0;
    /*parsing string. Printing strings every 257 symbols or parsing parameter if '%' encountered.
    Made this way because amount of "write" calls should be reduced to minimum as the slowest bus calling operation */
    while (str[i])
    {
        if (str[i] == '%')
            {
                /* cleaning string buffer before parameter parsing */
                i = display_buffer(&str, i);
                str++;
                /* parsing parameter and displaying corresponding data */
                if (!display_parameter(&str, ap))
                    return (0);
            }
        else if (i == 256)
            i = display_buffer(&str, i);
        else
            i++;
    }
    /* in case if we get out from cycle with string in buffer less than 257 symbols */
    i = display_buffer(&str, i);
    va_end(ap);
    return (1);
}