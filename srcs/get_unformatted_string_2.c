/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_unformatted_string_2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 19:05:15 by gmarin            #+#    #+#             */
/*   Updated: 2019/09/06 19:05:18 by gmarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		convert_int2string(t_format *format, long long int a, size_t base)
{
	unsigned long long int	b;

	if (a < 0 && format->type != 'u')
	{
		format->content.sign = '-';
		b = -a;
	}
	else
		b = a;
	if (!(format->content.string2show = ft_itoa_base(b, base)))
		return (0);
	return (1);
}

int		convert_short2string(t_format *format, short a, size_t base)
{
	short					b;

	if (a < 0)
	{
		format->content.sign = '-';
		b = -a;
	}
	else
		b = a;
	if (!(format->content.string2show = ft_itoa_base(b, base)))
		return (0);
	return (1);
}

/*
** in the next function
** var "integer" contains everything before separator
** var "decimal" contains everything after separator
*/

int		convert_float2string(t_format *format, double a)
{
	long long int			integer;
	long long int			decimal;

	if (a < 0)
	{
		a *= -1;
		format->content.sign = '-';
	}
	integer = (long long int)a;
	decimal = get_decimal(format->precision, a - integer, &integer);
	if (format->precision)
	{
		if (!(format->content.string2show = ft_itoa_base(decimal, 10)))
			return (0);
		if (!apply_precision_float(format))
			return (0);
	}
	if (!(format->content.string2show = join_strings(\
		ft_itoa_base(integer, 10), format->content.string2show, format)))
		return (0);
	return (1);
}

int		convert_pointer2string(t_format *format, long long int a)
{
	if (!convert_int2string(format, a, 16))
		return (0);
	format->flag.hash = 't';
	return (1);
}
