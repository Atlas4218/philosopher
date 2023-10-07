# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rastie <rastie@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/17 19:13:04 by rastie            #+#    #+#              #
#    Updated: 2023/10/06 19:15:37 by rastie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosopher 

SRC = src
INC = inc
BIN = bin
LIB = libft

SOURCE = ${SRC}/main.c\
	 ${SRC}/philos.c\
	 ${SRC}/utils.c\
	 ${SRC}/utils_2.c\
	 ${SRC}/monitor.c\
	 ${SRC}/gest_threads.c\
	 ${SRC}/parsing.c

OBJECT = ${patsubst %,${BIN}/%, ${notdir ${SOURCE:.c=.o}}}

CFLAGS = -g -pthread -Wall -Wextra -Werror
RM = rm -f
CC = cc

${BIN}/%.o : ${SRC}/%.c 
	mkdir -p ${BIN};\
		${CC} ${CFLAGS} -I${INC} -c $< -o $@

all:	${NAME}

${NAME}: ${OBJECT}
		${CC} -o ${NAME} ${OBJECT};

fsanitize:
	${CC} ${CFLAGS} -fsanitize=thread ${SOURCE} -I${INC}

clean:
	rm -rf ${BIN}

fclean:	clean
		${RM} ${NAME};\
		${RM} a.out

re:	fclean all

.PHONY: all clean fclean re
