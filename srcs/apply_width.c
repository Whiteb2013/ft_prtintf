#include "ft_printf.h"

int		apply_width(t_format *format)
{
	char	*filler_str;
	char	c;
	size_t	i;

	i = 0;
	c = ' ';
	if (format->type == 'c')
		format->length = 1;
	if (format->length < format->width)
	{
		if (!(filler_str = ft_strnew(format->width - format->length)))
			return (0);
		if (format->flag.zero == 't' && format->flag.minus == 'f' && format->type != 'c')
			c = '0';
		while (i < format->width - format->length)
			filler_str[i++] = c;
		if (format->flag.minus == 't')
			format->content.string2show = join_strings (format->content.string2show, filler_str, format);
		else
			format->content.string2show = join_strings (filler_str, format->content.string2show, format);
		format->length = format->width;
	}
	return (1);
}