# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    script.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgeorgin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/07 19:27:55 by lgeorgin          #+#    #+#              #
#    Updated: 2019/07/27 18:50:46 by lgeorgin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

make re && gcc -I ./srcs -I ./libft main_test_original.c -L. -lftprintf -o printf && make fclean
