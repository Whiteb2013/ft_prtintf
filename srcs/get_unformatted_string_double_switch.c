/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_unformatted_string_double_switch.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 18:49:53 by gmarin            #+#    #+#             */
/*   Updated: 2020/01/26 18:50:31 by gmarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** in the next function
** var "integer" contains everything before separator
** var "decimal" contains everything after separator
*/

int		select_double_type(t_format *format, t_float *flt, \
							t_array *integer, t_array *decimal)
{
	if (format->type == 'g' || format->type == 'G')
	{
		if (!convert_g2string(format, flt, integer, decimal))
			return (0);
	}
	else if (format->type == 'f' || format->type == 'F')
	{
		if (!convert_f2string(format, flt, integer, decimal))
			return (0);
	}
	else if (format->type == 'e' || format->type == 'E')
	{
		if (!convert_e2string(format, flt, integer, decimal))
			return (0);
	}
	return (1);
}

int		convert_double2string(t_format *format, long double a, size_t base)
{
	t_array				integer;
	t_array				decimal;
	t_float				flt;

	clean_array(&integer);
	clean_array(&decimal);
	flt.dbl.dbl = (long double)a;
	if (flt.dbl.t_union.sign)
		format->content.sign = '-';
	format->base = base;
	flt.exponent = flt.dbl.t_union.exponent - EXP_DFLT;
	if (((((flt.dbl.t_union.mantissa >> 63) & 1L) == 0L) || \
		flt.exponent == EXP_EXCPN - EXP_DFLT) && flt.exponent != -EXP_DFLT)
	{
		if (!dbl_check_exceptions(format, &flt))
			return (0);
		return (1);
	}
	flt.fraction_len = 64;
	flt.zero_counter = 0;
	dbl_get_integer(format, &flt, &integer);
	dbl_get_decimal(format, &flt, &decimal);
	if (!select_double_type(format, &flt, &integer, &decimal))
		return (0);
	return (1);
}
