/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utf8.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 20:39:14 by gmarin            #+#    #+#             */
/*   Updated: 2019/09/11 20:39:16 by gmarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	add_char_to_string(t_format *format, char *str)
{
	char	*tmp;

	if (!(format->content.string2show))
		format->content.string2show = ft_strdup((const char *)str);
	else
	{
		tmp = format->content.string2show;
		format->content.string2show = ft_strjoin(tmp, str);
		free(tmp);
	}
}

void	get_char_utf8(t_format *format, int c)
{
	char	str[5];

	ft_bzero((void*)str, 5);
	if (c < 0x80)
		str[0] = c;
	else if (c < 0x800)
	{
		str[0] = (c >> 6) | 0xC0;
		str[1] = (c & 0x3F) | 0x80;
	}
	else if (c < 0x10000)
	{
		str[0] = (c >> 12) | 0xE0;
		str[1] = ((c >> 6) & 0x3F) | 0x80;
		str[2] = (c & 0x3F) | 0x80;
	}
	else if (c < 0x110000)
	{
		str[0] = (c >> 18) | 0xF0;
		str[1] = ((c >> 12) & 0x3F) | 0x80;
		str[2] = ((c >> 6) & 0x3F) | 0x80;
		str[3] = (c & 0x3F) | 0x80;
	}
	add_char_to_string(format, str);
}

int		convert_char2utf8(t_format *format, int c)
{
	size_t tmp;

	get_char_utf8(format, c);
	format->length_utf8 = 1;
	if (format->width)
	{
		tmp = format->width;
		format->width += \
			ft_strlen(format->content.string2show) - format->length_utf8;
		format->length_utf8 = tmp;
	}
	return (1);
}

int		convert_string2utf8(t_format *format, int *str)
{
	size_t	i;

	i = 0;
	if (str && (format->precision_flag == 'f' || format->precision))
	{
		get_char_utf8(format, str[0]);
		while (str[++i])
		{
			if (i == format->precision)
				break ;
			get_char_utf8(format, str[i]);
		}
	}
	format->length_utf8 = i;
	if (format->length_utf8 < format->width)
	{
		i = format->width;
		format->width += \
			ft_strlen(format->content.string2show) - format->length_utf8;
		format->length_utf8 = i;
	}
	return (1);
}
