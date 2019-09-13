/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_unformatted_string.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 18:55:53 by gmarin            #+#    #+#             */
/*   Updated: 2019/09/06 18:55:56 by gmarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		convert_char2string(t_format *format, int a)
{
	if (!(format->content.string2show = ft_strnew(1)))
		return (0);
	format->content.string2show[0] = (unsigned char)a;
	return (1);
}

int		convert_string2string(t_format *format, char *str)
{
	if (!str)
	{
		if (!(format->content.string2show = ft_strdup("(null)")))
			return (0);
	}
	else if (!(format->content.string2show = ft_strdup(str)))
		return (0);
	return (1);
}

int		convert2string(t_format *format, va_list ap)
{
	int res;

	res = 0;
	if (format->type == '%')
		res = convert_char2string(format, '%');
	if (format->length_flag[0])
		res = apply_length(format, ap);
	else if (format->type == 'c')
		res = convert_char2string(format, va_arg(ap, int));
	else if (format->type == 's')
		res = convert_string2string(format, va_arg(ap, char *));
	else if (format->type == 'p')
		res = convert_pointer2string(format, va_arg(ap, long long int));
	else if (format->type == 'd' || format->type == 'i')
		res = convert_int2string(format, va_arg(ap, int), 10);
	else if (format->type == 'x' || format->type == 'X')
		res = convert_int2string(format, va_arg(ap, unsigned int), 16);
	else if (format->type == 'o')
		res = convert_int2string(format, va_arg(ap, unsigned int), 8);
	else if (format->type == 'u')
		res = convert_int2string(format, va_arg(ap, unsigned int), 10);
	else if (format->type == 'f' || format->type == 'F')
		res = convert_float2string(format, va_arg(ap, double));
	else if (format->type == 'e' || format->type == 'E')
		res = convert_efloat2string(format, va_arg(ap, double));
	else if (format->type == 'g' || format->type == 'G')
		res = convert_gfloat2string(format, va_arg(ap, double));
	else if (format->type == 'C')
		res = convert_char2utf8(format, va_arg(ap, int));
	else if (format->type == 'S')
	{
		//puts("OK");
		res = convert_string2utf8(format, va_arg(ap, int *));
	}
	if (format->type != 'C' && format->type != 'S')
	{
		//puts("OK");
		//printf("format->type = %c\n", format->type);
		format->length = ft_strlen(format->content.string2show);
	}
	return (res);
}
