/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_unformatted_string_gG.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 18:49:53 by gmarin            #+#    #+#             */
/*   Updated: 2020/01/26 18:50:31 by gmarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		convert_g2string_as_f2str(t_format *format, t_float *flt, \
									t_array *integer, t_array *decimal)
{
	if (integer->array[integer->current_element] && \
		format->precision >= integer->array_len)
		format->precision -= integer->array_len;
	else if (!integer->array[integer->current_element])
	{
		if (format->precision <= flt->zero_counter \
				&& flt->zero_counter < flt->zero_counter + 1)
			format->precision = flt->zero_counter + 1;
		else if (format->precision + flt->zero_counter >= format->precision)
			format->precision += flt->zero_counter;
		else
			return (0);
	}
	if (!convert_f2string(format, flt, integer, decimal))
		return (0);
	format->type = 'f';
	return (1);
}

int		convert_g2string_as_e2str(t_format *format, t_float *flt, \
									t_array *integer, t_array *decimal)
{
	if (format->precision)
		format->precision--;
	if (!convert_e2string(format, flt, integer, decimal))
		return (0);
	format->type = 'e';
	return (1);
}

int		convert_g2string(t_format *format, t_float *flt, \
							t_array *integer, t_array *decimal)
{
	unsigned int	top_int_value;

	top_int_value = integer->array[integer->current_element];
	if (!format->precision)
		format->precision = 1;
	if ((top_int_value && integer->array_len <= format->precision) || \
		(!top_int_value && flt->zero_counter < 4))
	{
		if (!convert_g2string_as_f2str(format, flt, integer, decimal))
			return (0);
	}
	else
	{
		if (!convert_g2string_as_e2str(format, flt, integer, decimal))
			return (0);
	}
	return (1);
}
