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

int		convert_int2string(t_format *format, long long a, size_t base)
{
	unsigned long long int	b;

	// printf("a = %d\n", a);
	if (a < 0LL && format->type != 'u')
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

int		convert_intXO2string(t_format *format, unsigned long long a, size_t base)
{
	if (!(format->content.string2show = ft_itoa_base(a, base)))
		return (0);
	return (1);
}

int		convert_short2string(t_format *format, short a, size_t base)
{
	short	b;

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

int		convert_pointer2string(t_format *format, long long int a)
{
	if (!convert_int2string(format, a, 16))
		return (0);
	format->flag.hash = 't';
	return (1);
}
