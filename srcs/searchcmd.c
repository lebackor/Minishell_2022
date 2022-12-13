/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchcmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebackor <lebackor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 17:00:50 by lebackor          #+#    #+#             */
/*   Updated: 2022/12/13 18:14:14 by lebackor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_execution(t_env *env, t_data *s)
{
	pid_t	i;
	s->pathexec = lookforpathsone(env, s);
	if (s->pathexec == NULL)
		return (1);
	i = fork();
	if (i == 0)
	{
	//	printf("%s\n", s->pathexec);
		execve(s->pathexec, s->cmds_tab[s->exec], env_node_to_str(env));
		perror("execve");
		return (0);
	}
	else
		waitpid(i, 0, 0);
	return (1);
}

char	*lookforpathsone(t_env *env, t_data *s)
{
	int		i;
	int		j;
	char	*str;
	char	*fini;

	i = -1;
	j = 1;
	if (looking_for_path(env, s) == 1)
	{
		printf("No PATH in env\n");
		return (NULL);
	}
	while (s->cmd[++i] && j != 0)
	{
		str = ft_strjoin(s->cmd[i], "/");
		fini = ft_strjoin(str, s->cmds_tab[s->i_split][0]); // 0 = car la commande se trouve au [0]
		str = NULL;
		j = access(fini, X_OK);
		if (j == 0)
		{
			return (fini);
		}
		free(fini);
		fini = NULL;
	}
	return (NULL);
}

char	*lookforpaths(t_env *env, t_data *s, t_number *nb)
{
	int		i;
	int		j;
	char	*str;
	char	*fini;

	i = -1;
	j = 1;
	if (looking_for_path(env, s) == 1)
	{
		printf("No PATH in env\n");
		return (NULL);
	}
	while (s->cmd[++i] && j != 0)
	{
		str = ft_strjoin(s->cmd[i], "/");
		fini = ft_strjoin(str, s->cmds_tab[nb->number - 1][s->exec]); // 0 = car la commande se trouve au [0]
		str = NULL;
		j = access(fini, X_OK);
		if (j == 0)
		{
			return (fini);
		}
		free(fini);
		fini = NULL;
	}
	return (NULL);
}

char	*lookforpaths_give(t_env *env, t_data *s, int x, t_number *nb)//redir input < >
{
	int		i;
	int		j;
	char	*str;
	char	*fini;

	i = -1;
	j = 1;
	if (looking_for_path(env, s) == 1)
	{
		printf("Error not found PATH\n");
		return (NULL);
	}
	while (s->cmd[++i] && j != 0)
	{
		str = ft_strjoin(s->cmd[i], "/");
		if (x == 0)
			fini = ft_strjoin(str, s->cmds_tab[nb->number - 1][x + 2]);
		else
			fini = ft_strjoin(str, s->cmds_tab[nb->number - 1][x - 1]);
		//free(str);
		str = NULL;
		j = access(fini, X_OK);
		if (j == 0)
		{
		//	printf("%s\n", fini);
			return (fini);
		}
		free(fini);
		fini = NULL;
	}
	return (NULL);
}
