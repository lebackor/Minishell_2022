/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebackor <lebackor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 14:25:54 by lebackor          #+#    #+#             */
/*   Updated: 2022/08/17 18:37:59 by lebackor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_unset(t_data *s, t_env *env)
{
	t_env	*tmp;

	tmp = env;
	if (ft_strcmp(tmp->content, ft_split_env(s->words[s->i_split + 1], 0)) == 0)
	{
		printf("fOUNDED\n");
	}
	while (tmp->next != NULL)
	{
		if (ft_strcmp(tmp->next->content, ft_split_env(s->words[s->i_split + 1], 0)) == 0)
		{
			printf("fOUNDED\n");
			free(tmp->next->content);
			free(tmp->next->value);
			tmp->next = tmp->next->next;
		}
		tmp = tmp->next;
	}
	return (0);
}
