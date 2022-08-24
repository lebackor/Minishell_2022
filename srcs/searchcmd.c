/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchcmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebackor <lebackor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 17:00:50 by lebackor          #+#    #+#             */
/*   Updated: 2022/08/24 17:23:50 by lebackor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_execution(t_env *env, t_data *s)
{
	(void) s;
	printf("rgerf\n");
	s->pathexec = lookforpaths(env, s);
	execve(s->pathexec, &s->words[s->i_split + 1], s->env);
	return (1);
}

char	*lookforpaths(t_env *env, t_data *s)
{
	int	i;
	int	j;
	char	*str;

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
		j = access(str, X_OK);
		if (j == 0)
			return (str);
		free(str);
		str = NULL;
	}
	return (NULL);
}

