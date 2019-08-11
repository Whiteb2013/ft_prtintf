#include "ft_printf.h"

int		apply_hash(t_format *format)
{
	if (format->flag.hash == 't')
	{
		if (format->type == 'x' || format->type == 'X')
		{
			if (!(format->content.string2show = join_prefix("0x", format->content.string2show, format)))
            	return (0);
		}
		else if (format->type == 'f' && format->precision == 0)
		{
			if (!(format->content.string2show = join_postfix(format->content.string2show, ".", format)))
            	return (0);
		}
		else if (format->type == 'o')
		{
			if (!(format->content.string2show = join_prefix("0", format->content.string2show, format)))
            	return (0);
		}
	}
	return (1);
}

int		apply_flags(t_format *format)
{
	if (!apply_hash(format))
		return (0);
	return (1);
}