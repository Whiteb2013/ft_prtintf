#include "ft_printf.h"

int		convert_string2string(t_format *format, char *s)
{
	if (format->precision_flag == 't' && !(format->content.string2show = apply_precision_string(s, format)))
		return (0);
	return (1);
}

int		convert_char2string(t_format *format, int a)
{   
    if (!(format->content.string2show = ft_strnew(1)))
        return (0);
    format->content.string2show[0] = (unsigned char)a;
	return (1);
}

int     convert_int2string(t_format *format, long long int a, size_t base)
{
    unsigned long long int  b;

    if (a < 0)
    {
		format->content.sign = '-';
		b = -a;
    }
    else
        b = a;
    format->content.string2show = ft_itoa_base(b, base, format->content.string2show);
    if (format->precision_flag == 't' && !(format->content.string2show = apply_precision_int(format->content.string2show, format)))
		return (0);
    return (1);
}

int		convert_pointer2string(t_format *format, long long int a)
{
	if (!convert_int2string(format, a, 16))
		return (0);
	if (!(format->content.string2show = join_prefix("0x", format->content.string2show, format)))
        return (0);
	return (1);
}

int		convert_float2string(t_format *format, double a)
{
	long long int   integer;
    long long int   decimal;
    char			*temp_str;

    /* var "integer" contains everything before separator, var "decimal" contains everything after separator */
    integer = (long long int)a;
	if (a < 0)
	{
        decimal = get_decimal(format->precision, -(a - integer), &integer);
		format->content.sign = '-';
	}
	else
        decimal = get_decimal(format->precision, a - integer, &integer);
    if (format->precision)
	    if (!(temp_str = apply_precision_float(ft_itoa_base(decimal, 10, temp_str), format)))
            return (0);
	if (!(format->content.string2show = join_strings(ft_itoa_base(integer, 10, format->content.string2show), temp_str, format)))
		return (0);
	return (1);
}

int     convert2string(t_format *format, va_list ap)
{
	if (format->type == '%')
        return (convert_char2string(format, '%'));
    else if (format->type == 'c')
        return (convert_char2string(format, va_arg(ap, int)));
    else if (format->type == 's')
        return (convert_string2string(format, va_arg(ap, char *)));
    else if (format->type == 'p')
        return (convert_pointer2string(format, va_arg(ap, long long int)));
    else if (format->type == 'd' || format->type == 'i')
        return (convert_int2string(format, va_arg(ap, int), 10));
    else if (format->type == 'x' || format->type == 'X')
        return (convert_int2string(format, va_arg(ap, unsigned int), 16));
    else if (format->type == 'o')
    	return (convert_int2string(format, va_arg(ap, unsigned int), 8));
    else if (format->type == 'u')
		return (convert_int2string(format, va_arg(ap, unsigned int), 10));
	else if (format->type == 'f')
        return (convert_float2string(format, va_arg(ap, double)));
    return (0);
}