/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 21:21:57 by gmarin            #+#    #+#             */
/*   Updated: 2019/09/11 21:21:59 by gmarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_dollar(char c)
{
	if (c == '$')
		return (1);
	else
		return (0);
}

int		check_precision(char c)
{
	if (c == '.')
		return (1);
	else
		return (0);
}

int		check_width(char c)
{
	if (c >= '1' && c <= '9')
		return (1);
	else
		return (0);
}

int		check_flag(char c)
{
	char	*options;
	int		i;

	options = " #0-+hlL*";
	i = 0;
	while (options[i])
	{
		if (options[i] == c)
			return (1);
		else
			i++;
	}
	return (0);
}

/*
**	checking if encountered symbols may be classified as displaying flag
**	Entry:
**		single char - c (from original string transferred as parameter),
**		single char - mode
**		(checking modes:
**			a - all (check if symbol is part of flag or width or precision);
**			f - flag (check if symbol is part of flag);
**			w - width (check if symbol is part of width);
**			p - precision (check if symbol is part of precision);
**			$ - dollar (check if symbol is a special parameter's array
**			managing symbol);
**		)
**	Exit:
**		0 - false (nothing parameter-like (mode dependent) detected),
**		1 - true (something parameter-like (mode dependent) detected).
*/

int		check_options(char c, char mode)
{
	if (mode == 'a')
		return (check_flag(c) || check_width(c) \
				|| check_precision(c) || check_dollar(c));
	else if (mode == 'f')
		return (check_flag(c));
	else if (mode == 'w')
		return (check_width(c));
	else if (mode == 'p')
		return (check_precision(c));
	else if (mode == '$')
		return (check_dollar(c));
	return (0);
}
