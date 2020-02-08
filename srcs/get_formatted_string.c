/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_formatted_string.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 20:35:21 by gmarin            #+#    #+#             */
/*   Updated: 2019/09/06 20:35:23 by gmarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		format_string(t_format *format)
{
	int i;

	i = -1;
	if (format->precision_flag == 't')
	{
		if (!apply_precision(format))
			return (0);
	}
	if (!apply_flags(format))
		return (0);
	if (!apply_width(format))
		return (0);
	if (format->type >= 'A' && format->type <= 'Z')
		while (format->content.string2show[++i])
			format->content.string2show[i] = \
				ft_toupper(format->content.string2show[i]);
	return (1);
}
