/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_calc_math.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 19:23:21 by gmarin            #+#    #+#             */
/*   Updated: 2020/01/26 19:23:26 by gmarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	sum_integer(t_float *a, t_float *exp)
{
	unsigned long int	sum;
	int					i;

	i = 0;
	while (i <= (*a).current_element || i <= (*exp).current_element)
	{
		sum = a->array[i] + exp->array[i];
		a->array[i + 1] += sum / BASE;
		a->array[i] = sum % BASE;
		i++;
	}
	if (a->array[i])
		a->current_element = i;
	else
		a->current_element = i - 1;
	array_cleaner(exp);
}

void	sum_integer_const(t_float *a, int array_elem_id, int digit_in_elem, unsigned long int value)
{
	t_float			b;
	unsigned int	base;

	array_cleaner(&b);
	if (a->current_element != array_elem_id)
	{
		if (!digit_in_elem)
		{
			array_elem_id++;
			digit_in_elem = BASE_LEN;
		}
		while (digit_in_elem++ != BASE_LEN)
			value *= 10;
	}
	else
	{
		base = int_length(a->array[a->current_element], 10);
		while (digit_in_elem++ != base)
			value *= 10;
	}
	b.array[array_elem_id] = value;
	b.current_element = array_elem_id;
	sum_integer(a, &b);
}

void	sum_decimal(t_float *a, t_float *exp)
{
	int					i;
	unsigned long int	mediator_next;
	unsigned long int	mediator_prev;

	i = 0;
	mediator_prev = 0;
	while (i <= a->current_element || i <= exp->current_element)
	{
		mediator_next = \
			(mediator_prev + (*a).array[i] * 10 + (*exp).array[i]) / BASE;
		(*a).array[i] = \
			(mediator_prev + (*a).array[i] * 10 + (*exp).array[i]) % BASE;
		mediator_prev = mediator_next;
		i++;
	}
	if (mediator_next)
	{
		(*a).array[i] = mediator_next;
		(*a).current_element = i;
	}
	else
		(*a).current_element = i - 1;
	array_cleaner(exp);
}

int		sum_decimal_const(t_float *a, size_t *zero_counter, \
							int array_elem_id, int digit_in_elem)
{
	unsigned int	current_value;
	unsigned int	top_element;
	unsigned int	base;
	size_t			zero_plus;

	top_element = a->current_element;
	current_value = a->array[top_element];
	sum_integer_const(a, array_elem_id, digit_in_elem, 1);
	if (a->current_element > top_element || \
		int_length(a->array[a->current_element], 10) > int_length(current_value, 10))
	{
		if (*zero_counter)
		{
			(*zero_counter)--;
			return (2);
		}
		else
		{
			if (a->current_element > top_element)
			{
				a->array[a->current_element--] = 0;
				zero_plus = int_length(current_value, 10) - \
								int_length(a->array[a->current_element], 10);
			}
			else
			{
				base = BASE;
				while (int_length(base, 10) > \
						int_length(a->array[a->current_element], 10))
					base /= 10;
				a->array[a->current_element] -= base;
				zero_plus = int_length(current_value, 10) - \
								int_length(a->array[a->current_element], 10);
			}
			*zero_counter = zero_plus;
			return (1);
		}
	}
	return (0);
}

t_float	*power(unsigned long int base, short int power, t_float *exp)
{
	int					i;
	unsigned long int	mediator_next;
	unsigned long int	mediator_prev;

	array_cleaner(exp);
	(*exp).array[0] = 1;
	while (power-- > 0)
	{
		i = 0;
		mediator_prev = 0;
		while (i <= (*exp).current_element)
		{
			mediator_next = (mediator_prev + (*exp).array[i] * base) / BASE;
			(*exp).array[i] = (mediator_prev + (*exp).array[i] * base) % BASE;
			mediator_prev = mediator_next;
			i++;
		}
		if (mediator_next)
		{
			(*exp).array[i] = mediator_next;
			(*exp).current_element = i;
		}
	}
	return (exp);
}
