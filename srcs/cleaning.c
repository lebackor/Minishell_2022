/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebackor <lebackor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 17:17:03 by lebackor          #+#    #+#             */
/*   Updated: 2022/11/28 20:44:05 by lebackor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_clean(t_env *env, t_data *s)
{
	t_env	*tmp;

	tmp = env;
	while (env->next)
	{
		tmp = env;
		env = env->next;
		if (tmp)
		{
			free(tmp->content);
			free(tmp->value);
			free(tmp);
		}
	}
	free(env);
	free(s->pathexec);
	free(s->stock);
	free(s->env);
	//if (s->cmd)
	 //	ft_free_table(s->cmd);
	free(s->rdline);
	free(s);
}

char	**ft_free_table(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}
