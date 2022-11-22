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
	char			*rdline;
	char			***cmds_tab;
	char			**cmd; //
	char			**words;
	char			*pathexec;
	char			**env;
	int				i;
	int				ac;
	int				i_split;
	int				end[2];
	int				end2[2];
	int				*stock;
	int				status;
	int				parent;
	struct t_env	*all;
}	t_data;

typedef struct t_env
{
	char			*content;
	char			*value;
	struct t_env	*next;
}	t_env;

int		ft_search_bultins(t_data *s, t_env *envp);
int		ft_search_echo(t_data *s);
int		ft_print_echo(t_data *s, t_env *env, int a);
int		ft_echo(t_data *s, t_env *env);
t_env	*ft_addback(t_env **stack, char *content, char *value);
t_env	*create_liste(t_env *env, char *content, char *value);
t_env	*put_env(t_env *env, char **envp, t_data *s);
int		ft_search_env(t_data *s);
int		ft_env(t_env *envp, t_data *s);
int		ft_search_export(t_data *s);
int		ft_export(t_data *s, t_env *envp);
int		ft_put_in_env(t_data *s, t_env *envp);
void	ft_put_first_env(t_env *env, char **envp);
void	ft_put_second_env(t_env *env, char **envp);
void	ft_clean(t_env *env, t_data *s);
int		looking_for_path(t_env *env, t_data *s);
char	*looking_access(t_env *env, t_data *s);
void	ft_print_split(char **str);
char	*ft_split_env(char *str, int count);
void	ft_addback_new_env(t_env *env, char *content, char *value);
int		ft_search_unset(t_data *s);
int		ft_unset(t_data *s, t_env **env);
void	print_list(t_env	*env);
int		ft_search_cd(t_data *s);
int		ft_cd(t_env *env, t_data *s);
int		ft_search_pwd(t_data *s);
int		ft_pwd(void);
int		ft_execution(t_env *env, t_data *s);
char	*lookforpaths(t_env *env, t_data *s);
char	**env_node_to_str(t_env *env);
int		ft_strlen_of_nodes(t_env *env);
int		ft_strlen_3table(char ***str);
void	ft_addshlvl(t_env *env);
int		ft_strlen_2table(char **str);
int		ft_redir_input(t_data *s);
char	search_export_equalvoid	multipipe(t_datapipe *p, t_nb *nb)
{
	int		i;
	t_nb	*tmp;

	i = -1;
	tmp = nb;
	while (++i < (p->ac - 3))
	{
		if (nb->number % 2 == 0)
			pipe(p->end2);
		else
			pipe(p->end);
		p->parent = fork();
		if (p->parent < 0)
			return ;
		p->stock[i] = p->parent;
		if (p->parent == 0)
			mchild_process(p, nb);
		closepipe2(p, nb, i);
		tmp = tmp->next;
	}
	i = -1;
	while (++i < (p->ac - 3))
		waitpid(p->stock[i], &p->status, 0);
	ft_exit(p, nb);
	exit(0);
}
_not(char *str);
void	ft_declare(t_env *env);
char	*lookforpaths_give(t_env *env, t_data *s, int x);
int		check_legit_files(t_data *s, int c);
int		edit_pwd_env(t_data *s, t_env *env);
/**************************************************************************** */
/*								PARSING										  */
/**************************************************************************** */

int	check_if_quotes(char q, char dq, char *str);
int	quote_or_not(char *str);
int	which_quote(char *str);
void	removal(char *dest, char *src);
void	remove_quote(char ***str);
char	***check_quotes(char *str, t_pipe *cmds_list);

void	destroy_cmds_args(char ***cmd_args);
char	***skip_isspace(char *str);
void	free_double_tab(char **str);
int	check_pipe(char *str);
int	check_syntax(char *str);
int	check_syntax2(char *str);
char	**ft_split_space(char const *s, char c);

#endif
