#include "ft_printf.h"

int		undefined_behavior(t_format *format)
{
	if (!(format->content.string2show = ft_strdup(&format->type)))
		return (0);
	format->length = ft_strlen(format->content.string2show);
	return (1);
}