#ifndef TOKEN_H
# define TOKEN_H

# include "../include/minishell.h"

typedef struct s_token // Parsing au départ des éléments
{
	int		type;
	char	*value;
	int		fd;
	int		env;
	// t_data	mini;
}	t_token;

#endif
