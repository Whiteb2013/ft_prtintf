# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    script.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgeorgin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/07 19:27:55 by lgeorgin          #+#    #+#              #
#    Updated: 2019/07/10 21:02:21 by lgeorgin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

gcc ft_printf.h main_test.c ft_printf.c parameter_parser.c check_options.c apply_format.c ../libft/libft.a && ./a.out
