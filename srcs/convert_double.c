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

void	remove_trailing_zeros(t_format *format)
{
	size_t	str_len;

	format->length = ft_strlen(format->content.string2show);
	if ((format->type == 'g' || format->type == 'G') && \
			format->flag.hash == 'f')
	{
		if (ft_strrchr(format->content.string2show, '.'))
		{
			str_len = format->length - 1;
			while (format->content.string2show[str_len] == '0')
				format->content.string2show[str_len--] = '\0';
			if (format->content.string2show[str_len] == '.')
				format->content.string2show[str_len--] = '\0';
			format->length = str_len + 1;
		}
	}
}

/*
** in the next function
** var "integer" contains everything before separator
** var "decimal" contains everything after separator
*/

int		convert_f2string(t_format *format, t_float *integer, \
							t_float *decimal, size_t zero_counter)
{
	rounding(integer, decimal, &zero_counter, format->precision);
	if (!(format->content.string2show = ft_itoa_base_array_precision(\
		decimal, 10, zero_counter, format->precision)))
		return (0);
	if (format->precision && !(format->content.string2show = join_prefix(\
		".", format)))
		return (0);
	if (!(format->content.string2show = join_strings(\
		ft_itoa_base_array_precision(integer, 10, 0, \
		int_length_array(integer, 10)), \
		format->content.string2show, format)))
		return (0);
	remove_trailing_zeros(format);
	return (1);
}

int		convert_e2string_positive(t_format *format, t_float *integer, \
									t_float *decimal, size_t zero_counter)
{
	size_t				array_length;

	array_length = int_length_array(integer, 10) - 1;
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
	remove_trailing_zeros(format);
	if (!(format->content.string2show = join_postfix(format, "e+")))
		return (0);
	if (!(format->content.string2show = \
			join_strings(format->content.string2show, \
			ft_itoa_base(array_length, 10, 2), format)))
		return (0);
	return (1);
}

int		convert_e2string_negative(t_format *format, t_float *decimal, \
									size_t zero_counter)
{
	if (!(format->content.string2show = ft_itoa_base_array_precision_e(\
	decimal, 10, format)))
		return (0);
	remove_trailing_zeros(format);
	if (!(format->content.string2show = join_postfix(format, "e-")))
		return (0);
	if (!(format->content.string2show = \
			join_strings(format->content.string2show, \
			ft_itoa_base(zero_counter + 1, 10, 2), format)))
		return (0);
	return (1);
}

int		convert_e2string(t_format *format, t_float *integer, \
							t_float *decimal, size_t zero_counter)
{
	e_rounding(integer, decimal, &zero_counter, format->precision);
	if (integer->array[integer->current_element] || \
		!decimal->array[decimal->current_element])
	{
		if (!convert_e2string_positive(format, integer, decimal, zero_counter))
			return (0);
	}
	else
	{
		if (!convert_e2string_negative(format, decimal, zero_counter))
			return (0);
	}
	return (1);
}

int		convert_g2string_as_f2str(t_format *format, t_float *integer, \
							t_float *decimal, size_t zero_counter)
{
	size_t		array_len;

	array_len = int_length_array(integer, 10);
	if (integer->array[integer->current_element] && \
		format->precision >= array_len)
		format->precision -= array_len;
	else if (!integer->array[integer->current_element])
	{
		if (format->precision <= zero_counter \
				&& zero_counter < zero_counter + 1)
			format->precision = zero_counter + 1;
		else if (format->precision + zero_counter >= format->precision)
			format->precision += zero_counter;
		else
			return (0);
	}
	if (!convert_f2string(format, integer, decimal, zero_counter))
		return (0);
	format->type = 'f';
	return (1);
}

int		convert_g2string_as_e2str(t_format *format, t_float *integer, \
							t_float *decimal, size_t zero_counter)
{
	if (format->precision)
		format->precision--;
	if (!convert_e2string(format, integer, decimal, zero_counter))
		return (0);
	format->type = 'e';
	return (1);
}

int		convert_g2string(t_format *format, t_float *integer, \
							t_float *decimal, size_t zero_counter)
{
	size_t			array_len;
	unsigned int	top_int_value;

	array_len = int_length_array(integer, 10);
	top_int_value = integer->array[integer->current_element];
	if (!format->precision)
		format->precision = 1;
	if ((top_int_value && array_len <= format->precision) || \
		(!top_int_value && zero_counter < 4))
	{
		if (!convert_g2string_as_f2str(format, integer, decimal, zero_counter))
			return (0);
	}
	else
	{
		if (!convert_g2string_as_e2str(format, integer, decimal, zero_counter))
			return (0);
	}
	return (1);
}

int		select_double_type(t_format *format, t_float *integer, \
							t_float *decimal, size_t zero_counter)
{
	if (format->type == 'g' || format->type == 'G')
	{
		if (!convert_g2string(format, integer, decimal, zero_counter))
			return (0);
	}
	else if (format->type == 'f' || format->type == 'F')
	{
		if (!convert_f2string(format, integer, decimal, zero_counter))
			return (0);
	}
	else if (format->type == 'e' || format->type == 'E')
	{
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
	if (dbl.t_union.sign)
		format->content.sign = '-';
	exponent = dbl.t_union.exponent - EXP_DFLT;
	if ((exponent != -EXP_DFLT && ((dbl.t_union.mantissa >> 63) & 1L) == 0L) \
			|| exponent == EXP_EXCPN - EXP_DFLT)
	{
		if (!check_double_exceptions(format, dbl))
			return (0);
		return (1);
	}
	zero_counter = get_decimal(dbl, &decimal, \
		get_integer(dbl, &integer, &exponent), &exponent);
	if (!select_double_type(format, &integer, &decimal, zero_counter))
		return (0);
	return (1);
}
