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
