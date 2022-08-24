/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebackor <lebackor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 14:25:54 by lebackor          #+#    #+#             */
/*   Updated: 2022/08/24 16:58:39 by lebackor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_unset(t_data *s, t_env *env)
{
	t_env	*tmp;
//	when i delete the first elem of the env it have a heap buffer free
	if (ft_strcmp(env->content, ft_split_env(s->words[s->i_split + 1], 0)) == 0)
	{
		printf("fOUNDED\n");
		tmp = env;
		env = env->next;
		free(tmp->content);
		free(tmp->value);
		free(tmp);
		tmp = NULL;
		return (0);
	}
	tmp = env;
	while (tmp->next != NULL)
	{
		if (ft_strcmp(tmp->next->content, ft_split_env(s->words[s->i_split + 1], 0)) == 0)
		{
			printf("xxfOUNDED\n");
			free(tmp->next->content);
			free(tmp->next->value);
			if (tmp->next->next != NULL)
				tmp->next = tmp->next->next;
			else if (!tmp->next->next)
			{
				tmp->next = NULL;
				free(tmp->next);
			}
			return 0;
		}
		tmp = tmp->next;
	}
	if (tmp->next == NULL)
	{
		if (ft_strcmp(tmp->content, ft_split_env(s->words[s->i_split + 1], 0)) == 0)
		{
			printf("ici\n");
		}
		return (0);
	}
	return (0);
}
