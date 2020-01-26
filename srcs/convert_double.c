/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_double.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 18:49:53 by gmarin            #+#    #+#             */
/*   Updated: 2020/01/26 18:50:31 by gmarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_for_rounding(t_float *decimal, int array_elem_id, \
							int digit_in_elem)
{
	unsigned long int	comp_base;

	comp_base = BASE;
	if (array_elem_id == decimal->current_element)
		while ((int_length(comp_base, 10) - \
				int_length(decimal->array[array_elem_id], 10)) > 1)
			comp_base /= 10;
	while (digit_in_elem--)
		comp_base /= 10;
	if (decimal->array[array_elem_id] % comp_base < comp_base / 2)
		return (0);
	return (1);
}

/*
** rounding:
** 0 - applied, no impact
** 1 - applied, impact on integer
** 2 - applied, impact on leading zeros
*/

void	rounding(t_float *decimal, t_float *integer, \
					size_t *zero_counter, size_t precision)
{
	size_t	first_elem_len;
	int		array_elem_id;
	int		digit_in_elem;

	if (precision < *zero_counter)
		return ;
	array_elem_id = decimal->current_element;
	first_elem_len = int_length(decimal->array[array_elem_id], 10);
	if (precision < *zero_counter + first_elem_len)
		digit_in_elem = precision - *zero_counter;
	else
	{
		if ((array_elem_id -= (precision - *zero_counter - first_elem_len) /\
				BASE_LEN + 1) < 0)
			return ;
		digit_in_elem = (precision - *zero_counter - first_elem_len) % BASE_LEN;
	}
	if (check_for_rounding(decimal, array_elem_id, digit_in_elem))
		if (sum_decimal_const(decimal, zero_counter, \
			array_elem_id, digit_in_elem) == 1)
			sum_integer_const(integer, 1);
}

int		e_rounding(t_float *decimal, t_float *integer, \
					size_t *zero_counter, size_t precision)
{
	size_t	first_elem_len;
	size_t	array_length;
	int		array_elem_id;
	int		digit_in_elem;

	array_elem_id = integer->current_element;
	first_elem_len = int_length(integer->array[array_elem_id], 10);
	array_length = int_length_array(integer, 10) - 1;
	if (precision < array_length)
	{
		if (precision + 1 < first_elem_len)
			digit_in_elem = precision + 1;
		else
		{
			array_elem_id -= (precision + 1 - first_elem_len) / BASE_LEN;
			digit_in_elem = (precision + 1 - first_elem_len) % BASE_LEN;
		}
		if (check_for_rounding(integer, array_elem_id, digit_in_elem))
			sum_integer_const(integer, 1);
	}
	else if (integer->array[array_elem_id])
		rounding(decimal, integer, zero_counter, precision - array_length);
	else if (precision < precision + *zero_counter + 1)
		rounding(decimal, integer, zero_counter, precision + *zero_counter + 1);
	else
		return (0);
	return (1);
}

size_t	count_leading_zeros(double a, char sign)
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
	if (!ft_strcmp(format->content.string2show, "nan") || \
		!ft_strcmp(format->content.string2show, "inf"))
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

int		convert_f2string(t_format *format, t_float *integer, \
							t_float *decimal, size_t zero_counter)
{
	rounding(decimal, integer, &zero_counter, format->precision);
	if (!(format->content.string2show = ft_itoa_base_array_precision(\
		decimal, 10, zero_counter, format->precision)))
		return (0);
	if (format->precision && !(format->content.string2show = join_prefix(\
		".", format)))
		return (0);
	if (!(format->content.string2show = join_strings(\
		ft_itoa_base_array(integer, 10), format->content.string2show, format)))
		return (0);
	return (1);
}

int		convert_e2string(t_format *format, t_float *integer, \
							t_float *decimal, size_t zero_counter)
{
	size_t				array_length;

	e_rounding(decimal, integer, &zero_counter, format->precision);
	array_length = int_length_array(integer, 10) - 1;
	if (integer->array[integer->current_element] || \
		!decimal->array[decimal->current_element])
	{
		if (!(format->content.string2show = ft_itoa_base_array_precision_e(\
		integer, 10, format)))
			return (0);
		if (array_length < format->precision)
		{
			if (!(format->content.string2show = \
					join_strings(format->content.string2show, \
					ft_itoa_base_array_precision(decimal, 10, zero_counter, \
					format->precision - array_length), format)))
				return (0);
		}
		if (!(format->content.string2show = join_postfix(format, "e+")))
			return (0);
		if (!(format->content.string2show = \
				join_strings(format->content.string2show, \
				ft_itoa_base(array_length, 10, 2), format)))
			return (0);
	}
	else
	{
		if (!(format->content.string2show = ft_itoa_base_array_precision_e(\
		decimal, 10, format)))
			return (0);
		if (!(format->content.string2show = join_postfix(format, "e-")))
			return (0);
		if (!(format->content.string2show = \
				join_strings(format->content.string2show, \
				ft_itoa_base(zero_counter + 1, 10, 2), format)))
			return (0);
	}
	return (1);
}

int		convert_g2string(t_format *format, t_float *integer, \
							t_float *decimal, size_t zero_counter)
{
	if ((integer->array[integer->current_element] && \
			int_length_array(integer, 10) <= format->precision) || \
		(!integer->array[integer->current_element] && zero_counter < 4))
	{
		if (!convert_f2string(format, integer, decimal, zero_counter))
			return (0);
	}
	else
	{
		if (format->precision)
			format->precision--;
		if (!convert_e2string(format, integer, decimal, zero_counter))
			return (0);
	}
	return (1);
}

int		convert_fge2string(t_format *format, long double a)
{
	t_float				integer;
	t_float				decimal;
	t_dbl				dbl;
	short int			exponent;
	size_t				zero_counter;

	array_cleaner(&integer);
	array_cleaner(&decimal);
	dbl.dbl = (long double)a;
	if (dbl.t_union.exponent == 32767 && !check_double_exceptions(format, dbl))
		return (1);
	if (dbl.t_union.sign)
		format->content.sign = '-';
	exponent = dbl.t_union.exponent - EXP_DFLT;
	zero_counter = count_leading_zeros(a, format->content.sign);
	zero_counter += get_decimal(dbl, &decimal, get_integer(dbl, &integer, &exponent), &exponent);
	if (format->type == 'g' || format->type == 'G')
	{
		if (!convert_g2string(format, &integer, &decimal, zero_counter))
			return (0);
	}
	else if (format->type == 'f' || format->type == 'F')
	{
		if (!convert_f2string(format, &integer, &decimal, zero_counter))
			return (0);
	}
	else if (format->type == 'e' || format->type == 'E')
	{
		if (!convert_e2string(format, &integer, &decimal, zero_counter))
			return (0);
	}
	return (1);
}
