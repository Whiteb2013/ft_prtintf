#include "ft_printf.h"

/* extracting paramter and displaying settings: returns amount of displayed symbols or 0. 0 means that error encountered while exctracting*/
int     extract_parameter(const char **str, va_list ap)
{
	int         i;
	int			k;
	t_format    *format;

	*str = *str + 1;
	if (!(format = (t_format *)ft_memalloc(sizeof(t_format))))
		return (0);
	if ((i = get_type(*str, format)) < 0)
		return (cleaner (format));
	if (check_type(format->type))
	{
		get_options(*str, format, ap, i);
	//printf ("format extracted. format->type = %c, format->flag = |%s|, format->width = %zu, format->precision = %zu\n", format->type, format->flag, format->width, format->precision);
		if (!convert2string(format, ap))
			return (cleaner (format));
		if (!format_string(format))
			return (cleaner (format));
	}
	else if (!undefined_behavior(format))
		return (cleaner (format));
	k = display_parameter_buffer(format);
	*str = *str + i;
	if (**str)
		*str = *str + 1;
	cleaner (format);
	return (k);
}  

/* project function: returns an amount of displayed symbols */
int     ft_printf(const char *str, ...)
{
	int     k;
	int     i;
	va_list ap;
	
	va_start(ap, str);
	i = 0;
	k = 0;
	while (str[i])
	{
		if (str[i] == '%' || i == 255)
			{
				k = k + display_static_buffer(&str, i);
				if (str[0] == '%')
				{
					if ((i = extract_parameter(&str, ap)) < 0)
					{
						va_end(ap);
						return (-1);
					}
					k = k + i;
				}
				i = 0;
			}
		else
			i++;
	}
	k += i;
	display_static_buffer(&str, i);
	va_end(ap);
	return (k);
}