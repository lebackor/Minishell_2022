#include "../include/minishell.h"

void	ft_heredoc(t_data *s, t_env *env, t_number *nb, int a)
{
	(void) env;
//	int i;
	char 	*str;
	int		fd;
	//ouvrir un fd et dup un infile en stdin
	fd = open("tmp.txt", O_CREAT | O_RDWR | O_TRUNC, 0644);
	//i = fork();
	if (a == 0)
	{
		str = readline("> ");
		while (ft_strcmp(str, s->cmds_tab[nb->number - 1][a + 1]) != 0)
		{

			ft_putstr_fd(str, fd);
			free(str);
			str = readline("> ");
		}
		close(fd);
		return ;
	}
}
