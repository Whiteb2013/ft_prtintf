NAME = printf

SRC_DIR = ./srcs
LIB_DIR = ./libft

SRC_FILES =	main_test.c \
			ft_printf.c \
			parameter_parser.c \
			check_options.c \
			apply_format.c \
			ft_itoa_base.c \
			sub_functions.c \
			formatting.c

SRCS = $(addprefix $(SRC_DIR)/,$(SRC_FILES))
OBJS = $(SRC_FILES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LFLAGS = -I$(LIB_DIR) -I$(SRC_DIR)

all: $(NAME)

bin:
#	@$(CC) $(CFLAGS) $(LFLAGS) -c $(SRCS)
	@$(CC) $(LFLAGS) -c $(SRCS)

$(NAME): lib bin
#	@$(CC) $(CFLAGS) $(LFLAGS) $(OBJS) -L$(LIB_DIR) -lft -o $(NAME)
	@$(CC) $(LFLAGS) $(OBJS) -L$(LIB_DIR) -lft -o $(NAME)

lib:
	@make -C $(LIB_DIR)

clean:
	@rm -rf $(OBJS)
	@make -C $(LIB_DIR) clean

fclean:
	@rm -rf $(OBJS) $(NAME)
	@make -C $(LIB_DIR) fclean

re: fclean $(NAME)
