/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclean.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 01:14:04 by lgeorgin          #+#    #+#             */
/*   Updated: 2019/04/20 01:25:54 by lgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strclean(char **str, int len)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (i < len)
		ft_strdel(&str[i++]);
	ft_strdel(str);
	return (str);
}
