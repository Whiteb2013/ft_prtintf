/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameter_parser_subroutines.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 17:06:22 by gmarin            #+#    #+#             */
/*   Updated: 2020/01/26 17:07:12 by gmarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		subroutine_1(t_format *format, va_list ap, int k)
{
	int wc_crutch;

	wc_crutch = va_arg(ap, size_t);
	if (wc_crutch < 0)
	{
		format->width = -(wc_crutch);
		format->flag.minus = 't';
	}
	else
		format->width = wc_crutch;
	k++;
	return (k);
}

int		subroutine_2_1(t_format *format, va_list ap, int k)
{
	int wc_crutch;

	wc_crutch = va_arg(ap, size_t);
	if (wc_crutch < 0)
	{
		if (format->type == 'f')
			format->precision = 6;
		else
			format->precision = 0;
		format->precision_flag = 'f';
	}
	else
		format->precision = wc_crutch;
	k += 2;
	return (k);
}

int		subroutine_2(const char *str, t_format *format, \
						va_list ap, int ap_array_that_is_crutch_bc_norm[2])
{
	int i;
	int k;

	i = ap_array_that_is_crutch_bc_norm[0];
	k = ap_array_that_is_crutch_bc_norm[1];
	format->precision_flag = 't';
	if (k + 1 < i && str[k + 1] == '*')
		k = subroutine_2_1(format, ap, k);
	else
	{
		format->precision = ft_atoi(&str[++k]);
		k += int_length(format->precision, 10);
	}
	if ((int)format->precision < 0)
	{
		format->width = -1 * format->precision;
		if (format->type == 'f')
			format->precision = 6;
		else
			format->precision = 0;
		format->precision_flag = 'f';
		format->flag.minus = 't';
	}
	return (k);
}
