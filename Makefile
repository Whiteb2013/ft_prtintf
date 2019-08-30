NAME = libftprintf.a

SRC_DIR = ./srcs
LIB_DIR = ./libft

SRC_FILES =	ft_printf.c \
			parameter_parser.c \
			check_options.c \
			get_unformatted_string.c \
			get_formatted_string.c \
			apply_width.c \
			apply_flags.c \
			apply_precision.c \
			ft_itoa_base.c \
			sub_functions.c \
			display.c \
			formatting.c \
			undefined_behavior.c \
			cleaner.c

SRC_LIB_FILES = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
				ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c \
				ft_strncpy.c ft_strcat.c ft_strlcat.c ft_strchr.c ft_strrchr.c \
				ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c \
				ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
				ft_toupper.c ft_tolower.c ft_memalloc.c ft_memdel.c ft_strnew.c \
				ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c \
				ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c \
				ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c ft_putstr.c \
				ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c \
				ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c \
				ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_strncat.c \
				ft_strtrimi.c ft_strclean.c ft_strwordcounter.c ft_strwordsize.c \
				ft_strndup.c get_next_line.c

SRCS = $(addprefix $(SRC_DIR)/,$(SRC_FILES))
SRCS += $(addprefix $(LIB_DIR)/,$(SRC_LIB_FILES))
OBJS = $(SRC_FILES:.c=.o)
OBJS += $(SRC_LIB_FILES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LFLAGS = -I ./libft/ -I ./srcs/

%.o:$(SRC_DIR)/%.c
	@$(CC) $(LFLAGS) -o $@ -c $<
#	$(CC) $(CFLAGS) $(LFLAGS) -o $@ -c $<
%.o:$(LIB_DIR)/%.c
	@$(CC) $(LFLAGS) -o $@ -c $<
#	$(CC) $(CFLAGS) $(LFLAGS) -o $@ -c $<

all: $(NAME)

#bin:
#	@$(CC) $(CFLAGS) $(LFLAGS) -c $(SRCS)
#	@$(CC) $(LFLAGS) -c $(SRCS)
#	@$(CC) $(LFLAGS) -c $(SRCS) 

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
#$(NAME): lib bin
#	@$(CC) $(CFLAGS) $(LFLAGS) $(OBJS) -L$(LIB_DIR) -lft -o $(NAME)
#	@ar rc $(NAME) $(OBJS)
#	@ar rc $(NAME) $(OBJS)
#	@ranlib $(NAME)

#lib:
#	@make -C $(LIB_DIR)

clean:
	@rm -rf *.o
#	@make -C $(LIB_DIR) clean

fclean: clean
	@rm -rf $(NAME)
#	@rm -rf $(OBJS) $(NAME)
#	@make -C $(LIB_DIR) fclean

re: fclean $(NAME)
