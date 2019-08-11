#include "ft_printf.h"

int		format_string(t_format *format)
{
	int i;
	
	i = -1;
	if (format->precision_flag == 't' && !apply_precision(format))
		return (0);
	if (!apply_flags(format))
		return (0);
	if (!apply_width(format))
		return (0);
	if (format->type >= 'A' && format->type <= 'Z')
        while (format->content.string2show[++i])
            format->content.string2show[i] = ft_toupper(format->content.string2show[i]);
	return (1);
}