#include "../include/minishell.h"

void	ft_heredoc(t_data *s, t_env *env, t_number *nb, int a)
{
	(void) env;
	char 	*str;

	s->f = open("tmp.txt", O_CREAT | O_RDWR | O_TRUNC, 0644);
	str = readline("> ");
	while (ft_strcmp(str, s->cmds_tab[nb->number - 1][a + 1]) != 0)
	{
		ft_putendl_fd(str, s->f);
		free(str);
		str = readline("> ");
	}
	ft_heredoc_execution(env, s, nb);
	//close(fd);
	return ;
}

int	ft_heredoc_execution(t_env *env, t_data *s, t_number *nbr)
{
	pid_t	i;
	if (ft_strcmp("<<", s->cmds_tab[nbr->number - 1][0]) == 0)
		s->exec += 2;
	s->pathexec = lookforpaths(env, s, nbr);
	if (s->pathexec == NULL)
	{
		printf("%s: command not found\n", s->cmds_tab[nbr->number - 1][s->exec]);
		return (1);
	}
	i = fork();
	if (i == 0)
	{
		if ((s->f = open("tmp.txt", O_RDONLY)) > 0)
			dup2(s->f, STDIN_FILENO);
		close (s->f);
		if (ft_strcmp("<<", s->cmds_tab[nbr->number - 1][0]) == 0)
		{
			execve(s->pathexec, &s->cmds_tab[nbr->number - 1][s->exec], env_node_to_str(s->all));
		}
		else
		{
			execve(s->pathexec, split_str_for_redir(s->cmds_tab[nbr->number - 1], nbr), env_node_to_str(env));
		}
		perror("execve");
		return (0);
	}
	else
		waitpid(i, 0, 0);
	return (1);
}
