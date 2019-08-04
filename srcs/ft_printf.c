#include "ft_printf.h"

/* simply send last i symbols to show on screen: 0 - succesfully executed*/
int		display_buffer(const char **str, int i)
{
    if (i)
    {
        write(1, *str, (size_t)i);
        *str = *str + i;
    }
    return (i);
}

/* extracting paramter and displaying settings: returns amount of displayed symbols or 0. 0 means that error encountered while exctracting*/
int     display_parameter(const char **str, va_list ap)
{
    int         i;
    int			k;
    t_format    *format;

    if (!(format = (t_format *)ft_memalloc(sizeof(t_format))))
        return (0);
    if (!(format->length_flag = ft_strnew(2)))
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
    //printf ("format extracted. format->type = %c, format->flag = |%s|, format->width = %zu, format->precision = %zu\n", format->type, format->flag, format->width, format->precision);
    //printf ("format extracted. format->length_flag = %s\n", format->length_flag);
    if (!(k = combine_options(format, ap)))
        return (0);
    /*moving pointer to the index next to parameter type definition */
    *str = *str + i + 1;
    free(format->length_flag);
    free(format);
    return (k);
}  

/* project function: returns an amount of displayed symbols */
int     ft_printf(const char *str, ...)
{
    int     k;
    int     i;
    va_list ap;
    
    va_start(ap, str);
    i = 0;
    k = 0;
    while (str[i])
    {
        if (str[i] == '%' || i == 255)
            {
                k = k + display_buffer(&str, i);
                if (str[0] == '%')
                {
                    str++;
                    if (!(i = display_parameter(&str, ap)))
                        return (0);
                    k = k + i;
                }
                i = 0;
            }
        else
            i++;
    }
    k = k + i;
    display_buffer(&str, i);
    va_end(ap);
    return (k);
}