#include "ft_printf.h"

char	*apply_precision_string(char *s, t_format *format)
{
	format->length = ft_strlen(s);
	if (format->length > format->precision)
		if (!(s = ft_strndup(s, format->precision)))
			return (NULL);
	format->length = ft_strlen(s);
	return (s);
}

char	*apply_precision_int(char *s, t_format *format)
{
	char	*filler_str;
	size_t	i;

	i = 0;
	format->length = ft_strlen(s);
	if (format->length < format->precision)
	{
		if (!(filler_str = ft_strnew(format->precision - format->length)))
			return (NULL);
		while (i < format->precision - format->length)
			filler_str[i++] = '0';
		s = join_strings (filler_str, s, format);
	}
	return (s);
}

char	*apply_precision(char *s, t_format *format)
{
	format->length = ft_strlen(s);
	if (format->type == 's')
		s = apply_precision_string (s, format);
	if (format->type == 'i' || format->type == 'd' || format->type == 'o' || format->type == 'x' || format->type == 'X' || format->type == 'p')
		s = apply_precision_int (s, format);
	return (s);
}