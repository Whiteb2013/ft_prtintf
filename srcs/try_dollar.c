/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_dollar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 21:43:13 by gmarin            #+#    #+#             */
/*   Updated: 2019/09/06 21:43:15 by gmarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		try_dollar(const char *str, t_format *format, va_list ap, int k)
{
	if (str[k] >= '1' && str[k] <= '9')
	{
		format->width = ft_atoi(&str[k]);
		k += int_length(format->width, 10);
		if (check_options(str[k], '$'))
		{
			format->width = format->width - 1;
			*ap = *format->ap_root;
			while (format->width)
			{
				va_arg(ap, void *);
				format->width = format->width - 1;
			}
			k++;
		}
	}
	return (k);
}
