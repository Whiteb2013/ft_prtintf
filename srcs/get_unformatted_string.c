#include "ft_printf.h"

int		convert_char2string(t_format *format, int a)
{   
	if (!(format->content.string2show = ft_strnew(1)))
		return (0);
	format->content.string2show[0] = (unsigned char)a;
	return (1);
}

char    *ft_itoa_base_2(long long int int2convert, size_t base)
{
    char    *str1;
    char    *str2;
    size_t	i;
    size_t  k;
    char	values[16] = "0123456789abcdef";

	// idk why but we cant <return "0";> so next 7 rows for that
	if (int2convert == 0)
	{
		if (!(str2 = ft_strnew(0)))
        	return (NULL);
		str2[0] = '0';
		return (str2);
	}

	i = int_length(int2convert, 10);
    if (!(str1 = ft_strnew(i)) || !(str2 = ft_strnew(i)))
        return (NULL);
    k = 0;
    while (int2convert)
    {
        str1[k++] = values[int2convert % base];
        int2convert = int2convert / base;
    }
    i = 0;
    str2[k] = '\0';
    while (k > 0)
        str2[i++] = str1[--k];
    return (str2);
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
	if (!(format->content.string2show = ft_itoa_base(b, base)))// itoa2
		return (0);
	if (!a)
		format->flag.hash = 'f';
	//printf("\ncontent = %s\n", format->content.string2show);
	return (1);
}

int     convert_short2string(t_format *format, short a, size_t base)
{
	short	b;

	if (a < 0)
	{
		format->content.sign = '-';
		b = -a;
	}
	else
		b = a;
	if (!(format->content.string2show = ft_itoa_base(b, base)))// itoa2
		return (0);
	if (!a)
		format->flag.hash = 'f';
	return (1);
}

int		convert_pointer2string(t_format *format, long long int a)
{
	if (!convert_int2string(format, a, 16))
		return (0);
	format->flag.hash = 't';
	return (1);
}

int		convert_float2string(t_format *format, double a)
{
	long long int   integer;
	long long int   decimal;

	// var "integer" contains everything before separator, var "decimal" contains everything after separator
	if (a < 0)
	{
		a *= -1;
		format->content.sign = '-';
	}
	integer = (long long int)a;
	decimal = get_decimal(format->precision, a - integer, &integer);
	if (format->precision)
	{
		if (!(format->content.string2show = ft_itoa_base(decimal, 10)))// itoa2
			return (0);
		if (!apply_precision_float(format))
			return (0);
	}
	if (!(format->content.string2show = join_strings(ft_itoa_base(integer, 10), format->content.string2show, format)))// itoa2
		return (0);
	return (1);
}

int     apply_length(t_format *format, va_list ap)
{
	int res;

	res = 0;
	
	// LENGTH == h
	if ((format->type == 'd' || format->type == 'i') && !ft_strcmp(format->length_flag, "h"))
		res = convert_int2string(format, (int)((short)(va_arg(ap, int))), 10);
	else if ((format->type == 'u') && !ft_strcmp(format->length_flag, "h"))
		res = convert_int2string(format, (int)((short)(va_arg(ap, int))), 10);
	else if ((format->type == 'x' || format->type == 'X') && !ft_strcmp(format->length_flag, "h"))
		res = convert_int2string(format, (int)((short)(va_arg(ap, int))), 16);
	else if (format->type == 'o' && !ft_strcmp(format->length_flag, "h"))
		res = convert_int2string(format, (int)((short)(va_arg(ap, int))), 8);
	
	// LENGTH == hh
	else if ((format->type == 'd' || format->type == 'i') && !ft_strcmp(format->length_flag, "hh"))
		res = convert_int2string(format, (int)((char)(va_arg(ap, int))), 10);
	else if ((format->type == 'u') && !ft_strcmp(format->length_flag, "hh"))
		res = convert_int2string(format, (int)((char)(va_arg(ap, int))), 10);
	else if ((format->type == 'x' || format->type == 'X') && !ft_strcmp(format->length_flag, "hh"))
		res = convert_int2string(format, (int)((char)(va_arg(ap, int))), 16);
	else if (format->type == 'o' && !ft_strcmp(format->length_flag, "hh"))
		res = convert_int2string(format, (int)((char)(va_arg(ap, int))), 8);
	
	// LENGTH == l
	else if ((format->type == 'd' || format->type == 'i') && !ft_strcmp(format->length_flag, "l"))
		res = convert_int2string(format, va_arg(ap, long), 10);
	else if ((format->type == 'u') && !ft_strcmp(format->length_flag, "l"))
		res = convert_int2string(format, va_arg(ap, unsigned long), 10);
	else if ((format->type == 'x' || format->type == 'X') && !ft_strcmp(format->length_flag, "l"))
		res = convert_int2string(format, va_arg(ap, long), 16);
	else if (format->type == 'o' && !ft_strcmp(format->length_flag, "l"))
		res = convert_int2string(format, va_arg(ap, long), 8);

	// LENGTH == ll
	else if ((format->type == 'd' || format->type == 'i') && !ft_strcmp(format->length_flag, "ll"))
		res = convert_int2string(format, va_arg(ap, long long int), 10);
	else if ((format->type == 'u') && !ft_strcmp(format->length_flag, "ll"))
		res = convert_int2string(format, va_arg(ap, unsigned long long), 10);
	else if ((format->type == 'x' || format->type == 'X') && !ft_strcmp(format->length_flag, "ll"))
		res = convert_int2string(format, va_arg(ap, long long int), 16);
	else if (format->type == 'o' && !ft_strcmp(format->length_flag, "ll"))
		res = convert_int2string(format, va_arg(ap, long long int), 8);
	
	// LENGTH == L
	else if (format->type == 'f' && !ft_strcmp(format->length_flag, "L"))
		res = convert_float2string(format, va_arg(ap, long double));

	return (res);
}

/*
int		convert_float2string(t_format *format, double a)
{
	long long int   integer;
	long long int   decimal;

	// var "integer" contains everything before separator, var "decimal" contains everything after separator
	integer = (long long int)a;
	printf("integer = %llu\n", integer);
	if (a < 0)
	{
		decimal = get_decimal(format->precision, -(a - integer), &integer);
		format->content.sign = '-';
	}
	else
		decimal = get_decimal(format->precision, a - integer, &integer);
	if (format->precision)
	{
		if (!(format->content.string2show = ft_itoa_base_2(decimal, 10)))// itoa2
			return (0);
		if (!apply_precision_float(format))
			return (0);
	}
	if (!(format->content.string2show = join_strings(ft_itoa_base_2(integer, 10), format->content.string2show, format)))// itoa2
		return (0);
	return (1);
}
*/

int     convert2string(t_format *format, va_list ap)
{
	int res;
	
	res = 0;
	if (format->type == '%')
		res = convert_char2string(format, '%');
	if (format->length_flag[0] != 0) 					// rewrite condition
		res = apply_length(format, ap);
	else if (format->type == 'c')
		res = convert_char2string(format, va_arg(ap, int));
	else if (format->type == 's')
	{
		format->content.string2show = va_arg(ap, char *);
		if (!format->content.string2show)
			if (!(format->content.string2show = ft_strdup("(null)")))
				return (0);
		res = 1;
	}
	else if (format->type == 'p')
		res = convert_pointer2string(format, va_arg(ap, long long int));
	else if (format->type == 'd' || format->type == 'i')
		res = convert_int2string(format, va_arg(ap, int), 10);
	else if (format->type == 'x' || format->type == 'X')
		res = convert_int2string(format, va_arg(ap, unsigned int), 16);
	else if (format->type == 'o')
		res = convert_int2string(format, va_arg(ap, unsigned int), 8);
	else if (format->type == 'u')
		res = convert_int2string(format, va_arg(ap, unsigned int), 10);
	else if (format->type == 'f')
		res = convert_float2string(format, va_arg(ap, double));
	format->length = ft_strlen(format->content.string2show);
	return (res);
}