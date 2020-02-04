/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_itoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 20:47:28 by gmarin            #+#    #+#             */
/*   Updated: 2019/09/11 20:47:30 by gmarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	fill_first_elem(char *str, t_array *array, size_t i, size_t precision)
{
	unsigned int	int2convert;
	unsigned int	base;
	char			*values;

	values = "0123456789abcdef";
	int2convert = array->array[array->current_element];
	base = BASE / 10;
	while (base > int2convert)
		base /= 10;
	while (base && precision > i)
	{
		str[i++] = values[int2convert / base];
		int2convert %= base;
		base /= 10;
	}
	array->current_element--;
	return (i);
}

size_t	fill_first_elem_e(char *str, t_array *array, size_t i, \
															size_t precision)
{
	unsigned int	int2convert;
	unsigned int	base;
	char			*values;

	values = "0123456789abcdef";
	int2convert = array->array[array->current_element];
	base = BASE / 10;
	while (base > int2convert)
		base /= 10;
	while (base && precision > i)
	{
		str[i++] = values[int2convert / base];
		int2convert %= base;
		base /= 10;
		if (i == 1 && precision > i)
			str[i++] = '.';
	}
	array->current_element--;
	return (i);
}

size_t	fill_string(char *str, t_array *array, size_t i, size_t size)
{
	char				*values;
	unsigned long int	int2convert;
	unsigned long int	base;

	values = "0123456789abcdef";
	while (size > i && array->current_element >= 0)
	{
		int2convert = array->array[array->current_element];
		base = BASE / 10;
		while (base && size > i)
		{
			str[i++] = values[int2convert / base];
			int2convert %= base;
			base /= 10;
		}
		array->current_element--;
	}
	return (i);
}

char	*ft_itoa_base_array_precision(t_array *array, size_t zero_counter, \
															size_t precision)
{
	char			*str;
	size_t			i;

	if (!(str = ft_strnew(precision)))
		return (NULL);
	str[precision] = '\0';
	i = 0;
	while (zero_counter-- && precision > i)
		str[i++] = '0';
	i = fill_first_elem(str, array, i, precision);
	i = fill_string(str, array, i, precision);
	while (precision > i)
		str[i++] = '0';
	return (str);
}

char	*ft_itoa_base_array_precision_e(t_format *format, t_array *array)
{
	char			*str;
	size_t			i;
	size_t			size;

	i = 0;
	size = array->array_len;
	if (format->precision < size - 1)
		size = format->precision + 1;
	if (format->precision || format->flag.hash == 't')
	{
		if (size + 1 < size)
			return (NULL);
		size++;
	}
	if (!(str = ft_strnew(size)))
		return (NULL);
	str[size] = '\0';
	i = fill_first_elem_e(str, array, i, size);
	i = fill_string(str, array, i, size);
	return (str);
}
