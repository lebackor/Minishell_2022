#ifndef MINISHELL_H
# define MINISHELL_H

# define _END "\e[0m"
# define _RED "\e[31m"
# define _GREY "\e[30m"
# define _YELLOW "\e[33m"
# define _GREEN "\e[32m"
# define _BLUE "\e[34m"
# define SYSCALLFAIL -1

# define MINISH _GREEN "(╯°□°）╯ ︵ ┻━┻ minishell" _END
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdarg.h>
# include <sys/wait.h>
# include <errno.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <errno.h>
# include <stdbool.h>
# include "../libft/libft.h"
# include "../include/token.h"

typedef struct s_data
{
	char	*rdline;
	char	**words;
	char	**cmd;
	char	**cmds;
	char	**args;
	int		i;
}	t_data;

typedef struct t_env
{
	char			*content;
	char			*value;
	struct t_env	*next;
}	t_env;

int ft_search_bultins(t_data *s, t_env *envp);
int ft_search_echo(t_data *s);
int ft_print_echo(t_data *s, int a);
int ft_echo(t_data *s);
t_env	*ft_addback(t_env **stack);
t_env	*create_liste(t_env *env);
t_env *put_env(t_env *env, char **envp, t_data *s);
int ft_search_env(t_data *s);
int ft_env(t_env *envp, t_data *s);
int ft_search_export(t_data *s);
int ft_export(t_data *s, t_env *envp);
int ft_put_in_env(t_data *s, t_env *envp);
void    ft_put_first_env(t_env *env, char **envp);
void    ft_put_second_env(t_env *env, char **envp);
void	ft_clean(t_env *env, t_data *s);
char    *looking_for_path(t_env *env, t_data *s);
char 	*looking_access(t_env *env, t_data *s);

/**************************************************************************** */
/*								PARSING										  */
/**************************************************************************** */
int		check_syntax(char *str);
char	***check_quotes(char *str, t_pipe *cmds_list);
char	**ft_split_space(char const *s, char c);
void	destroy_cmds_args(char ***cmd_args);
#endif
