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

// void	ft_putchar_utf8(int c)
// {
// 	unsigned char	ch[4] = {0};

// 	if (c < 0x80)
// 		write(1, &c, 1);
// 	else if (c < 0x800)
// 	{
// 		ch[0] = (c >> 6) | 0xC0;
// 		ch[1] = (c & 0x3F) | 0x80;
// 		write(1, &ch, 2);
// 	}
// 	else if (c < 0x10000)
// 	{
// 		ch[0] = (c >> 12) | 0xE0;
// 		ch[1] = ((c >> 6) & 0x3F) | 0x80;
// 		ch[2] = (c & 0x3F) | 0x80;
// 		write(1, &ch, 3);
// 	}
// 	else if (c < 0x110000)
// 	{
// 		ch[0] = (c >> 18) | 0xF0;
// 		ch[1] = ((c >> 12) & 0x3F) | 0x80;
// 		ch[2] = ((c >> 6) & 0x3F) | 0x80;
// 		ch[3] = (c & 0x3F) | 0x80;
// 		write(1, &ch, 4);
// 	}
// }

char	*get_char_utf8(t_format *format, int c)
{
	char	*str;

	if (c < 0x80)
	{
		str = (char *)ft_memalloc(sizeof(char) * 2);
		str[0] = c;
		str[1] = '\0';
	}
	else if (c < 0x800)
	{
		str = (char *)ft_memalloc(sizeof(char) * 3);
		str[0] = (c >> 6) | 0xC0;;
		str[1] = (c & 0x3F) | 0x80;
		str[2] = '\0';
	}
	else if (c < 0x10000)
	{
		str = (char *)ft_memalloc(sizeof(char) * 4);
		str[0] = (c >> 12) | 0xE0;
		str[1] = ((c >> 6) & 0x3F) | 0x80;
		str[2] = (c & 0x3F) | 0x80;
		str[3] = '\0';
	}
	else if (c < 0x110000)
	{
		str = (char *)ft_memalloc(sizeof(char) * 5);
		str[0] = (c >> 18) | 0xF0;
		str[1] = ((c >> 12) & 0x3F) | 0x80;
		str[2] = ((c >> 6) & 0x3F) | 0x80;
		str[3] = (c & 0x3F) | 0x80;
		str[4] = '\0';
	}
	return(str);
}

int		convert_char2utf8(t_format *format, int c)
{
	if (!(format->content.string2show = get_char_utf8(format, c)))
		return (0);
	format->length_utf8 = 1;
	return (1);
}

int		convert_string2utf8(t_format *format, int *str)
{
	size_t	i;
	char	*res;

	res = ft_strnew(0);
	i = 0;
	if (str && (format->precision_flag == 'f' || format->precision))
	{
		res = get_char_utf8(format, str[0]);
		while (str[++i])
		{
			if (format->precision_flag == 't' && i == format->precision)
				break ;
			res = ft_strjoin(res, get_char_utf8(format, str[i]));
		}
	}
	format->length_utf8 = i;
	if (!(format->content.string2show = ft_strdup((const char *)res)))
	{
		free(res);
		return (0);
	}
	free(res);
	return (1);
}