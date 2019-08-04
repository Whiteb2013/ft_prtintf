#include "ft_printf.h"

int		convert2string(t_format *format, char *s)
{
    int i;
	
	i = -1;
	format->length = ft_strlen(s);
	if (format->length < format->width)
		if (!(s = apply_width(s, format)))
			return (0);
    if (!(s = apply_flags(s, format)))
		return (0);
	if (format->type >= 'A' && format->type <= 'Z')
        while (s[++i])
            s[i] = ft_toupper(s[i]);
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
    //issue to resolve later: str will cause a leak in case of no padding
    //free (result_str);
    return (i);
}

//for now this function palced here...
char	*apply_precision(char *s, t_format *format)
{
	char	*filler_str;
	size_t	i;

	i = 0;
    format->length = ft_strlen(s);
	if (!(filler_str = ft_strnew(format->precision - format->length)))
		return (NULL);
	while (i < format->precision - format->length)
		filler_str[i++] = '0';
	s = join_strings (filler_str, s, format);
	return (s);
}

int     combine_options(t_format *format, va_list ap)
{
    int     res;
    char    *str;
	
    //%% seems ok for now
	if (format->type == '%')
        res = convert2char(format, '%');
    //%c seems ok for now
    else if (format->type == 'c')
        res = convert2char(format, va_arg(ap, int));
    //%s seems ok for now
    else if (format->type == 's')
    {
        str = va_arg(ap, char *);
        if (format->precision_flag == 't')
            str = ft_strndup(str, format->precision);
        res = convert2string(format, str);
        //free(str);
    }
    //%p must be cheked
    else if (format->type == 'p')
        res = convert2int(format, va_arg(ap, long long int), 16);
    //for %d & %i have to add precision // works like width + flag zero // printf("%+8.5i\n", 123) => __+00123
    //i think we must get argument as a string, apply precision and only then convert it to int
    else if (format->type == 'd' || format->type == 'i')
    {
        str = ft_itoa(va_arg(ap, int));
        if (format->precision_flag == 't')
            str = apply_precision(str, format);
        //from this moment i dont know what is going on with standard printf // look at rows 22, 23, 25 in main_test.c
        if (atoi(str) >= 0)
            str = join_prefix("+", str, format);
        res = convert2string(format, str);
        //res = convert2int(format, atoi(str), 10);
    }
    else if (format->type == 'x' || format->type == 'X')
        res = convert2int(format, va_arg(ap, unsigned int), 16);
    else if (format->type == 'o')
    	res = convert2int(format, va_arg(ap, unsigned int), 8);
    else if (format->type == 'u')
		res = convert2int(format, va_arg(ap, unsigned int), 10);
    //for %f have to add rounding numbers when precision applied
	else if (format->type == 'f')
        //apply precision
        res = convert2float(format, va_arg(ap, double));
    return (res);
}