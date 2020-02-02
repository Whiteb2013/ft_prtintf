/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_rounding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 19:24:17 by lgeorgin          #+#    #+#             */
/*   Updated: 2020/01/26 19:24:29 by lgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_for_rounding(t_float *array, int array_elem_id, \
							int digit_in_elem)
{
	unsigned long int	comp_base;

	comp_base = BASE;
	if (array_elem_id == array->current_element)
		while ((int_length(comp_base, 10) - \
				int_length(array->array[array_elem_id], 10)) > 1)
			comp_base /= 10;
	while (digit_in_elem--)
		comp_base /= 10;
	if (array->array[array_elem_id] % comp_base < comp_base / 2)
		return (0);
	return (1);
}

/*
** rounding:
** 0 - applied, no impact
** 1 - applied, impact on integer
** 2 - applied, impact on leading zeros
*/

void	rounding(t_float *integer, t_float *decimal, \
					size_t *zero_counter, size_t precision)
{
	size_t	first_elem_len;
	int		array_elem_id;
	int		digit_in_elem;

	if (precision < *zero_counter)
		return ;
	array_elem_id = decimal->current_element;
	first_elem_len = int_length(decimal->array[array_elem_id], 10);
	if (precision < *zero_counter + first_elem_len)
		digit_in_elem = precision - *zero_counter;
	else
	{
		if ((array_elem_id -= (precision - *zero_counter - first_elem_len) / \
				BASE_LEN + 1) < 0)
			return ;
		digit_in_elem = (precision - *zero_counter - first_elem_len) % BASE_LEN;
	}
	if (check_for_rounding(decimal, array_elem_id, digit_in_elem))
		if (sum_decimal_const(decimal, zero_counter, \
			array_elem_id, digit_in_elem) == 1)
			sum_integer_const(integer, 0, 4, 1);
}

void	e_rounding(t_float *integer, t_float *decimal, \
					size_t *zero_counter, size_t precision)
{
	size_t	first_elem_len;
	size_t	array_length;
	int		array_elem_id;
	int		digit_in_elem;

	array_elem_id = integer->current_element;
	first_elem_len = int_length(integer->array[array_elem_id], 10);
	array_length = int_length_array(integer, 10) - 1;
	if (precision < array_length)
	{
		if (precision + 1 < first_elem_len)
			digit_in_elem = precision + 1;
		else
		{
			if ((array_elem_id -= (precision + 1 - first_elem_len) / \
					BASE_LEN + 1) < 0)
				return ;
			digit_in_elem = (precision + 1 - first_elem_len) % BASE_LEN;
		}
		if (check_for_rounding(integer, array_elem_id, digit_in_elem))
			sum_integer_const(integer, array_elem_id, digit_in_elem, 1);
	}
	else if (integer->array[array_elem_id])
		rounding(integer, decimal, zero_counter, precision - array_length);
	else if (precision < precision + *zero_counter + 1)
		rounding(integer, decimal, zero_counter, precision + *zero_counter + 1);
}
