NAME = cube3d

CC := cc
DIR := objs/
EXTRAFLAGS := -Wall -Wextra -Werror -g

SRCS := main.c exit.c keyboard.c frame.c texture.c data_gen.c raycast.c map.c screen.c utils.c minimap.c fps.c mouse.c door.c floor_ceiling.c xpmgif.c clean.c

BINS := $(addprefix ${DIR}, ${SRCS:.c=.o})

all: ${NAME}

${NAME}: ${BINS}
	@make -C libft
	@make -C mlx_linux
	${CC} ${EXTRAFLAGS} ${BINS} -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz ./libft/libft.a -o ${NAME}

${DIR}%.o: %.c cube3d.h
	@mkdir -p ${DIR}
	${CC} ${EXTRAFLAGS} -c $< -o $@

clean:
	@make -C libft clean
	@make -C mlx_linux clean
	@rm -rf ${DIR}

fclean: clean
	@make -C libft fclean
	@make -C mlx_linux clean
	@rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re