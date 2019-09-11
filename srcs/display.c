/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 21:08:32 by gmarin            #+#    #+#             */
/*   Updated: 2019/09/11 21:08:33 by gmarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** simply send last i symbols to show on screen: 0 - succesfully executed
*/

int		display_static_buffer(const char **str, int i)
{
	if (i)
	{
		write(1, *str, (size_t)i);
		*str = *str + i;
	}
	return (i);
}

int		display_parameter_buffer(t_format *format)
{
	write(1, format->content.string2show, format->length);
	return ((int)format->length);
}
