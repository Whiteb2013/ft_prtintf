#include "ft_printf.h"

int		cleaner(t_format *format)
{
	if (format)
	{
		if (format->content.string2show)
			free(format->content.string2show);
		if (format->length_flag)
			free(format->length_flag);
		free(format);
	}
	return (-1);
}