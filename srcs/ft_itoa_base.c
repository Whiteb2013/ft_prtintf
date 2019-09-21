/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 20:47:28 by gmarin            #+#    #+#             */
/*   Updated: 2019/09/11 20:47:30 by gmarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_base(unsigned long long int2convert, size_t base)
{
	char	*str;
	size_t	i;
	char	*values;

	values = "0123456789abcdef";
	i = int_length(int2convert, base);
	if (!(str = ft_strnew(i)))
		return (NULL);
	str[i] = '\0';
	while (int2convert / base)
	{
		str[--i] = values[int2convert % base];
		int2convert = int2convert / base;
	}
	str[--i] = values[int2convert % base];
	return (str);
}

char	*ft_itoa_base_array(t_float *array, size_t base)
{
	char			*str;
	size_t			i;
	char			*values;
	int				elem_counter;
	unsigned int	int2convert;
	int				counter;

	elem_counter = 0;
	values = "0123456789abcdef";
	i = int_length_array(array, base);
	if (!(str = ft_strnew(i)))
		return (NULL);
	str[i] = '\0';
	/* only for decimal values for now*/
	while (elem_counter < (*array).current_element)
	{
		counter = 0;
		int2convert = (*array).array[elem_counter];
		while (!(counter++ / 4))
		{
			str[--i] = values[int2convert % base];
			int2convert = int2convert / base;
		}
		++elem_counter;
	}
	int2convert = (*array).array[elem_counter];
	while (int2convert / base)
	{
		str[--i] = values[int2convert % base];
		int2convert = int2convert / base;
	}
	str[--i] = values[int2convert % base];
	return (str);
}
