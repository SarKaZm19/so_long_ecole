NAME = liblibft.a

SRCS =	ft_atoi.c ft_strchr.c ft_strlcat.c ft_strlcpy.c ft_strlen.c \
		ft_strncmp.c ft_strnstr.c ft_strrchr.c \
		ft_calloc.c ft_strdup.c \
		ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
		ft_tolower.c ft_toupper.c \
		ft_bzero.c ft_memchr.c ft_memcmp.c ft_memmove.c ft_memcpy.c \
		ft_memset.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_putendl_fd.c \
		ft_itoa.c ft_split.c ft_strjoin.c ft_strtrim.c ft_substr.c \
		ft_striteri.c ft_strmapi.c \
		ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c \
		ft_lstclear_bonus.c ft_lstdelone_bonus.c ft_lstlast_bonus.c \
		ft_lstnew_bonus.c ft_lstsize_bonus.c ft_lstiter_bonus.c \
		ft_lstmap_bonus.c \
		ft_isblank.c ft_iscntrl.c ft_isgraph.c ft_ispunct.c ft_isspace.c \
		ft_isupper.c ft_islower.c ft_isxdigit.c \
		ft_strcmp.c ft_strndup.c \
		get_next_line.c get_next_line_utils.c \
		ft_free_str.c ft_free_strs_tab.c ft_free_str_return.c ft_free_strs_tab_return.c \
		ft_printf.c ft_printf_utils.c ft_print_c.c ft_print_cx.c ft_print_d.c ft_print_i.c \
		ft_print_p.c ft_print_prct.c ft_print_s.c ft_print_u.c ft_print_x.c

OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

RM = @rm -f

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
		ar -rcs $(NAME) $(OBJS)

bonus: $(OBJS) $(BONUS_OBJS)
		ar -rcs $(NAME) $(OBJS) $(BONUS_OBJS)

clean:
		$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

%.o: %.c
		@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

.PHONY: all comment clean fclean re bonus
