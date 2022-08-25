/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchcmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebackor <lebackor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 17:00:50 by lebackor          #+#    #+#             */
/*   Updated: 2022/08/25 18:18:07 by lebackor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_execution(t_env *env, t_data *s)
{
	char *tmp;
	char *tmp2;
	pid_t i;

	(void) s;

	s->pathexec = lookforpaths(env, s);
	tmp = ft_strdup(s->pathexec);
	tmp2 = ft_strjoin(tmp, " ");
	tmp2 = ft_strjoin(tmp2, s->words[s->i_split + 1]);
	printf("%s\n", tmp2);
	i = fork();
	if (i == 0)
	{
		printf("avant\n");
		printf("%s \\ %s\n", s->pathexec, tmp2);
		execve(s->pathexec, &tmp2, s->env);
		printf("apres\n");
	}
	waitpid(i, 0, 0);
	return (1);
}

char	*lookforpaths(t_env *env, t_data *s)
{
	int	i;
	int	j;
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
		fini = ft_strjoin(str, s->words[s->i_split]);
		//free(str);
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

