#include "ft_printf.h"

unsigned long long int	get_integer(t_dbl dbl)
{
	short int	exponent;
	
	if ((exponent = dbl.t_union.exponent - 16383) < 0)
		return (0);
	else if (exponent < 64)
		return (dbl.t_union.mantissa >> (63 - exponent));
}

int		check_double_exceptions(t_format *format, t_dbl dbl)
{
	if (((dbl.t_union.mantissa >> 63) & 1L) == 0)
	{
		if (((dbl.t_union.mantissa >> 62) & 1L) == 0)
		{
			if (((dbl.t_union.mantissa >> 61) & 1L) == 0)
				format->content.string2show = ft_strdup("inf");
			else
				format->content.string2show = ft_strdup("nan");
		}
		else
			format->content.string2show = ft_strdup("nan");
	}
	else
	{
		if (((dbl.t_union.mantissa >> 62) & 1L) == 0)
		{
			if (((dbl.t_union.mantissa >> 61) & 1L) == 0)
				format->content.string2show = ft_strdup("inf");
			else
				format->content.string2show = ft_strdup("nan");
		}
		else
		{
			if (((dbl.t_union.mantissa >> 61) & 1L) == 0)
				format->content.string2show = ft_strdup("nan");
			else
				format->content.string2show = ft_strdup("nan");
		}
	}
	if (!ft_strcmp(format->content.string2show, "nan") || !ft_strcmp(format->content.string2show, "inf"))
		return (0);
	return (1);
}

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
	unsigned long long int	integer;
	long long int			decimal;
    short int           	exp_value;
	t_dbl					dbl;
	int						i;
	char					str[65];
	
	dbl.dbl = (long double)a;
	printf("Value=%d\n", dbl.t_union.sign);
	printf("Mantissa =%llu\n", dbl.t_union.mantissa);
	printf("Exponent =%d\n", dbl.t_union.exponent);
	i = 0;
	while (i < 64)
		{
			if (((dbl.t_union.mantissa >> i) & 1L) == 1L)
				str[i] = '1';
			else
				str[i] = '0';
			i++;
		}
	str[64] = '\0';
	printf("%s\n", str);
	if (dbl.t_union.exponent == 32767 && !check_double_exceptions(format, dbl))
		return (1);
	if (dbl.t_union.sign)
		format->content.sign = '-';
	integer = get_integer(dbl);
	printf("ineger =%llu\n", integer);
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