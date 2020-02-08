/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subroutines_length_calc.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 19:40:29 by gmarin            #+#    #+#             */
/*   Updated: 2020/01/26 19:40:32 by gmarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	int_length(unsigned long long int b, unsigned int base)
{
	size_t i;

	i = 0;
	while ((b = b / base))
		i++;
	return (++i);
}

size_t	int_length_array(t_array *array, unsigned int base)
{
	size_t	i;

	i = int_length(array->array[array->current_element], base) + \
			array->current_element * BASE_LEN;
	return (i);
}
