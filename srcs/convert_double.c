#include "ft_printf.h"

int		check_for_rounding(t_float *decimal, int array_elem_id, int digit_in_elem)
{
	unsigned long int	comp_base;

	comp_base = BASE;
	if (array_elem_id == decimal->current_element)
		while ((int_length(comp_base, 10) - int_length(decimal->array[array_elem_id], 10)) > 1)
			comp_base /= 10;
	while (digit_in_elem--)
		comp_base /= 10;
	if (decimal->array[array_elem_id] % comp_base < comp_base / 2)
		return (0);
	return (1);
}

//rounding: 0 - applied, no impact, 1 - applied, impact on integer, 2 - applied, impact on leading zeros
void	rounding(t_float *decimal, t_float *integer, size_t *zero_counter, t_format *format)
{
	size_t	first_elem_len;
	int		array_elem_id;
	int		digit_in_elem;

	if (format->precision < *zero_counter)
		return ;
	array_elem_id = decimal->current_element;
	first_elem_len = int_length(decimal->array[array_elem_id], 10);
	if (format->precision < *zero_counter + first_elem_len)
		digit_in_elem = format->precision - *zero_counter;
	else
	{
		if ((array_elem_id -= (format->precision - *zero_counter - first_elem_len) / BASE_LEN + 1) < 0)
			return ;
		digit_in_elem = (format->precision - *zero_counter - first_elem_len) % BASE_LEN;
	}
	if (check_for_rounding(decimal, array_elem_id, digit_in_elem))
		if (sum_decimal_const(decimal, zero_counter, array_elem_id, digit_in_elem) == 1)
			sum_integer_const(integer, 1);
}

size_t	count_leading_zeros (double a, char sign)
{
	size_t	counter;

	if (sign == '-')
		a = -a;
	counter = 0;
	while (a && a < 0.1)
	{
		a *= 10;
		counter++;
	}
	return (counter);
}

void	clean_exp(t_float *exp)
{
	while ((*exp).current_element >= 0)
		(*exp).array[(*exp).current_element--] = 0;
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
	t_float				exp;
	unsigned long int	leading_zero_flag;
	unsigned long int	mediator;
	size_t				leading_zero_counter;

	array_cleaner(decimal);
	exponent = -exponent;
	leading_zero_flag = 0;
	leading_zero_counter = 0;
	//moved to function array_cleaner
	//(*decimal).current_element = 0;
	if (exponent != EXP_DFLT)
	{
		//a = define_leading_zeros();
		while (fraction_length-- > 0)
		{
			if (((dbl.t_union.mantissa >> fraction_length) & 1L) == 1L)
				sum_decimal(decimal, power(5, exponent, &exp));
			//insert here leading zero check.
			else if (!decimal->current_element && !decimal->array[0])
			{
				decimal->array[0] = 1;
				leading_zero_flag = 1;
			}
			else
				sum_decimal(decimal, &exp);
			++exponent;
			//printf("fraction_length = %hd, byte = %d\n", fraction_length, ((dbl.t_union.mantissa >> fraction_length) & 1L) == 1L);
		}
		if (leading_zero_flag)
		{
			mediator = decimal->array[decimal->current_element];
			while ((mediator /= 10))
				leading_zero_flag *= 10;
			decimal->array[decimal->current_element] -= leading_zero_flag;
			while (decimal->array[decimal->current_element] < leading_zero_flag && leading_zero_flag > 1)
			{
				leading_zero_flag /= 10;
				++leading_zero_counter;
			}
		}
	}
	return (leading_zero_counter);
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

int		convert_float2string(t_format *format, long double a)
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
	size_t				zero_counter;

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
	zero_counter = count_leading_zeros(a, format->content.sign);
	printf("Exponent = %hd\n", exponent);
	zero_counter += get_decimal_2(dbl, &decimal, get_integer(dbl, &integer, &exponent), exponent);
	printf("Exponent = %hd\n", exponent);
	printf("Leading zeros = %zu\n", zero_counter);
	//if (!apply_precision_float_2(format, &integer, &decimal, zero_counter))
	//	return (0);
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
	//rounding: 0 - applied, no impact, 1 - applied, impact on integer, 2 - applied, impact on leading zeros
	rounding(&decimal, &integer, &zero_counter, format);
	if (!(format->content.string2show = ft_itoa_base_array_precision(\
		&decimal, 10, zero_counter, format->precision)))
		return (0);
	if (format->precision && !(format->content.string2show = join_prefix(\
		".", format)))
		return (0);
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
