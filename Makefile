# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rastie <rastie@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/17 19:13:04 by rastie            #+#    #+#              #
#    Updated: 2023/06/26 14:20:38 by rastie           ###   ########.fr        #
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

clean:
	${RM} ${OBJECT};\

fclean:	clean
		${RM} ${NAME}

re:	fclean all

.PHONY: all clean fclean re
