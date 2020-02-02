/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_functions.c                                    :+:      :+:    :+:   */
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
			((dbl.t_union.mantissa >> fraction_length) & 1L) == 1L ? \
				sum_integer(integer, power(2, *exponent, &exp)) : 0;
			--*exponent;
		}
	return (fraction_length);
}

int		detect_leading_zero(t_float *decimal, short int *fraction_length, \
							short int *exponent, t_float *exp)
{
	short int	counter;

	counter = 2;
	decimal->array[0] = 1;
	if (*exponent > 3)
	{
		while (counter++ < *exponent)
			sum_decimal(decimal, exp);
	}
	else
	{
		--*fraction_length;
		++*exponent;
	}
	return (1);
}

size_t	count_leading_zero(t_float *decimal, int flag, size_t *zero_counter)
{
	unsigned long int	base;

	base = BASE / 10;
	if (flag)
	{
		while (base > decimal->array[decimal->current_element])
			base /= 10;
		decimal->array[decimal->current_element] -= base;
	}
	while (decimal->array[decimal->current_element] < base && base)
	{
		base /= 10;
		++*zero_counter;
	}
	if (!decimal->array[decimal->current_element] && decimal->current_element)
	{
		decimal->current_element--;
		count_leading_zero(decimal, 0, zero_counter);
	}
	return (*zero_counter);
}

size_t	get_decimal(t_dbl dbl, t_float *decimal, \
					short int fraction_length, short int *exponent)
{
	t_float				exp;
	size_t				zero_counter;
	int					flag;

	array_cleaner(&exp);
	*exponent = -*exponent;
	flag = 0;
	zero_counter = 0;
	if (*exponent != EXP_DFLT && fraction_length > 0)
	{
		if (*exponent > 3 || (*exponent == 1 && \
			((dbl.t_union.mantissa >> (fraction_length - 1) & 1L) == 0L)))
			flag = detect_leading_zero(decimal, &fraction_length, \
			exponent, &exp);
		while (fraction_length-- > 0)
		{
			((dbl.t_union.mantissa >> fraction_length) & 1L) == 1L ? \
				sum_decimal(decimal, power(5, *exponent, &exp)) : \
				sum_decimal(decimal, &exp);
			++*exponent;
		}
	}
	return (flag ? count_leading_zero(decimal, flag, &zero_counter) : 0);
}
