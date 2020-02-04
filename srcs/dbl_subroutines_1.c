/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_subroutines_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 19:24:17 by lgeorgin          #+#    #+#             */
/*   Updated: 2020/01/26 19:24:29 by lgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		dbl_check_for_rounding(t_array *array, int array_elem_id, \
															int digit_in_elem)
{
	unsigned long int	comp_base;

	comp_base = BASE;
	if (array_elem_id == array->current_element)
		while ((int_length(comp_base, 10) - \
				int_length(array->array[array_elem_id], 10)) > 1)
			comp_base /= 10;
	while (digit_in_elem--)
		comp_base /= 10;
	if (array->array[array_elem_id] % comp_base < comp_base / 2)
		return (0);
	return (1);
}

/*
** rounding:
** 0 - applied, no impact
** 1 - applied, impact on integer
** 2 - applied, impact on leading zeros
*/

void	dbl_rounding(t_format *format, t_float *flt, t_array *integer, \
										t_array *decimal, size_t precision)
{
	size_t	first_elem_len;
	int		array_elem_id;
	int		digit_in_elem;

	if (precision < flt->zero_counter)
		return ;
	array_elem_id = decimal->current_element;
	first_elem_len = int_length(decimal->array[array_elem_id], 10);
	if (precision < flt->zero_counter + first_elem_len)
		digit_in_elem = precision - flt->zero_counter;
	else
	{
		if ((array_elem_id -= (precision - flt->zero_counter - first_elem_len) \
															/ BASE_LEN + 1) < 0)
			return ;
		digit_in_elem = (precision - flt->zero_counter - first_elem_len) \
															% BASE_LEN;
	}
	if (dbl_check_for_rounding(decimal, array_elem_id, digit_in_elem))
		if (sum_decimal_const(format, flt, decimal, array_elem_id, \
															digit_in_elem) == 1)
			sum_integer_const(integer, 0, 4, 1);
}

void	dbl_e_rounding(t_format *format, t_float *flt, \
										t_array *integer, t_array *decimal)
{
	int		array_elem_id;
	int		digit_in_elem;

	array_elem_id = integer->current_element;
	if (format->precision < integer->array_len - 1)
	{
		if (format->precision + 1 < integer->first_len)
			digit_in_elem = format->precision + 1;
		else
		{
			if ((array_elem_id -= (format->precision + 1 - integer->first_len) \
														/ BASE_LEN + 1) < 0)
				return ;
			digit_in_elem = (format->precision + 1 - integer->first_len) \
														% BASE_LEN;
		}
		if (dbl_check_for_rounding(integer, array_elem_id, digit_in_elem))
			sum_integer_const(integer, array_elem_id, digit_in_elem, 1);
	}
	else if (integer->array[array_elem_id])
		dbl_rounding(format, flt, integer, decimal, \
						format->precision - integer->array_len + 1);
	else if (format->precision < format->precision + flt->zero_counter + 1)
		dbl_rounding(format, flt, integer, decimal, \
						format->precision + flt->zero_counter + 1);
}

void	dbl_remove_trailing_zeros(t_format *format)
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
