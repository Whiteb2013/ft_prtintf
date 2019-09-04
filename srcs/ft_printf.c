#include "ft_printf.h"

/* extracting paramter and displaying settings: returns amount of displayed symbols or 0. 0 means that error encountered while exctracting*/
int     extract_parameter(const char **str, va_list ap, va_list ap_root)
{
	int         i;
	int			k;
	t_format    *format;

	//*format->ap_root = *ap;
	//printf("\nva_arg = %i\n", va_arg(format->ap_root, int));

	*str = *str + 1;
	if (!(format = (t_format *)ft_memalloc(sizeof(t_format))))
		return (0);
	if ((i = get_type(*str, format, ap_root)) < 0)
		return (cleaner (format));
	if (check_type(format->type))
	{
		get_options(*str, format, ap, ap_root, i);
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

int		ft_strcmp_second_son(const char *s1, const char *s2, size_t i)
{
	while ((*(unsigned char *)s1++ == *(unsigned char *)s2) && i > 0)
	{
		if (*(s2++) == 0)
			return (0);
		i--;
	}
	return (*(unsigned char *)--s1 - *(unsigned char *)s2);
}

void	set_color(const char *color, const char **str, int i)
{
	write(1, color, ft_strlen(color));
    *str = *str + i;
}

void	check_color(const char **str)
{
	if (!ft_strncmp(*str, "{red}", 5))
	{
		// write(1, "\033[22;31m", (size_t)8);
        // *str = *str + 5;
		set_color("\033[22;31m", str, 5);
		//puts("OK");
	}
	else
	{
	 	display_static_buffer(str, 1);
		//write(1, "{", (size_t)1);
        //*str = *str + 1;
	}
}

/* project function: returns an amount of displayed symbols */
int     ft_printf(const char *str, ...)
{
	int     k;
	int     i;
	va_list ap;
	va_list	ap_root;
	//va_list	ap2;
	
	va_start(ap, str);
	*ap_root = *ap;
	i = 0;
	k = 0;
	while (str[i])
	{
		if (str[i] == '%' || str[i] == '{' || i == 255)
			{
				k = k + display_static_buffer(&str, i);
				if (str[0] == '{')
					check_color(&str);
				//puts(str);
				if (str[0] == '%')
				{
					if ((i = extract_parameter(&str, ap, ap_root)) < 0)
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