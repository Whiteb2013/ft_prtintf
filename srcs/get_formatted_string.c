#include "ft_printf.h"

int		format_string(t_format *format)
{
	int i;
	
	i = -1;
	format->length = ft_strlen(format->content.string2show);
	if (!apply_flags(format))
		return (0);
	if (format->length < format->width)
		if (!(format->content.string2show = apply_width(format->content.string2show, format)))
			return (0);
	if (format->type >= 'A' && format->type <= 'Z')
        while (format->content.string2show[++i])
            format->content.string2show[i] = ft_toupper(format->content.string2show[i]);
	return (1);
}