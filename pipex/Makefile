# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lebackor <lebackor@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/17 15:32:59 by lebackor          #+#    #+#              #
#    Updated: 2022/11/20 17:55:22 by lebackor         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	pipex.c\
			parsing.c\
			cleaning.c\
			multipipex.c\
			multichilds.c \
			liste.c \

OBJS = ${SRCS:.c=.o}

CC	=	gcc

CFLAGS = -Wall -Werror -Wextra -g3

NAME = pipex

all : ${NAME}

${NAME} :	${OBJS}
	@$(CC) $(CFLAGS) $(OBJS) -o $@
	@echo "Ca arrive..."

%.o: %.c
	@${CC} ${CFLAGS} -I includes -c $< -o ${<:.c=.o}

clean :
		rm -f ${OBJS}

fclean :	clean
			rm -f ${NAME}

re : fclean all

.PHONY: all clean fclean re
