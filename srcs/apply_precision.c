#include "ft_printf.h"

int		apply_precision_string(t_format *format)
{
	if (format->length > format->precision)
		if (!(format->content.string2show = ft_strndup(format->content.string2show, format->precision)))
			return (0);
	return (1);
}

int		apply_precision_int(t_format *format)
{
	char	*filler_str;
	size_t	i;

	i = 0;
	//printf("\n|Length = %zu, precision = %zu|\n", format->length, format->precision);
	if (format->length < format->precision)
	{
		if (!(filler_str = ft_strnew(format->precision - format->length)))
			return (0);
		while (i < format->precision - format->length)
			filler_str[i++] = '0';
		format->content.string2show = join_strings (filler_str, format->content.string2show, format);
	}
	if (!format->precision && !ft_strcmp(format->content.string2show, "0"))
		ft_strclr(format->content.string2show);
	format->flag.zero = 'f';
	return (1);
}

int		apply_precision_float(t_format *format)
{
	format->length = ft_strlen(format->content.string2show);
	if (!apply_precision_int(format))
		return (0);
	if (!(format->content.string2show = join_prefix(".", format->content.string2show, format)))
		return (0);
	return (1);
}

int		apply_precision(t_format *format)
{
	if (format->type == 's' && !apply_precision_string(format))
		return (0);
	if (format->type == 'i' || format->type == 'd' || format->type == 'o' || format->type == 'x' || format->type == 'X' || format->type == 'u' || format->type == 'p')
		if (!apply_precision_int(format))
			return (0);
	format->length = ft_strlen(format->content.string2show);
	return (1);
}