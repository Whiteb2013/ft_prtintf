/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_functions.c                                      :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 21:53:16 by gmarin            #+#    #+#             */
/*   Updated: 2019/09/06 21:53:19 by gmarin           ###   ########.fr       */
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

size_t	int_length_array(t_float *array, unsigned int base)
{
	size_t			i;
	unsigned int	b;
	int				elem_counter;

	i = 0;
	b = 0;
	elem_counter = 0;
	while ((*array).current_element - elem_counter >= 0)
	{
		b = b * BASE + (*array).array[(*array).current_element - elem_counter];
		while ((b / base))
		{
			b = b / base;
			++i;
		}
		++elem_counter;
	}
	return (++i);
}

int		get_integer(t_dbl dbl, t_float *integer, short int *exponent)
{
	short int			fraction_length;
	t_float				exp;

	fraction_length = 64;
	if (*exponent != -EXP_DFLT)
		while (*exponent >= 0 && fraction_length-- > 0)
		{
			if (((dbl.t_union.mantissa >> fraction_length) & 1L) == 1L)
				sum_integer(integer, power(2, *exponent, &exp));
			--*exponent;
		}
	return (fraction_length);
}

int		get_decimal(t_dbl dbl, t_float *decimal, short int fraction_length, short int *exponent)
{
	t_float				exp;
	unsigned long int	leading_zero_flag;
	unsigned long int	mediator;
	size_t				leading_zero_counter;

	array_cleaner(&exp);
	*exponent = -*exponent;
	leading_zero_flag = 0;
	leading_zero_counter = 0;
	if (*exponent != EXP_DFLT)
	{
		while (fraction_length-- > 0)
		{
			if (((dbl.t_union.mantissa >> fraction_length) & 1L) == 1L)
				sum_decimal(decimal, power(5, *exponent, &exp));
			else if (!decimal->current_element && !decimal->array[0])
			{
				decimal->array[0] = 1;
				leading_zero_flag = 1;
			}
			else
				sum_decimal(decimal, &exp);
			++*exponent;
		}
		if (leading_zero_flag)
		{
			mediator = decimal->array[decimal->current_element];
			while ((mediator /= 10))
				leading_zero_flag *= 10;
			decimal->array[decimal->current_element] -= leading_zero_flag;
			while (decimal->array[decimal->current_element] < leading_zero_flag && leading_zero_flag > 1)
			{
				leading_zero_flag /= 10;
				++leading_zero_counter;
			}
		}
	}
	return (leading_zero_counter);
}
