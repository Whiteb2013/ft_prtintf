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

/*
**	adopting string according to displaying rules for activated precision
**	flag stored in 'format' structure for type 's'
**	Entry:
**		custom structure - format (carrier for general displaying settings).
**	Exit:
**		0 - exception behaviour encountered,
**		1 - processed successfully.
*/

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

/*
**	adopting string according to displaying rules for activated precision
**	flag stored in 'format' structure for types 'i', 'd', 'o', 'O', 'x',
**	'X', 'u', 'U', 'p'
**	Entry:
**		custom structure - format (carrier for general displaying settings).
**	Exit:
**		0 - exception behaviour encountered,
**		1 - processed successfully.
*/

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
		if (format->type != 'o' && format->type != 'O' && format->type != 'p')
			format->flag.hash = 'f';
	}
	format->flag.zero = 'f';
	return (1);
}

/*
**	adopting string according to displaying rules for activated precision
**	flag stored in 'format' structure
**	Entry:
**		custom structure - format (carrier for general displaying settings).
**	Exit:
**		0 - exception behaviour encountered,
**		1 - processed successfully.
*/

int		apply_precision(t_format *format)
{
	if (format->type == 's')
	{
		if (!apply_precision_string(format))
			return (0);
	}
	if (format->type == 'i' || format->type == 'd' || format->type == 'o' || \
		format->type == 'O' || format->type == 'x' || format->type == 'X' ||
		format->type == 'u' || format->type == 'U' || format->type == 'p')
		if (!apply_precision_int(format))
			return (0);
	format->length = ft_strlen(format->content.string2show);
	return (1);
}
