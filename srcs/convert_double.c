#include "ft_printf.h"

/*
** in the next function
** var "integer" contains everything before separator
** var "decimal" contains everything after separator
*/

int		check_double_exceptions(t_format *format, t_dbl dbl)
{
	if (((dbl.t_union.mantissa >> 63) & 1) == 0)
	{
		if (((dbl.t_union.mantissa >> 62) & 1) == 0)
		{
			if (((dbl.t_union.mantissa >> 61) & 1) == 0)
				format->content.string2show = ft_strdup("inf");
			else
				format->content.string2show = ft_strdup("nan");
		}
		else
			format->content.string2show = ft_strdup("nan");
	}
	else
	{
		if (((dbl.t_union.mantissa >> 62) & 1) == 0)
		{
			if (((dbl.t_union.mantissa >> 61) & 1) == 0)
				format->content.string2show = ft_strdup("inf");
			else
			{
				format->content.string2show = ft_strdup("nan");
				format->content.sign = '\0';
			}
		}
		else
		{
			if (((dbl.t_union.mantissa >> 61) & 1) == 0)
				format->content.string2show = ft_strdup("nan");
			else
			{
				format->content.string2show = ft_strdup("nan");
				format->content.sign = '\0';
			}
		}
	}
	if (!ft_strcmp(format->content.string2show, "nan") || !ft_strcmp(format->content.string2show, "inf"))
		return (0);
	return (1);
}

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
    short int           	exp_value;
	t_dbl					dbl;
	int						i;
	char					str[65];
	
	dbl.dbl = (long double)a;
	i = 0;
	while (i < 64)
		{
			if ((dbl.t_union.mantissa >> i) == 1)
				str[i] = '1';
			else
				str[i] = '0';
			i++;
		}
	str[64] = '\0';
	//printf("%s\n", str);
	if (dbl.t_union.exponent == 32767 && !check_double_exceptions(format, dbl))
		return (1);
	if ((exp_value = dbl.t_union.exponent - 16383) < 0)
		integer = 0;
	//printf("Value=%d\n", dbl.t_union.sign);
	//printf("Mantissa =%lu\n", dbl.t_union.mantissa);
	//printf("Exponent =%d\n", dbl.t_union.exponent);

	if (dbl.t_union.sign)
		format->content.sign = '-';
	//else
	//	integer = get_integer();
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