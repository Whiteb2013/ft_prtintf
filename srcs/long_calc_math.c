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

void	sum_integer(t_array *a, t_array *exp)
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
	clean_array(exp);
}

void	sum_integer_const(t_format *format, t_array *a, unsigned long int value)
{
	t_array			b;
	size_t			base;

	clean_array(&b);
	if (a->current_element != a->round.elem_id)
	{
		if (!a->round.digit_in_elem)
		{
			a->round.elem_id++;
			a->round.digit_in_elem = BASE_LEN;
		}
		while (a->round.digit_in_elem++ != BASE_LEN)
			value *= format->base;
	}
	else
	{
		base = int_length(a->array[a->current_element], format->base);
		while (a->round.digit_in_elem++ - base)
			value *= format->base;
	}
	b.array[a->round.elem_id] = value;
	b.current_element = a->round.elem_id;
	sum_integer(a, &b);
	dbl_update_array_length(format, a);
}

void	sum_decimal(t_array *a, t_array *exp)
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
	clean_array(exp);
}

int		sum_decimal_const(t_format *format, t_float *flt, t_array *a)
{
	unsigned int	current_value;
	int				top_element;

	top_element = a->current_element;
	current_value = a->array[top_element];
	sum_integer_const(format, a, 1);
	if (a->current_element > top_element || \
			int_length(a->array[a->current_element], format->base) > \
				int_length(current_value, format->base))
	{
		if (flt->zero_counter)
		{
			flt->zero_counter--;
			return (2);
		}
		dbl_count_leading_zero(format, flt, a, 1);
		return (1);
	}
	return (0);
}

t_array	*power(unsigned long int base, short int power, t_array *exp)
{
	int					i;
	unsigned long int	mediator_next;
	unsigned long int	mediator_prev;

	clean_array(exp);
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
