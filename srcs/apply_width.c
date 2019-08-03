#include "ft_printf.h"

char	*apply_width(char *s, t_format *format)
{
	char	*filler_str;
	char	c;
	size_t	i;

	i = 0;
	c = ' ';
	if (!(filler_str = ft_strnew(format->width - format->length)))
		return (NULL);
	if (format->flag.zero == 't' && format->flag.minus == 'f')
		c = '0';
	while (i < format->width - format->length)
		filler_str[i++] = c;
	if (format->flag.minus == 't')
		s = join_strings (s, filler_str, format);
	else
		s = join_strings (filler_str, s, format);
	return (s);
}