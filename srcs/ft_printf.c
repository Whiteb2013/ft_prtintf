/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 21:45:11 by gmarin            #+#    #+#             */
/*   Updated: 2019/09/06 21:45:13 by gmarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** extracting paramter and displaying settings:
** returns amount of displayed symbols or 0.
** 0 means that error encountered while exctracting
*/

int			extract_parameter(const char **str, va_list ap, va_list ap_root)
{
	int			i;
	int			k;
	t_format	*format;

	*str = *str + 1;
	if (!(format = (t_format *)ft_memalloc(sizeof(t_format))))
		return (-1);
	if ((i = get_type(*str, format, ap_root)) < 0)
		return (clean_format(format));
	if (check_type(format->type))
	{
		get_options(*str, format, ap, i);
		if (!convert2string(format, ap))
			return (clean_format(format));
		if (!format_string(format))
			return (clean_format(format));
	}
	else if (!undefined_behaviour(format))
		return (clean_format(format));
	k = display_parameter_buffer(format);
	*str = *str + i;
	if (**str)
		*str = *str + 1;
	clean_format(format);
	return (k);
}

void		set_color(const char *color, const char **str, int i)
{
	write(1, color, ft_strlen(color));
	*str = *str + i;
}

int			check_color(const char **str)
{
	if (!ft_strncmp(*str, "{black}", 7))
		set_color("\x1b[30m", str, 7);
	else if (!ft_strncmp(*str, "{red}", 5))
		set_color("\x1b[31m", str, 5);
	else if (!ft_strncmp(*str, "{green}", 7))
		set_color("\x1b[32m", str, 7);
	else if (!ft_strncmp(*str, "{yellow}", 8))
		set_color("\x1b[33m", str, 8);
	else if (!ft_strncmp(*str, "{blue}", 6))
		set_color("\x1b[34m", str, 6);
	else if (!ft_strncmp(*str, "{magenta}", 9))
		set_color("\x1b[35m", str, 9);
	else if (!ft_strncmp(*str, "{cyan}", 6))
		set_color("\x1b[36m", str, 6);
	else if (!ft_strncmp(*str, "{white}", 7))
		set_color("\x1b[37m", str, 7);
	else if (!ft_strncmp(*str, "{eoc}", 5))
		set_color("\x1b[0m", str, 5);
	else
	{
		display_static_buffer(str, 1);
		return (1);
	}
	return (0);
}

const char	*read_str(const char *str, \
					va_list ap_array_that_is_crutch_bc_norm[2], int *i, int *k)
{
	while (str[*i])
	{
		if (str[*i] == '%' || str[*i] == '{' || *i == 255)
		{
			*k = *k + display_static_buffer(&str, *i);
			if (str[0] == '{')
				*k = *k + check_color(&str);
			if (str[0] == '%')
			{
				if ((*i = extract_parameter(&str, \
							ap_array_that_is_crutch_bc_norm[0], \
							ap_array_that_is_crutch_bc_norm[1])) < 0)
				{
					va_end(ap_array_that_is_crutch_bc_norm[0]);
					return (NULL);
				}
				*k = *k + *i;
			}
			*i = 0;
		}
		else
			++*i;
	}
	return (str);
}

/*
** project function: returns an amount of displayed symbols
*/

int			ft_printf(const char *str, ...)
{
	int			k;
	int			i;
	va_list		ap;
	va_list		ap_root;
	va_list		ap_array_that_is_crutch_bc_norm[2];

	va_start(ap, str);
	*ap_root = *ap;
	*ap_array_that_is_crutch_bc_norm[0] = *ap;
	*ap_array_that_is_crutch_bc_norm[1] = *ap_root;
	i = 0;
	k = 0;
	if (!(str = read_str(str, ap_array_that_is_crutch_bc_norm, &i, &k)))
		return (-1);
	k += i;
	display_static_buffer(&str, i);
	va_end(ap);
	return (k);
}
