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

int		check_double_exceptions_subroutine(t_format *format, t_dbl dbl)
{
	if (((dbl.t_union.mantissa >> 62) & 1L) == 0)
	{
		if (((dbl.t_union.mantissa >> 61) & 1L) == 0)
		{
			if (!(format->content.string2show = ft_strdup("inf")))
				return (0);
			return (1);
		}
		else
		{
			if (!(format->content.string2show = ft_strdup("nan")))
				return (0);
			return (1);
		}
	}
	return (2);
}

int		check_double_exceptions(t_format *format, t_dbl dbl)
{
	int state;

	if (((dbl.t_union.mantissa >> 63) & 1L) == 0)
	{
		if ((state = check_double_exceptions_subroutine(format, dbl)) == 2)
			if (!(format->content.string2show = ft_strdup("nan")))
				return (0);
	}
	else
	{
		if ((state = check_double_exceptions_subroutine(format, dbl)) == 2)
		{
			if (((dbl.t_union.mantissa >> 61) & 1L) == 0)
			{
				if (!(format->content.string2show = ft_strdup("nan")))
					return (0);
			}
			else
				if (!(format->content.string2show = ft_strdup("nan")))
					return (0);
		}
	}
	return (state);
}
