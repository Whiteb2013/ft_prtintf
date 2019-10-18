/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_length.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 20:05:45 by gmarin            #+#    #+#             */
/*   Updated: 2019/09/06 20:05:47 by gmarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		apply_length_d(t_format *format, va_list ap)
{
	if (!ft_strcmp(format->length_flag, "h"))
		return (convert_int2string(format, \
			(short)(va_arg(ap, int)), 10));
	else if (!ft_strcmp(format->length_flag, "hh"))
		return (convert_int2string(format, (char)(va_arg(ap, int)), 10));
	else if (!ft_strcmp(format->length_flag, "l"))
		return (convert_int2string(format, va_arg(ap, long), 10));
	else if (!ft_strcmp(format->length_flag, "ll"))
		return (convert_int2string(format, va_arg(ap, long long int), 10));
	return (0);
}

int		apply_length_u(t_format *format, va_list ap)
{
	if (!ft_strcmp(format->length_flag, "h"))
		return (convert_int2string(format, \
			(short)(va_arg(ap, int)), 10));
	else if (!ft_strcmp(format->length_flag, "hh"))
		return (convert_int2string(format, (char)(va_arg(ap, int)), 10));
	else if (!ft_strcmp(format->length_flag, "l"))
		return (convert_int2string(format, va_arg(ap, unsigned long), 10));
	else if (!ft_strcmp(format->length_flag, "ll"))
		return (convert_int2string(format, va_arg(ap, unsigned long long), 10));
	return (0);
}

int		apply_length_x(t_format *format, va_list ap)
{
	if (!ft_strcmp(format->length_flag, "h"))
		return (convert_intXO2string(format, \
			(short)(va_arg(ap, unsigned int)), 16));
	else if (!ft_strcmp(format->length_flag, "hh"))
		return (convert_intXO2string(format, (char)(va_arg(ap, unsigned int)), 16));
	else if (!ft_strcmp(format->length_flag, "l"))
		return (convert_intXO2string(format, va_arg(ap, unsigned long), 16));
	else if (!ft_strcmp(format->length_flag, "ll"))
		return (convert_intXO2string(format, va_arg(ap, unsigned long long int), 16));
	return (0);
}

int		apply_length_o(t_format *format, va_list ap)
{
	if (!ft_strcmp(format->length_flag, "h"))
		return (convert_intXO2string(format, (short)(va_arg(ap, unsigned int)), 8));
	else if (!ft_strcmp(format->length_flag, "hh"))
		return (convert_intXO2string(format, (char)(va_arg(ap, unsigned int)), 8));
	else if (!ft_strcmp(format->length_flag, "l"))
		return (convert_intXO2string(format, va_arg(ap, unsigned long), 8));
	else if (!ft_strcmp(format->length_flag, "ll"))
		return (convert_intXO2string(format, va_arg(ap, unsigned long long), 8));
	return (0);
}

int		apply_length(t_format *format, va_list ap)
{
	int res;

	res = 0;
	if (format->type == 'd' || format->type == 'i')
		res = apply_length_d(format, ap);
	else if (format->type == 'u')
		res = apply_length_u(format, ap);
	else if (format->type == 'x' || format->type == 'X')
		res = apply_length_x(format, ap);
	else if (format->type == 'o')
		res = apply_length_o(format, ap);
	else if (format->type == 'f' && !ft_strcmp(format->length_flag, "l"))
		res = convert_float2string(format, va_arg(ap, double));
	else if (format->type == 'f' && !ft_strcmp(format->length_flag, "L"))
		res = convert_float2string(format, va_arg(ap, long double));
	return (res);
}
