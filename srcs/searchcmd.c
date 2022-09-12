/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchcmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchan <vchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 17:00:50 by lebackor          #+#    #+#             */
/*   Updated: 2022/09/06 15:20:10 by vchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_execution(t_env *env, t_data *s)
{
	pid_t	i;
	(void) s;

	s->pathexec = lookforpaths(env, s);
	if (s->pathexec == NULL)
		return (1);
	i = fork();
	if (i == 0)
	{
		execve(s->pathexec, s->cmds_tab[s->i_split], env_node_to_str(env));
		perror("execve");
		return (0);
	}
	else
		waitpid(i, 0, 0);
	return (1);
}

char	*lookforpaths(t_env *env, t_data *s)
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
		fini = ft_strjoin(str, s->cmds_tab[s->i_split][s->i_split]);
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

char	*lookforpaths_give(t_env *env, t_data *s, int x)
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
		fini = ft_strjoin(str, s->cmds_tab[s->i_split][x]);
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