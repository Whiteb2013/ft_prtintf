# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    script.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgeorgin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/07 19:27:55 by lgeorgin          #+#    #+#              #
#    Updated: 2019/12/07 21:41:51 by lgeorgin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

clear && make re && gcc -I ./srcs -I ./libft main_test_unexp_behav.c -L. -lftprintf -o printf && make fclean && ./printf
