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

int		display_parameter_buffer(t_format *format)
{
    write (1, format->content.string2show, format->length);
	return ((int)format->length);
}