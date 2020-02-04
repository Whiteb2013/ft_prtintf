/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_unformatted_string_f.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 18:49:53 by gmarin            #+#    #+#             */
/*   Updated: 2020/01/26 18:50:31 by gmarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		convert_f2string(t_format *format, t_float *flt,
							t_array *integer, t_array *decimal)
{
	dbl_rounding(format, flt, integer, decimal, format->precision);
	if (!(format->content.string2show = ft_itoa_base_array_precision(\
		decimal, flt->zero_counter, format->precision)))
		return (0);
	if (format->precision && !(format->content.string2show = join_prefix(\
		".", format)))
		return (0);
	if (!(format->content.string2show = join_strings(\
		ft_itoa_base_array_precision(integer, 0, integer->array_len), \
		format->content.string2show, format)))
		return (0);
	dbl_remove_trailing_zeros(format);
	return (1);
}
