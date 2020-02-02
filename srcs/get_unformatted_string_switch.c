/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_unformatted_string_switch.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 18:55:53 by gmarin            #+#    #+#             */
/*   Updated: 2019/09/06 18:55:56 by gmarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		convert2string_for_symbols(t_format *format, va_list ap, int res)
{
	if (format->type == 'c')
		res = convert_char2string(format, va_arg(ap, int));
	else if (format->type == 's')
		res = convert_string2string(format, va_arg(ap, char *));
	else if (format->type == 'C')
		res = convert_char2utf8(format, va_arg(ap, int));
	else if (format->type == 'S')
		res = convert_string2utf8(format, va_arg(ap, int *));
	return (res);
}

int		convert2string_for_digits(t_format *format, va_list ap, int res)
{
	if (format->type == 'p')
		res = convert_pointer2string(format, va_arg(ap, long long int));
	else if (format->length_flag[0])
		res = apply_length(format, ap);
	else if (format->type == 'd' || format->type == 'i')
		res = convert_int2string(format, va_arg(ap, int), 10);
	else if (format->type == 'x' || format->type == 'X')
		res = convert_xo2string(format, va_arg(ap, unsigned int), 16);
	else if (format->type == 'o' || format->type == 'O')
		res = convert_xo2string(format, va_arg(ap, unsigned int), 8);
	else if (format->type == 'u' || format->type == 'U')
		res = convert_int2string(format, va_arg(ap, unsigned int), 10);
	else if (format->type == 'f' || format->type == 'F' || \
		format->type == 'e' || format->type == 'E' || \
		format->type == 'g' || format->type == 'G')
		res = convert_double2string(format, va_arg(ap, double), 10);
	return (res);
}

int		convert2string(t_format *format, va_list ap)
{
	int res;

	res = 0;
	if (format->type == '%')
		res = convert_char2string(format, '%');
	else if (format->type == 'c' || format->type == 'C' || \
				format->type == 's' || format->type == 'S')
		res = convert2string_for_symbols(format, ap, res);
	else
		res = convert2string_for_digits(format, ap, res);
	if (res)
		format->length = ft_strlen(format->content.string2show);
	return (res);
}
