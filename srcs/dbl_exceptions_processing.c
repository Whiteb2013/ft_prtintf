/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_exceptions_processing.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 18:49:53 by gmarin            #+#    #+#             */
/*   Updated: 2020/01/26 18:50:31 by gmarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		dbl_check_exceptions(t_float *flt)
{
	if (((((flt->dbl.t_union.mantissa >> 63) & 1L) == 0L) || \
		flt->exponent == EXP_EXCPN - LDBL_EXP_ZERO) && flt->exponent != -LDBL_EXP_ZERO)
		return (1);
	return (0);
}

int		dbl_define_exception(t_format *format, t_float *flt)
{
	int state;
	int	remaining_part;

	flt->fraction_len = flt->fraction_len - 2;
	remaining_part = 0;
	state = flt->dbl.t_union.mantissa >> flt->fraction_len;
	while (flt->fraction_len-- && !remaining_part)
		if (((flt->dbl.t_union.mantissa >> flt->fraction_len) & 1L) == 1L)
			remaining_part = 1;
	if (state == 2 && !remaining_part)
	{
		if (!(format->content.string2show = ft_strdup("inf")))
			return (0);
	}
	else
	{
		format->content.sign = '\0';
		if (!(format->content.string2show = ft_strdup("nan")))
			return (0);
	}
	return (1);
}

int		dbl_check_limits(t_format *format, t_float *flt)
{
	if (flt->exponent == -LDBL_EXP_ZERO)
		return (0);
	else if (flt->exponent == -DBL_EXP_ZERO && format->length_flag[0] != 'L')
		return (0);
	return(1);
}
