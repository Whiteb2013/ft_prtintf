/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 21:27:06 by gmarin            #+#    #+#             */
/*   Updated: 2019/09/11 21:27:07 by gmarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		cleaner(t_format *format)
{
	if (format)
	{
		if (format->content.string2show)
			free(format->content.string2show);
		if (format->length_flag)
			free(format->length_flag);
		free(format);
	}
	return (-1);
}

void	array_cleaner(t_float *array)
{
	int i;

	i = 0;
	while ((i < MAX_ELEM && *((*array).array + i)) \
			|| i <= (*array).current_element)
		(*array).array[i++] = 0;
	(*array).current_element = 0;
}
