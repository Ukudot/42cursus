NAME	= fdf
M_DIR	= mandatory
B_DIR	= bonus
SRCS	= ${M_DIR}/bresenham.c ${M_DIR}/bresenham2.c ${M_DIR}/check.c \
		  ${M_DIR}/check2.c ${M_DIR}/commands.c ${M_DIR}/commands2.c \
		  ${M_DIR}/draw.c ${M_DIR}/draw2.c ${M_DIR}/get_next_line.c \
		  ${M_DIR}/get_next_line_utils.c ${M_DIR}/main.c ${M_DIR}/map.c \
		  ${M_DIR}/matrix.c ${M_DIR}/rotate.c ${M_DIR}/utils.c \
		  ${M_DIR}/window.c
OBJS	= ${SRCS:.c=.o}
B_SRCS	= ${B_DIR}/bresenham_bonus.c ${B_DIR}/bresenham2_bonus.c \
		  ${B_DIR}/check_bonus.c \
		  ${B_DIR}/check2_bonus.c ${B_DIR}/commands_bonus.c \
		  ${B_DIR}/commands2_bonus.c \
		  ${B_DIR}/draw_bonus.c ${B_DIR}/draw2_bonus.c ${B_DIR}/draw3_bonus.c \
		  ${B_DIR}/get_next_line_bonus.c \
		  ${B_DIR}/get_next_line_utils_bonus.c ${B_DIR}/map_bonus.c \
		  ${B_DIR}/matrix_bonus.c ${B_DIR}/main_bonus.c \
		  ${B_DIR}/parallel_bonus.c \
		  ${B_DIR}/rotate_bonus.c ${B_DIR}/rotate2_bonus.c \
		  ${B_DIR}/rotate_p_front_bonus.c \
		  ${B_DIR}/rotate_p_side_bonus.c ${B_DIR}/rotate_p_top_bonus.c \
		  ${B_DIR}/rotate_s_bonus.c ${B_DIR}/sphere_bonus.c \
		  ${B_DIR}/translate_bonus.c \
		  ${B_DIR}/utils_bonus.c ${B_DIR}/window_bonus.c ${B_DIR}/zoom_bonus.c
B_OBJS	= ${B_SRCS:.c=.o}
LIBS	= libft.a libftprintf.a libmlx.a
FLAGS	= -Wall -Werror -Wextra -O3
GCC		= gcc ${FLAGS}
RM		= rm -f
MLXF	= -Lmlx -lXext -lX11 -lm #-framework OpenGL -framework AppKit

.c.o:
	gcc ${FLAGS} -c $<  -o ${<:.c=.o}

${NAME}: ${OBJS} lib
	${GCC} ${OBJS} ${LIBS} ${MLXF} -o ${NAME}

all: ${NAME}

lib:
	make -C ./libft
	cp ./libft/libft.a ./libft.a
	make -C ./ft_printf
	cp ./ft_printf/libftprintf.a ./libftprintf.a
	make -C ./minilibx-linux
	cp ./minilibx-linux/libmlx.a ./libmlx.a

clean:
	${RM} ${OBJS}
	${RM} ${B_OBJS}
	${RM} libft.a
	${RM} libftprintf.a
	${RM} libmlx.a
	make clean -C ./libft
	make clean -C ./ft_printf
	make clean -C ./minilibx-linux

fclean: clean
	${RM} ${NAME}
	make fclean -C ./libft
	make fclean -C ./ft_printf

re: fclean all

bonus: ${B_OBJS} lib
	${GCC} ${B_OBJS} ${LIBS} ${MLXF} -o ${NAME}
