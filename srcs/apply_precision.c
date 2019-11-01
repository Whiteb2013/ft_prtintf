/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 21:14:29 by gmarin            #+#    #+#             */
/*   Updated: 2019/09/11 21:14:30 by gmarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		apply_precision_string(t_format *format)
{
	char	*tmp;

	if (format->length > format->precision)
	{
		tmp = format->content.string2show;
		if (!(format->content.string2show = \
			ft_strndup(format->content.string2show, format->precision)))
			return (0);
		free(tmp);
	}
	return (1);
}

int		apply_precision_int(t_format *format)
{
	char	*filler_str;
	size_t	i;

	i = 0;
	if (format->length < format->precision)
	{
		if (!(filler_str = ft_strnew(format->precision - format->length)))
			return (0);
		while (i < format->precision - format->length)
			filler_str[i++] = '0';
		format->content.string2show = \
			join_strings(filler_str, format->content.string2show, format);
	}
	if (!format->precision && !ft_strcmp(format->content.string2show, "0"))
	{
		ft_strclr(format->content.string2show);
		if (format->type != 'o' && format->type != 'p')
			format->flag.hash = 'f';
	}
	format->flag.zero = 'f';
	return (1);
}

int		apply_precision_float(t_format *format)
{
	format->length = ft_strlen(format->content.string2show);
	if (!apply_precision_int(format))
		return (0);
	if (!(format->content.string2show = join_prefix(".", format)))
		return (0);
	return (1);
}

int		apply_precision_float_2(t_format *format, t_float *integer, \
								t_float *decimal, size_t zero_counter)
{
	size_t	decimal_counter;
	size_t	first_elem_length;
	int		mediator;

	first_elem_length = int_length(decimal->array[0], 10);
	if (format->precision >= zero_counter + first_elem_length)
	{
		mediator = decimal->current_element - \
			(format->precision - zero_counter - first_elem_length) / BASE_LEN;
		decimal_counter = (format->precision - \
			zero_counter - first_elem_length) % BASE_LEN;
	}
	else if (format->precision >= zero_counter)
	{
		decimal->current_element = 0;
		decimal_counter = (format->precision - zero_counter) % BASE_LEN;
	}
	else
	{
		decimal->current_element = 0;
		array_cleaner(decimal);
	}
	//apply rounding within array;
	return (1);
}

int		apply_precision(t_format *format)
{
	if (format->type == 's' && !apply_precision_string(format))
		return (0);
	if (format->type == 'i' || format->type == 'd' || format->type == 'o' \
		|| format->type == 'x' || format->type == 'X' || format->type == 'u' \
		|| format->type == 'p')
		if (!apply_precision_int(format))
			return (0);
	format->length = ft_strlen(format->content.string2show);
	return (1);
}
