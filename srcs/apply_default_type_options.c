/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_default_type_options.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 13:43:04 by lgeorgin          #+#    #+#             */
/*   Updated: 2020/02/08 13:43:06 by lgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	defining default displaying options for all types
**	Entry:
**		custom structure - format (carrier for general displaying settings),
**		pointer to parameters array - ap_root.
**	Exit:
**		0 - exception behaviour encountered,
**		1 - processed successfully.
*/

int		apply_default_options_general(t_format *format, va_list ap_root)
{
	if (!(format->length_flag = ft_strnew(2)))
		return (0);
	format->flag.minus = 'f';
	format->flag.plus = 'f';
	format->flag.space = 'f';
	format->flag.zero = 'f';
	format->flag.hash = 'f';
	format->precision_flag = 'f';
	format->width = 0;
	format->content.sign = '+';
	format->zero_flag = 'f';
	if (format->type == 'f' || format->type == 'e' || format->type == 'g' || \
		format->type == 'F' || format->type == 'E' || format->type == 'G')
		format->precision = 6;
	else
		format->precision = 0;
	format->length_utf8 = 0;
	*format->ap_root = *ap_root;
	return (1);
}

/*
**	defining default displaying options for float
**	Entry:
**		custom structure - format (carrier for general displaying settings),
**		custom structure - flt (carrier for specific float settings),
**		calculation base value - base (for furhter multibase extension)
**	Exit:
**		1 - processed successfully.
*/

int		apply_default_options_dbl(t_format *format, t_float *flt, size_t base)
{
	if (flt->dbl.t_union.sign)
		format->content.sign = '-';
	format->base = base;
	flt->exponent = flt->dbl.t_union.exponent - EXP_DFLT;
	flt->fraction_len = 64;
	flt->zero_counter = 0;
	return (1);
}
