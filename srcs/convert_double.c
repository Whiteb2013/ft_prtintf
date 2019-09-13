#include "ft_printf.h"

/*
** in the next function
** var "integer" contains everything before separator
** var "decimal" contains everything after separator
*/

int		convert_float2string(t_format *format, double a)
{
	long long int	integer;
	long long int	decimal;

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
	if (!(format->content.string2show = join_strings(\
		ft_itoa_base(integer, 10), format->content.string2show, format)))
		return (0);
	return (1);
}

int		convert_efloat2string(t_format *format, double a)
{
	long long int			integer;
	long long int			decimal;

	t_dbl					dbl;
	dbl.dbl = (long double)a;
	printf("Value=%d\n", dbl.t_union.sign);
	//printf("Value=%lu\n", dbl.t_union.mantissa);
	//printf("Value=%d\n", dbl.t_union.exponent);

	if (a < 0)
	{
		a *= -1;
		format->content.sign = '-';
	}
	while (a > 10)
	{
		a = a / 10;
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
	if (!(format->content.string2show = join_strings(\
		ft_itoa_base(integer, 10), format->content.string2show, format)))
		return (0);
	return (1);
}

int		convert_gfloat2string(t_format *format, double a)
{
	long long int			integer;
	long long int			decimal;

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
	if (!(format->content.string2show = join_strings(\
		ft_itoa_base(integer, 10), format->content.string2show, format)))
		return (0);
	return (1);
}