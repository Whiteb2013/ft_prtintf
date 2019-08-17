#include "ft_printf.h"

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
	if (!(format->content.string2show = ft_itoa_base(b, base)))
		return (0);
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
		if (!(format->content.string2show = ft_itoa_base(decimal, 10)))
			return (0);
		if (!apply_precision_float(format))
			return (0);
	}
	if (!(format->content.string2show = join_strings(ft_itoa_base(integer, 10), format->content.string2show, format)))
		return (0);
	return (1);
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
		if (!(format->content.string2show = ft_itoa_base(decimal, 10)))
			return (0);
		if (!apply_precision_float(format))
			return (0);
	}
	if (!(format->content.string2show = join_strings(ft_itoa_base(integer, 10), format->content.string2show, format)))
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
	else if (format->type == 'c')
		res = convert_char2string(format, va_arg(ap, int));
	else if (format->type == 's')
	{
		format->content.string2show = va_arg(ap, char *);
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