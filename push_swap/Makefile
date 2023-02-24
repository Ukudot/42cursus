NAME	= push_swap
NAME_BN	= checker
FLAGS	= -Wall -Werror -Wextra
CC		= gcc ${FLAGS}
RM		= rm -f
SRC 	= check.c circular_list.c circular_list2.c greed.c greed2.c \
		  greed3.c input.c input2.c push_swap.c rules.c rules2.c rules3.c \
		  stack.c three_number.c
SRC_BN	= bonus_moves.c get_next_line.c
OBJ		= ${SRC:.c=.o}
OBJ_BN	= ${SRC_BN:.c=.o}

.o:.c
	${CC} -c $< -o ${<:.c=.o}

${NAME}: ${OBJ}
	${CC} main.c ${OBJ} -o ${NAME}

bonus: ${OBJ} ${OBJ_BN}
	${CC} check_main.c ${OBJ} ${OBJ_BN} -o ${NAME_BN}

all: ${NAME}

clean:
	${RM} ${OBJ} ${OBJ_BN}

fclean: clean
	${RM} ${NAME} ${NAME_BN}

re: fclean all
