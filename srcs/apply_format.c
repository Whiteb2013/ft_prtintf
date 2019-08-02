#include "ft_printf.h"

int		convert2string(t_format *format, char *s)
{
    format->length = ft_strlen(s);
    if (format->length < format->width)
		s = apply_width(s, format);
    write (1, s, format->length);
	return ((int)format->length);    
}

int		convert2char(t_format *format, int a)
{
    char	*str;
    int		i;
    
    if (!(str = ft_strnew(1)))
        return (0);
    str[0] = (unsigned char)a;
    i = convert2string(format, str);
    //issue to resolve later: str will cause a leak in case of no padding
	//free (str);
	return (i);
}

int     convert2int(t_format *format, long long int a, size_t base)
{
    char                    *str;
    size_t                  sign;
    unsigned long long int  b;
	int						i;

    sign = 0;
    if (a < 0)
    {
        b = -a;
        sign = 1;
    }
    else
        b = a;
    format->length = int_length(b, base) + sign;
    if (!format->length || !(str = ft_strnew(format->length)))
        return (0);
    str = ft_itoa_base(b, base, format, str);
    if (sign)
        str[0] = '-';
    if (format->type == 'p')
        if (!(str = join_prefix("0x", str, format)))
            return (0);
    i = convert2string(format, str);
    //issue to resolve later: str will cause a leak in case of no padding
	//free (str);
    return (i);
}

int		convert2float(t_format *format, double a)
{
	long long int   integer;
    long long int   decimal;
    char			*temp_str;
    char			*result_str;
	int				i;

    /* var "integer" contains everything before separator, var "decimal" contains everything after separator */
    integer = (long long int)a;
    if (a < 0)
	{
        decimal = get_decimal(format->precision, -(a - integer), &integer);
		format->length = int_length(integer, 10) + 1;
	}
	else
	{
        decimal = get_decimal(format->precision, a - integer, &integer);
		format->length = int_length(integer, 10);
	}
    if (!format->length || !(result_str = ft_strnew(format->length)))
        return (0);
    result_str = ft_itoa_base(integer, 10, format, result_str);
    if (a < 0)
        result_str[0] = '-';
    /* following cycle may be considered as subroutine to join decimal part*/
    if (format->precision)
    {
	    format->length = int_length(decimal, 10);
	    if (!(temp_str = ft_strnew(format->length)))
            return (0);
	    temp_str = ft_itoa_base(decimal, 10, format, temp_str);
	    while (format->length < format->precision)
            if (!(temp_str = join_prefix("0", temp_str, format)))
                return (0);
        if (!(temp_str = join_prefix(".", temp_str, format)))
		    return (0);
        if (!(result_str = join_strings(result_str, temp_str, format)))
		    return (0);
    }
    i = convert2string(format, result_str);
    free (result_str);
    return (i);
}

int     combine_options(t_format *format, va_list ap)
{
    int res;
	
	if (format->type == '%')
        res = convert2char(format, '%');
    else if (format->type == 'c')
        res = convert2char(format, va_arg(ap, int));
    else if (format->type == 's')
        res = convert2string(format, va_arg(ap, char *));
    else if (format->type == 'p')
        res = convert2int(format, va_arg(ap, long long int), 16);
    else if (format->type == 'd' || format->type == 'i')
        res = convert2int(format, va_arg(ap, int), 10);
    else if (format->type == 'x' || format->type == 'X')
        res = convert2int(format, va_arg(ap, unsigned int), 16);
    else if (format->type == 'o')
    	res = convert2int(format, va_arg(ap, unsigned int), 8);
    else if (format->type == 'u')
		res = convert2int(format, va_arg(ap, unsigned int), 10);
	else if (format->type == 'f')
        res = convert2float(format, va_arg(ap, double));
    return (res);
}