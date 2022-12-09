################################################################################
#                                     CONFIG                                   #
################################################################################
MAKEFLAGS += 	--silent
NAME		=	pipex
NAME_BONUS	=	bonus
RM			=	rm -f
CC			=	clang
CFLAGS		=	-Wall -Wextra -Werror
# DIR_OBJS	=	./objs/
# DIR_SRCS	=	./srcs/
MKDIR		=	mkdir

# COLORS/FORMAT #
# _END		=	\e[0m
# _BOLD		=	\e[1m
# _RESET		=	\033[2K
# _GREY		=	\e[30m
# _RED		=	\e[31m
# _GREEN		=	\e[32m
# _YELLOW		=	\e[33m
# _BLUE		=	\e[34m

SRCS =		pipex/multichilds.c \
			pipex/multipipex.c \
			srcs/minishell.c\
			srcs/echo.c\
			srcs/search_bultins.c\
			srcs/env.c\
			srcs/liste.c\
			srcs/export.c\
			srcs/cleaning.c\
			srcs/pathparse.c\
			parsing/parsing.c\
			parsing/parsing2.c\
			parsing/destroy.c\
			parsing/split_space1.c\
			parsing/quote.c\
			srcs/utils.c\
			srcs/unset.c\
			srcs/cd.c\
			srcs/pwd.c\
			srcs/searchcmd.c\
			srcs/env_str.c\
			srcs/redir_input.c\
			srcs/declare_export.c\
			parsing/quote2.c\
			parsing/split_pipe.c

OBJS		= 	$(SRCS:%.c=$(DIR_OBJS)%.o)

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
