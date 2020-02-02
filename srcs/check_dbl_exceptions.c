/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dbl_exceptions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 18:49:53 by gmarin            #+#    #+#             */
/*   Updated: 2020/01/26 18:50:31 by gmarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_double_exceptions(t_format *format, t_dbl dbl)
{
	int state;
	int	remaining_part;
	int offset;

	offset = 62;
	remaining_part = 0;
	state = dbl.t_union.mantissa >> offset;
	while (offset-- && !remaining_part)
		if (((dbl.t_union.mantissa >> offset) & 1L) == 1L)
			remaining_part = 1;
	if (state == 2 && !remaining_part)
	{
		if (!(format->content.string2show = ft_strdup("inf")))
			return (0);
	}
	else
	{
		format->content.sign = '\0';
		if (!(format->content.string2show = ft_strdup("nan")))
			return (0);
	}
	return (1);
}
