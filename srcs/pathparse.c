/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathparse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebackor <lebackor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 17:14:59 by lebackor          #+#    #+#             */
/*   Updated: 2022/08/29 15:14:04 by lebackor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	looking_for_path(t_env *env, t_data *s)
{
	t_env	*tmp;

	tmp = env;
	while (tmp != NULL && ft_strcmp(tmp->content, "PATH") != 0)
		tmp = tmp->next;
	if (tmp == NULL)
		return (1);
	if (ft_strcmp(tmp->content, "PATH") == 0)
		s->cmd = ft_split(tmp->value, ':');
	else
		return (printf("Not found PATH in the environment\n"));
	return (0);
}

char	*looking_access(t_env *env, t_data *s)
{
	int		i;
	int		j;
	char	*tmp;
	char	*str;

	(void) env;
	(void) s;
	i = -1;
	j = 1;
	while (s->cmd[++i] && j != 0)
	{
		tmp = ft_strjoin(s->cmd[i], "/");
		str = ft_strjoin(tmp, s->cmds_tab[s->i_split][i]);
		free(tmp);
		j = access(str, X_OK);
		if (j == 0)
		{
			printf("%s\n", str);
			return (str);
		}
		free(str);
		str = NULL;
	}
	return (NULL);
}

/*
char	*parsep1(t_data *p)
{
	char	*raciste;
	int		i;

	i = -1;
	while (p->paths[++i] && p->j != 0)
	{
		raciste = ft_strjoin(p->paths[i], "/");
		p->cmdargs = ft_strjoin(raciste, p->avsplit[0]);
		free(raciste);
		p->j = access(p->cmdargs, X_OK);
		if (p->j == 0)
			return (p->cmdargs);
		free(p->cmdargs);
		p->cmdargs = NULL;
	}
	return (NULL);
}*/
