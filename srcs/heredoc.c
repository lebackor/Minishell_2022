#include "../include/minishell.h"

void	ft_heredoc(t_data *s, t_env *env, t_number *nb, int a)
{
	(void) env;
	int i;
	char *str;
	//ouvrir un fd et dup un infile en stdin
	i = 0;
	if (a == 0)
	{
		str = readline("> ");
		while (ft_strcmp(str, s->cmds_tab[nb->number - 1][a + 1]) != 0)
		{
			free(str);
			str = readline("> ");
		}
		return ;
	}
}
