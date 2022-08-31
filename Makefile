SRCS = 		srcs/minishell.c\
			srcs/echo.c\
			srcs/search_bultins.c\
			srcs/env.c\
			srcs/liste.c\
			srcs/export.c\
			srcs/cleaning.c\
			srcs/pathparse.c\
			parsing/parsing.c\
			srcs/utils.c\
			srcs/unset.c\
			srcs/cd.c\
			srcs/pwd.c\
			srcs/searchcmd.c\
			srcs/env_str.c\

OBJS = ${SRCS:.c=.o}

CC	=	cc

 CFLAGS = -Wall -Werror -Wextra -g3 #-fsanitize=address
#CFLAGS = -Wall -Werror -Wextra -g3
LDFLAGS = -L libft -lft


LIBFT = libft/libft.a

NAME = minishell

CLEAN_FT	=	make fclean -C libft
all : ${NAME}

${NAME} :	${OBJS} $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS)  -o $@ -L /usr/lib/x86_64-linux-gnu -lreadline
	@echo "Ca arrive..."

%.o: %.c
	@${CC} ${CFLAGS} -I includes -c $< -o ${<:.c=.o}

$(LIBFT)	:
	@make -C libft

clean :
		rm -f ${OBJS} ${LIBFT}
		${CLEAN_FT}

fclean :	clean
			rm -f ${NAME}

re : fclean all

.PHONY: all clean fclean re
