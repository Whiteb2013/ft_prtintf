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
