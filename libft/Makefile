NAME = libft.a

CC := cc
DIR := objs/
EXTRAFLAGS := -Wall -Wextra -Werror -g

SRCS := ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
	ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c \
	ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c \
	ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c \
	ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c \
	ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c \
	ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
	ft_lstiter.c ft_lstlast.c ft_lstnew.c ft_lstsize.c ft_lstmap.c \
	ft_substr.c ft_tolower.c ft_toupper.c ft_get_next_line.c ft_swap.c \
	ft_printf.c ft_printf_utils.c ft_putstr.c ft_endswith.c ft_sort_int_list.c \
	ft_putchar.c ft_putvoidptr.c ft_putnum.c ft_putunum.c ft_printhex.c \
	ft_flags.c ft_write.c ft_wordcount.c ft_free_split.c ft_min.c ft_max.c \
	ft_strcmp.c free_array.c ft_strreplace.c ft_split_func.c ft_split_push.c \
	ft_split_size.c ft_print_split.c

BINS := $(addprefix ${DIR}, ${SRCS:.c=.o})

all: ${NAME}

${NAME}: ${BINS}
	@ar r ${NAME} ${BINS}

${DIR}%.o: %.c libft.h ft_printf.h
	@mkdir -p ${DIR}
	@${CC} ${EXTRAFLAGS} -c $< -o $@

clean:
	@rm -rf ${DIR}

fclean: clean
	@rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re