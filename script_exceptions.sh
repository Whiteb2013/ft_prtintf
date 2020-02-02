# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    script.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgeorgin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/07 19:27:55 by lgeorgin          #+#    #+#              #
#    Updated: 2020/02/02 17:39:39 by lgeorgin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

make re && gcc -I ./srcs -I ./libft main_test_exceptions.c -L. -lftprintf -o printf && make fclean && ./printf
