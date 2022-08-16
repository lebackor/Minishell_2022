/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebackor <lebackor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 17:16:57 by lebackor          #+#    #+#             */
/*   Updated: 2022/08/16 19:56:57 by lebackor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_env	*create_liste(t_env *env)
{
	env = malloc(sizeof(t_env));
	*env = (t_env){0};
	env->next = NULL;
	return (env);
}

t_env	*ft_addback(t_env **stack)
{
	t_env	*t_pile;

	if (!(*stack))
	{
		create_liste(*stack);
	}
	else
	{
		t_pile = *stack;
		while (t_pile->next != NULL)
		{
			t_pile = t_pile->next;
		}
		t_pile->next = create_liste(t_pile->next);
	}
	return (*stack);
}

void	ft_addback_new_env(t_env *env, char *content, char *value)
{
	t_env	*tmp;

	tmp = env;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = create_liste(tmp->next);
	tmp->next->content = ft_strdup(content);
	tmp->next->value = ft_strdup(value);
}
