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

char	*ft_itoa_base(unsigned long long int2convert, size_t base, size_t size)
{
	char	*str;
	size_t	i;
	char	*values;

	values = "0123456789abcdef";
	i = int_length(int2convert, base);
	if (i < size)
		i = size;
	if (!(str = ft_strnew(i)))
		return (NULL);
	str[i] = '\0';
	while (int2convert / base)
	{
		str[--i] = values[int2convert % base];
		int2convert = int2convert / base;
	}
	str[--i] = values[int2convert % base];
	while (i)
		str[--i] = values[0];
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
		str[i++] = values[int2convert / base];
		int2convert %= base;
		base /= 10;
	}
	array->current_element--;
	return (i);
}

int		fill_first_elem_e(char *str, t_float *array, size_t precision)
{
	unsigned int	int2convert;
	unsigned int	base;
	char			*values;
	int				i;

	i = 0;
	values = "0123456789abcdef";
	int2convert = array->array[array->current_element];
	base = 1;
	while (int_length(base, 10) < int_length(int2convert, 10))
		base *= 10;
	while (base && i < precision)
	{
		str[i++] = values[int2convert / base];
		int2convert %= base;
		base /= 10;
		if (i == 1 && i < precision)
			str[i++] = '.';
	}
	array->current_element--;
	return (i);
}

char	*ft_itoa_base_array_precision(t_float *array, size_t base, \
										size_t zero_counter, size_t precision)
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
				str[i] = values[int2convert / base];
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

char	*ft_itoa_base_array_precision_e(t_float *array, \
										size_t base, t_format *format)
{
	char			*str;
	char			*values;
	int				i;
	unsigned int	int2convert;
	size_t			size;

	values = "0123456789abcdef";
	size = int_length_array(array, base);
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
	i = fill_first_elem_e(str, array, size);
	while (i < size)
	{
		if (array->current_element >= 0)
		{
			int2convert = array->array[array->current_element];
			base = BASE / 10;
			while (base && size - i)
			{
				str[i] = values[int2convert / base];
				int2convert %= base;
				base /= 10;
				i++;
			}
			array->current_element--;
		}
	}
	return (str);
}
