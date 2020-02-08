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

int		dbl_check_for_rounding(t_format *format, t_array *array)
{
	unsigned long int	comp_base;
	int					digit_in_elem;

	comp_base = BASE;
	digit_in_elem = array->round.digit_in_elem;
	if (array->round.elem_id == array->current_element)
		while ((int_length(comp_base, format->base) - \
				int_length(array->array[array->round.elem_id], 10)) > 1)
			comp_base /= format->base;
	while (digit_in_elem--)
		comp_base /= format->base;
	if (array->array[array->round.elem_id] % comp_base < comp_base / 2)
		return (0);
	return (1);
}

/*
** rounding:
** 0 - applied, no impact
** 1 - applied, impact on integer
** 2 - applied, impact on leading zeros
*/

void	dbl_dec_rounding(t_format *format, t_float *flt, \
										t_array *integer, t_array *decimal)
{
	int		rounding_pos;

	if (flt->dec_prec < flt->zero_counter)
		return ;
	decimal->round.elem_id = decimal->current_element;
	if (flt->dec_prec < flt->zero_counter + decimal->first_len)
		decimal->round.digit_in_elem = flt->dec_prec - flt->zero_counter;
	else
	{
		rounding_pos = flt->dec_prec - flt->zero_counter - decimal->first_len;
		if ((decimal->round.elem_id -= rounding_pos / BASE_LEN + 1) < 0)
			return ;
		decimal->round.digit_in_elem = rounding_pos % BASE_LEN;
	}
	if (dbl_check_for_rounding(format, decimal))
		if (sum_decimal_const(format, flt, decimal) == 1)
		{
			integer->round.elem_id = 0;
			integer->round.digit_in_elem = 4;
			sum_array_const(format, integer, 1);
		}
}

void	dbl_e_rounding(t_format *format, t_float *flt, \
										t_array *integer, t_array *decimal)
{
	int		rounding_pos;

	integer->round.elem_id = integer->current_element;
	if (format->precision < integer->array_len - 1)
	{
		if ((rounding_pos = format->precision + 1 - integer->first_len) < 0)
			integer->round.digit_in_elem = format->precision + 1;
		else
		{
			if ((integer->round.elem_id -= rounding_pos / BASE_LEN + 1) < 0)
				return ;
			integer->round.digit_in_elem = rounding_pos % BASE_LEN;
		}
		if (dbl_check_for_rounding(format, integer))
			sum_array_const(format, integer, 1);
	}
	else if (integer->array[integer->current_element])
	{
		flt->dec_prec = format->precision - integer->array_len + 1;
		dbl_dec_rounding(format, flt, integer, decimal);
	}
	else if (format->precision < \
				(flt->dec_prec = format->precision + flt->zero_counter + 1))
		dbl_dec_rounding(format, flt, integer, decimal);
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
