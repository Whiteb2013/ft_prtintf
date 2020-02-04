/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_unformatted_string_e.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 02:06:35 by lgeorgin          #+#    #+#             */
/*   Updated: 2020/02/03 02:06:43 by lgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		convert_e2string_positive(t_format *format, t_float *flt, \
									t_array *integer, t_array *decimal)
{
	if (!(format->content.string2show = ft_itoa_base_array_precision_e(\
														format, integer)))
		return (0);
	if (integer->array_len - 1 < format->precision)
	{
		if (!(format->content.string2show = \
			join_strings(format->content.string2show, \
			ft_itoa_base_array_precision(decimal, flt->zero_counter, \
				format->precision - integer->array_len + 1), format)))
			return (0);
	}
	dbl_remove_trailing_zeros(format);
	if (!(format->content.string2show = join_postfix(format, "e+")))
		return (0);
	if (!(format->content.string2show = \
		join_strings(format->content.string2show, \
		ft_itoa_base(integer->array_len - 1, format->base, 2), format)))
		return (0);
	return (1);
}

int		convert_e2string_negative(t_format *format, t_float *flt, \
									t_array *decimal)
{
	if (!(format->content.string2show = ft_itoa_base_array_precision_e(\
														format, decimal)))
		return (0);
	dbl_remove_trailing_zeros(format);
	if (!(format->content.string2show = join_postfix(format, "e-")))
		return (0);
	if (!(format->content.string2show = \
			join_strings(format->content.string2show, \
			ft_itoa_base(flt->zero_counter + 1, format->base, 2), format)))
		return (0);
	return (1);
}

int		convert_e2string(t_format *format, t_float *flt, \
							t_array *integer, t_array *decimal)
{
	dbl_e_rounding(format, flt, integer, decimal);
	if (integer->array[integer->current_element] || \
		!decimal->array[decimal->current_element])
	{
		if (!convert_e2string_positive(format, flt, integer, decimal))
			return (0);
	}
	else
	{
		if (!convert_e2string_negative(format, flt, decimal))
			return (0);
	}
	return (1);
}
