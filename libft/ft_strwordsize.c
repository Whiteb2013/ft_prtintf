/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strwordsize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 01:35:36 by lgeorgin          #+#    #+#             */
/*   Updated: 2019/04/20 01:41:17 by lgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strwordsize(const char *s, char c)
{
	size_t	i;

	i = 0;
	if (s)
		while (*s && *s++ != c)
			i++;
	return (i);
}
