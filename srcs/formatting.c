/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 21:27:27 by gmarin            #+#    #+#             */
/*   Updated: 2019/09/11 21:27:29 by gmarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*join_prefix(char *s1, t_format *format)
{
	char	*str;
	char	*tmp;

	tmp = format->content.string2show;
	str = ft_strjoin(s1, format->content.string2show);
	free(tmp);
	format->length = ft_strlen(str);
	return (str);
}

char	*join_postfix(t_format *format, char *s2)
{
	char	*str;
	char	*tmp;

	tmp = format->content.string2show;
	str = ft_strjoin(format->content.string2show, s2);
	free(tmp);
	format->length = ft_strlen(str);
	return (str);
}

char	*join_strings(char *s1, char *s2, t_format *format)
{
	char	*str;

	str = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	format->length = ft_strlen(str);
	return (str);
}
