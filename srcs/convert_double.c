#include "ft_printf.h"

void	clean_exp(t_float *exp)
{
	while ((*exp).current_element >= 0)
		(*exp).array[(*exp).current_element--] = 0;
}

void		sum_integer(t_float *a, t_float *exp)
{
	int	i;

	i = 0;
	while (i <= (*a).current_element || i <= (*exp).current_element)
	{
		(*a).array[i + 1] += ((*a).array[i] + (*exp).array[i]) / BASE;
		(*a).array[i] = ((*a).array[i] + (*exp).array[i]) % BASE;
		//printf("Sum_a[%d] = %lu, exp[%d] = %lu\n", i, (*a).array[i], i, (*exp).array[i]);
		i++;
	}
	if ((*a).array[i])
		(*a).current_element = i;
	else
		(*a).current_element = i - 1;
	//check if may be cleaned earlier
	array_cleaner(exp);
}

void		sum_decimal(t_float *a, t_float *exp)
{
	int	i;
	unsigned long int	mediator_next;
	unsigned long int	mediator_prev;

	i = 0;
	mediator_prev = 0;
	while (i <= (*a).current_element || i <= (*exp).current_element)
	{
		mediator_next = (mediator_prev + (*a).array[i] * 10 + (*exp).array[i]) / BASE;
		(*a).array[i] = (mediator_prev + (*a).array[i] * 10 + (*exp).array[i]) % BASE;
		mediator_prev = mediator_next;
		//printf("Sum_a[%d] = %lu, exp[%d] = %lu\n", i, (*a).array[i], i, (*exp).array[i]);
		i++;
	}
	if (mediator_next)
	{
		(*a).array[i] = mediator_next;
		(*a).current_element = i;
	}
	else
		(*a).current_element = i - 1;
	//check if may be cleaned earlier
	array_cleaner(exp);
}

t_float		*power(unsigned long int base, short int power, t_float *exp)
{
	int	i;
	unsigned long int	mediator_next;
	unsigned long int	mediator_prev;

	array_cleaner(exp);
	//moved to function array_cleaner
	//(*exp).current_element = 0;
	(*exp).array[0] = 1;
	while (power-- > 0)
	{
		i = 0;
		mediator_prev = 0;
		while (i <= (*exp).current_element)
		{
			//организовать работу с переходящим остатком. Сначала умножить, затем прибавить разряд
			//if (!(*exp).array[i + 1])
			//	(*exp).array[i + 1] =  (*exp).array[i] * base / BASE_LEN;
			//else
			mediator_next = (mediator_prev + (*exp).array[i] * base) / BASE;
			(*exp).array[i] = (mediator_prev + (*exp).array[i] * base) % BASE;
			mediator_prev = mediator_next;
			i++;
		}
		if (mediator_next)
		{
			(*exp).array[i] = mediator_next;
			(*exp).current_element = i;
		}
		//printf("Power_Elem[0] = %lu, elem[1] = %lu, elem_counter = %d\n", (*exp).array[0], (*exp).array[1], (*exp).current_element);
	}
	return (exp);
}

int		get_integer(t_dbl dbl, t_float *integer, short int *exponent)
{
	short int			fraction_length;
	t_float				exp;

	array_cleaner(integer);
	fraction_length = 64;
	//moved to function array_cleaner
	//(*integer).current_element = 0;
	if (*exponent != -EXP_DFLT)
		while (*exponent >= 0 && fraction_length-- > 0)
		{
			if (((dbl.t_union.mantissa >> fraction_length) & 1L) == 1L)
				sum_integer(integer, power(2, *exponent, &exp));
			--*exponent;
		}
	return (fraction_length);
}

int		get_decimal_2(t_dbl dbl, t_float *decimal, short int fraction_length, short int exponent)
{
	t_float	exp;
	double	a;

	array_cleaner(decimal);
	exponent = -exponent;
	//moved to function array_cleaner
	//(*decimal).current_element = 0;
	if (exponent != EXP_DFLT)
	{
		//a = define_leading_zeros();
		while (fraction_length-- > 0)
		{
			if (((dbl.t_union.mantissa >> fraction_length) & 1L) == 1L)
				sum_decimal(decimal, power(5, exponent, &exp));
			else
				sum_decimal(decimal, &exp);
			++exponent;
			//printf("fraction_length = %hd, byte = %d\n", fraction_length, ((dbl.t_union.mantissa >> fraction_length) & 1L) == 1L);
		}
	}
	return (1);
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
	{
		format->content.sign = '\0';
		return (0);
	}
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
	t_dbl				dbl;
	t_float				integer;
	t_float				decimal;
	int					i;
	char				str[65];
	short int			exponent;

	dbl.dbl = (long double)a;
	/*
	printf("Value=%d\n", dbl.t_union.sign);
	printf("Mantissa =%lu\n", dbl.t_union.mantissa);
	printf("Exponent =%d\n", dbl.t_union.exponent);
	*/
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
	exponent = dbl.t_union.exponent - EXP_DFLT;
	printf("Exponent = %hd\n", exponent);
	get_decimal_2(dbl, &decimal, get_integer(dbl, &integer, &exponent), exponent);
	printf("Exponent = %hd\n", exponent);
	printf("Leading zeros = %d\n", (int)((double)(-exponent) / 3.32));
	if (!apply_precision_float_2(format, &integer, &decimal))
		return (0);
	i = 0;
	while (i <= integer.current_element)
	{
		printf("Int[%d] = %lu", i, integer.array[i]);
		i++;
	}
	puts("");
	i = 0;
	while (i <= decimal.current_element)
	{
		printf("Dec[%d] = %lu", i, decimal.array[i]);
		i++;
	}
	puts("");
	/*
	if (format->precision)
	{
		if (!(format->content.string2show = ft_itoa_base_array(&decimal, 10)))
			return (0);
		if (!apply_precision_float(format))
			return (0);
	}
	*/
	if (!(format->content.string2show = join_strings(\
		ft_itoa_base_array(&integer, 10), format->content.string2show, format)))
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
