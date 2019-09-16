/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 21:16:58 by gmarin            #+#    #+#             */
/*   Updated: 2019/09/11 21:17:00 by gmarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		apply_width(t_format *format)
{
	char	*filler_str;
	char	c;
	size_t	i;

	i = 0;
	c = ' ';
	if (format->type == 'c' || format->type == 'C')
		format->length = 1;
	if (format->type == 'S')
		format->length = format->length_utf8;
	if (format->length < format->width)
	{
		if (!(filler_str = ft_strnew(format->width - format->length)))
			return (0);
		if (format->flag.zero == 't' && format->flag.minus == 'f' \
			&& format->type != 'c' && format->type != 'C' && format->type != 's' && format->type != 'S')
			c = '0';
		while (i < format->width - format->length)
			filler_str[i++] = c;
		if (format->flag.minus == 't')
			format->content.string2show = \
				join_strings(format->content.string2show, filler_str, format);
		else
			format->content.string2show = join_strings(filler_str, \
				format->content.string2show, format);
		// next condition fix one error in basic tests (have to see this case to specify the condition)
		if (format->type != 'C' && format->type != 'S')
			format->length = format->width;
		if (format->type == 'C' || format->type == 'S')
			format->length_utf8 = format->width;
	}
	return (1);
}
