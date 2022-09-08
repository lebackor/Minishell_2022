/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebackor <lebackor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 14:25:54 by lebackor          #+#    #+#             */
/*   Updated: 2022/09/07 18:59:28 by lebackor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_unset(t_data *s, t_env **env)
{
	t_env	*tmp;
//	t_env	*save;
	int		i;

//	save = *env;
	i = 1;
//	when i delete the first elem of the env it have a heap buffer free
	if (!s->cmds_tab[s->i_split][s->i_split + 1])
	{
		printf("Nothing to unset\n");
		return (0);
	}
	/*if (ft_strcmp((*env)->content, ft_split_env(s->cmds_tab[s->i_split]
				[s->i_split + 1], 0)) == 0)
	{
		if (save->next)
		{
			save = (*env)->next;
			free((*env)->content);
			free((*env)->value);
			free(*env);
			*env = save;
		}
		else
		{
			free(*env);
			*env = NULL;
		}
		printf("LE INFINITO\n");
		return (0);
	}*/
	while (i < ft_strlen_2table(s->cmds_tab[s->i_split]))
	{
		tmp = *env;
		while (tmp->next != NULL)
		{
			if (ft_strcmp(tmp->next->content, ft_split_env(s->cmds_tab
						[s->i_split][i], 0)) == 0)
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
			}
			tmp = tmp->next;
		}
		i++;
	}
	if (!s->cmds_tab[s->i_split][i])
		return (0);
	if (tmp->next == NULL)
	{
		if (ft_strcmp(tmp->content, ft_split_env(s->cmds_tab[s->i_split]
					[s->i_split + 1], 0)) == 0)
		{
			printf("ici\n");
		}
		return (0);
	}
	return (0);
}
