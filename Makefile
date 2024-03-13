NAME = push_swap
SRCS = main.c lst_utils.c pars_utils.c stack_initialise.c free.c op_swap.c op_push.c op_rotate.c op_revrotate.c \
		sort_stacks.c sort_getter.c sort_utils.c sort_algo.c sort_set_prices.c sort_move_fts.c pars_utils2.c
OBJ = $(SRCS:.c=.o)
LIBFT = libft
LIBFTSRCS = $(addprefix $(LIBFT)/, ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
		ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strlcat.c \
		ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c \
		ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c  \
		ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strcmp.c \
		ft_flags_bonus.c ft_hexa_bonus.c ft_print_char_bonus.c ft_print_hexa_bonus.c \
		ft_print_nbr_bonus.c ft_print_string_bonus.c ft_print_unsigned_bonus.c ft_print_vptr_bonus.c \
		ft_printf_bonus.c)
CC = cc
CFLAGS = -Wall -Wextra -Werror
ARG = 

all: $(NAME)

$(NAME): libft.a $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) libft.a -o $(NAME)

libft.a:
	@make -C libft
	@cp libft/libft.a .

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

test: fclean $(NAME)
	@./$(NAME) $(ARG)

debug: fclean
	$(CC) $(CFLAGS) -g $(LIBFTSRCS) $(SRCS) -o push_swap

clean:
	rm -f $(OBJ)
	@make -C libft clean

fclean: clean
	rm -f $(NAME)
	rm -f libft.a
	@make -C libft fclean

re: fclean all

.PHONY: all libft.a test debug clean fclean re
