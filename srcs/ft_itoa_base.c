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

	// printf("nmb = %lli\n", int2convert);
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
		while (!(counter++ / BASE_LEN))
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

int		fill_first_elem(char *str, int i, t_float *array, size_t precision)
{
	unsigned int	int2convert;
	unsigned int	base;
	char			*values;

	values = "0123456789abcdef";
	int2convert = array->array[array->current_element];
	base = 1;
	while (int_length(base, 10) < int_length(int2convert, 10))
		base *= 10;
	while (base && i < precision)
	{
		str[i++] = values[int2convert/base];
		int2convert %= base;
		base /= 10;
	}
	array->current_element--;
	return (i);
}

char	*ft_itoa_base_array_precision(t_float *array, size_t base, size_t zero_counter, size_t precision)
{
	char			*str;
	char			*values;
	int				i;
	unsigned int	int2convert;

	values = "0123456789abcdef";
	if (!(str = ft_strnew(precision)))
		return (NULL);
	str[precision] = '\0';
	i = 0;
	while (zero_counter-- && i < precision)
		str[i++] = '0';
	i = fill_first_elem(str, i, array, precision);
	while (i < precision)
	{
		if (array->current_element >= 0)
		{
			int2convert = array->array[array->current_element];
			base = BASE / 10;
			while (base && precision - i)
			{
				str[i] = values[int2convert/base];
				int2convert %= base;
				base /= 10;
				i++;
			}
			array->current_element--;
		}
		else
			str[i++] = values[0];
	}
	return (str);
}
