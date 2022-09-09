#include "../include/minishell.h"

int	minishell_init(t_data *s, t_env *env, t_pipe *cmds_list)
{
	char	***cmd_args;

	s->rdline = readline(MINISH _GREEN"$ " _END);
	while (s->rdline)
	{
		if (ft_strcmp(s->rdline, "exit") == 0)
			return (free (s->rdline), printf("exit\n"), 1);
		if (check_syntax(s->rdline) == 1)
			free(s->rdline);
		else
		{
			add_history(s->rdline);
			cmd_args = check_quotes(s->rdline, cmds_list);
			ft_search_bultins(s, env);
			destroy_cmds_args(cmd_args);
			free(s->rdline);
		}
		s->rdline = readline(MINISH _GREEN"$ " _END);
	}
	return (0);
}

int	main(int ac, char **av, char **envp)
{
	t_data	*s;
	t_env	*env;
	t_pipe	cmds_list;

	(void)av;
	(void)envp;
	if (ac == 1)
	{
		env = NULL;
		s = malloc(sizeof(t_data));
			*s = (t_data){0};
		env = malloc(sizeof(t_env));
			*env = (t_env){0};
		env = put_env(env, envp, s);
		minishell_init(s, env, &cmds_list);
		ft_clean(env, s);
	}
	return (0);
}
