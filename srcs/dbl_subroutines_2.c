/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_subroutines_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 19:24:17 by lgeorgin          #+#    #+#             */
/*   Updated: 2020/01/26 19:24:29 by lgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	dbl_update_array_length(t_format *format, t_array *a)
{
	a->array_len = int_length_array(a, format->base);
	a->first_len = int_length(a->array[a->current_element], format->base);
}

int		dbl_detect_leading_zero(t_float *flt, t_array *decimal, t_array *exp)
{
	short int	counter;

	if (flt->exponent > 3 || (flt->exponent == 1 && \
		((flt->dbl.t_union.mantissa >> (flt->fraction_len - 1) & 1L) == 0L)))
	{
		counter = 2;
		decimal->array[0] = 1;
		if (flt->exponent > 3)
		{
			while (counter++ < flt->exponent)
				sum_decimal(decimal, exp);
		}
		else
		{
			flt->fraction_len--;
			flt->exponent++;
		}
		return (1);
	}
	return (0);
}

void	dbl_count_leading_zero(t_format *format, t_float *flt, \
												t_array *decimal, int flag)
{
	unsigned long int	base;

	base = BASE / format->base;
	if (flag)
	{
		while (base > decimal->array[decimal->current_element])
			base /= format->base;
		decimal->array[decimal->current_element] -= base;
	}
	while (decimal->array[decimal->current_element] < base && base)
	{
		base /= format->base;
		flt->zero_counter++;
	}
	if (!decimal->array[decimal->current_element] && decimal->current_element)
	{
		decimal->current_element--;
		dbl_count_leading_zero(format, flt, decimal, 0);
	}
}

void	dbl_get_decimal(t_format *format, t_float *flt, t_array *decimal)
{
	t_array				exp;
	int					flag;

	clean_array(&exp);
	flt->exponent = -flt->exponent;
	flag = 0;
	if (flt->exponent != EXP_DFLT && flt->fraction_len > 0)
	{
		flag = dbl_detect_leading_zero(flt, decimal, &exp);
		while (flt->fraction_len-- > 0)
		{
			((flt->dbl.t_union.mantissa >> flt->fraction_len) & 1L) == 1L ? \
				sum_decimal(decimal, power(5, flt->exponent, &exp)) : \
				sum_decimal(decimal, &exp);
			flt->exponent++;
		}
	}
	if (flag)
		dbl_count_leading_zero(format, flt, decimal, flag);
	else
		flt->zero_counter = 0;
	dbl_update_array_length(format, decimal);
}

void	dbl_get_integer(t_format *format, t_float *flt, t_array *integer)
{
	t_array				exp;

	clean_array(&exp);
	if (flt->exponent != -EXP_DFLT)
		while (flt->exponent >= 0 && flt->fraction_len-- > 0)
		{
			((flt->dbl.t_union.mantissa >> flt->fraction_len) & 1L) == 1L ? \
				sum_integer(integer, power(2, flt->exponent, &exp)) : 0;
			flt->exponent--;
		}
	dbl_update_array_length(format, integer);
}
