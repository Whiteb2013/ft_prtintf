/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_unformatted_string_cs.c                        :+:      :+:    :+:   */
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
