#include "ft_printf.h"

/* simply send last i symbols to show on screen: 0 - succesfully executed*/
int		display_static_buffer(const char **str, int i)
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

    *str = *str + 1;
    if (!(format = (t_format *)ft_memalloc(sizeof(t_format))))
        return (0);
    if (!(format->length_flag = ft_strnew(2)))
        return (0);
    if ((i = get_type(*str, format)) < 0)
        return (0);
    if (i)
        get_options(*str, format, ap, i);
    //printf ("format extracted. format->type = %c, format->flag = |%s|, format->width = %zu, format->precision = %zu\n", format->type, format->flag, format->width, format->precision);
    if (!(k = combine_options(format, ap)))
        return (0);
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
                k = k + display_static_buffer(&str, i);
                if (str[0] == '%')
                {
                    if (!(i = display_parameter(&str, ap)))
                        return (-1);
                    k = k + i;
                }
                i = 0;
            }
        else
            i++;
    }
    k = k + i;
    display_static_buffer(&str, i);
    va_end(ap);
    return (k);
}