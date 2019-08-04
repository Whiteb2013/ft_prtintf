#include "ft_printf.h"

char	*apply_hash(char *s, t_format *format)
{
	if (format->flag.hash == 't')
	{
		if (format->type == 'x' || format->type == 'X')
		{
			if (!(s = join_prefix("0x", s, format)))
            	return (NULL);
		}
		else if (format->type == 'f' && format->precision == 0)
		{
			if (!(s = join_postfix(s, ".", format)))
            	return (NULL);
		}
		else if (format->type == 'o')
		{
			if (!(s = join_prefix("0", s, format)))
            	return (NULL);
		}
	}
	return (s);
}

char	*apply_flags(char *s, t_format *format)
{
	s = apply_hash(s, format);
	return (s);
}