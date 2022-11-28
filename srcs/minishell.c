#include "../include/minishell.h"
#include <signal.h>

// > infile toujours apres le chevron
// SIGQUIT ET SIG_IGN a gerer avec le WAIT_PID de l'enfant
// parent en ignore, et child en default, valeur de retour dans le WAIT PID

void	handler(int signal)
{
	(void)signal;
	rl_on_new_line();
	rl_replace_line("", 1);
	printf("\n");
	rl_redisplay();
}

// void	handler_slash(int signal)
// {
// 	(void)signal;

// }

int	minishell_init(t_data *s, t_env *env, t_pipe *cmds_list)
{
	signal(SIGINT, handler);
	signal(SIGQUIT, SIG_IGN);
	s->rdline = readline(MINISH _GREEN"$ " _END);
	if (!s->rdline)
		return (1);
	while (ft_strlen(s->rdline) < 1)
	{
		free(s->rdline);
		s->rdline = readline(MINISH _GREEN"$ " _END);
	}
	while (s->rdline)
	{
		if (ft_strcmp(s->rdline, "exit") == 0)
		{
			ft_clean(env, s);
			printf("exit\n");
			exit(1);
			//return (free (s->rdline), printf("exit\n"), 1);
		}
		if (check_syntax(s->rdline) == 1)
		{
			add_history(s->rdline);
			free(s->rdline);
		}
		else
		{
			s->cmds_tab = check_quotes(s->rdline, cmds_list);
			add_history(s->rdline);
			if (ft_strlen_3table(s->cmds_tab) == 1)
			{
				check_legit_files(s, 0);
				if (ft_search_bultins(s, env) != 0)
					ft_execution(env, s);
				destroy_cmds_args(s->cmds_tab);
				free(s->rdline);
			}
			else
			{
				s->stock = malloc(sizeof(int) * ft_strlen_3table(s->cmds_tab));
				multipipe(s, env);
			}
		}
		signal(SIGINT, handler);
		s->rdline = readline(MINISH _GREEN"$ " _END);
		if (!s->rdline)
			return (1);
		while (ft_strlen(s->rdline) < 1)
		{
			free(s->rdline);
			s->rdline = readline(MINISH _GREEN"$ " _END);
		}
	}
	return (0);
}


int	main(int ac, char **av, char **envp)
{
	t_data	*s;
	t_env	*env;
	t_pipe	cmds_list;

	(void)av;
	if (ac == 1)
	{
		env = NULL;
		s = malloc(sizeof(t_data));
			*s = (t_data){0};
		env = malloc(sizeof(t_env));
			*env = (t_env){0};
		env = put_env(env, envp, s);
		if (minishell_init(s, env, &cmds_list))
			return (EXIT_SUCCESS);
		ft_clean(env, s);
	}
	return (0);
}
