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

int		fill_first_elem(char *str, int i, t_float *array, size_t *dec_length)
{
	unsigned int	int2convert;
	unsigned int	base;
	char			*values;

	values = "0123456789";
	int2convert = array->array[array->current_element];
	base = 1;
	while (int_length(base, 10) < int_length(int2convert, 10))
		base *= 10;
	while (base && (*dec_length)--)
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
	size_t			dec_length;
	int				i;
	unsigned int	int2convert;

	values = "0123456789";
	dec_length = int_length_array(array, base) + zero_counter;
	if (precision < dec_length)
		dec_length = precision;
	if (!(str = ft_strnew(dec_length)))
		return (NULL);
	str[dec_length] = '\0';
	i = 0;
	while (zero_counter-- && dec_length)
	{
		str[i++] = '0';
		dec_length--;
	}
	i = fill_first_elem(str, i, array, &dec_length);
	/*
	while (array->current_element && dec_length)
	{
		int2convert = array->array[array->current_element];
		base = BASE / 10;
		while (base && dec_length--)
		{
			str[i++] = values[int2convert/base];
			int2convert %= base;
			base /= 10;
		}
		array->current_element--;
	}
	*/
	return (str);
}
