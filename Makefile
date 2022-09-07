# COLORS/FORMAT #
_END		=	\e[0m
_BOLD		=	\e[1m
_RESET		=	\033[2K
_GREY		=	\e[30m
_RED		=	\e[31m
_GREEN		=	\e[32m
_YELLOW		=	\e[33m
_BLUE		=	\e[34m

SRCS = 		srcs/minishell.c\
			srcs/echo.c\
			srcs/search_bultins.c\
			srcs/env.c\
			srcs/liste.c\
			srcs/export.c\
			srcs/cleaning.c\
			srcs/pathparse.c\
			parsing/parsing.c\
			parsing/split_space1.c\
			srcs/utils.c\
			srcs/unset.c\
			srcs/cd.c\
			srcs/pwd.c\
			srcs/searchcmd.c\
			srcs/env_str.c\
			srcs/redir_input.c\
			srcs/declare_export.c\

OBJS = ${SRCS:.c=.o}

CC	=	cc

 CFLAGS = -Wall -Werror -Wextra -g3 -fsanitize=address
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
