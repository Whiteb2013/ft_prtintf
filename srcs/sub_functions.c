/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_functions.c                                    :+:      :+:    :+:   */
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

int		get_decimal(size_t precision, long double a, long long int *integer)
{
	int		decimal;
	size_t	i;

	decimal = 0;
	i = 0;
	while (i++ < precision)
		a = a * 10;
	decimal = (int)a;
	if ((a - (int)a) * 10 > 5)
	{
		if (!precision)
		{
			*integer = *integer + 1;
			return (0);
		}
		return (decimal + 1);
	}
	else
		return (decimal);
}
