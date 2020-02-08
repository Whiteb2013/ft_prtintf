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

int		clean_format(t_format *format)
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

void	clean_array(t_array *array)
{
	//int i;

	//i = 0;
	while (array->current_element >= 0)
		array->array[array->current_element--] = 0;
	array->current_element = 0;
}


void	clean_array_initial(t_array *array)
{
	int i;

	i = 0;
	while (i <= MAX_ELEM)
		array->array[i++] = 0;
	array->current_element = 0;
}
