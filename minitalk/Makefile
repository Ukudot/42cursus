NAME_SERVER	= server
NAME_CLIENT	= client
SERVER_DIR	= ./srv
CLIENT_DIR	= ./clt
SERVER		= ${SERVER_DIR}/server.c
CLIENT		= ${CLIENT_DIR}/client.c
SERVER_B	= ${SERVER_DIR}/server_bonus.c
CLIENT_B	= ${CLIENT_DIR}/client_bonus.c
SERVER_OBJ	= ${SERVER:.c=.o}
CLIENT_OBJ	= ${CLIENT:.c=.o}
CC		= gcc
FLAGS		= -Wall -Werror -Wextra
RM		= rm -f

.o:.c
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

all: lib ${NAME_SERVER} ${NAME_CLIENT}

bonus: lib
	${CC} ${FLAGS} ${SERVER_B} ./libft/libft.a ./ft_printf/libftprintf.a -o ${NAME_SERVER}
	${CC} ${FLAGS} ${CLIENT_B} ./libft/libft.a ./ft_printf/libftprintf.a -o ${NAME_CLIENT}


lib:
	make -C ./libft
	make -C ./ft_printf

${NAME_SERVER}:
	${CC} ${FLAGS} ${SERVER} ./libft/libft.a ./ft_printf/libftprintf.a -o ${NAME_SERVER}

${NAME_CLIENT}:
	${CC} ${FLAGS} ${CLIENT} ./libft/libft.a ./ft_printf/libftprintf.a -o ${NAME_CLIENT}

clean:
	make clean -C ./libft
	make clean -C ./ft_printf
	${RM} ${SERVER_OBJ} ${CLIENT_OBJ}

fclean: clean
	make fclean -C ./libft
	make fclean -C ./ft_printf
	${RM} ${NAME_SERVER} ${NAME_CLIENT}

re: fclean all
