/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebackor <lebackor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 17:16:57 by lebackor          #+#    #+#             */
/*   Updated: 2022/08/17 19:33:57 by lebackor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_env	*create_liste(t_env *env, char *content, char *value)
{
	env = malloc(sizeof(t_env));
	*env = (t_env){0};
	env->next = NULL;
	//if (content != NULL)
		env->content = ft_strdup(content);
	//if (value != NULL)
		env->value = ft_strdup(value);
	return (env);
}

t_env	*ft_addback(t_env **stack, char *content, char *value)
{
	t_env	*t_pile;

	if (*stack == NULL)
	{
		printf("e\n");
		*stack = create_liste(*stack, content, value);
	}
	else
	{
		t_pile = *stack;
		while (t_pile->next != NULL)
		{
			t_pile = t_pile->next;
		}
		t_pile->next = create_liste(t_pile->next, content, value);
	}
	return (*stack);
}

void	ft_addback_new_env(t_env *env, char *content, char *value)
{
	t_env	*tmp;

	tmp = env;
	while (tmp->next != NULL)
		tmp = tmp->next;
	//tmp->next = create_liste(tmp->next);//
	tmp = ft_addback(&tmp, content, value);
	// tmp->content = ft_strdup(content);
	// tmp->value = ft_strdup(value);
}
