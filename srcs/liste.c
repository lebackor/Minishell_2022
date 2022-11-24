/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebackor <lebackor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 17:16:57 by lebackor          #+#    #+#             */
/*   Updated: 2022/11/24 20:34:24 by lebackor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_env	*create_liste(t_env *env, char *content, char *value)
{
	env = malloc(sizeof(t_env));
	*env = (t_env){0};
	env->next = NULL;
	env->content = ft_strdup(content);
	env->value = ft_strdup(value);
	return (env);
}

t_env	*ft_addback(t_env **stack, char *content, char *value)
{
	t_env	*t_pile;

	if (*stack == NULL)
	{
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
	tmp = ft_addback(&tmp, content, value);
}

t_number	*create_listenb(t_number *nb)
{
	nb = malloc(sizeof(t_number));
	if (!nb)
		return (0);
	nb->next = NULL;
	return (nb);
}

t_number	*ft_addback_number(t_number *p, int i)
{
	t_number	*t_pile;

	if (i == 1)
	{
		p->number = 1;
		p->next = NULL;
	}
	else
	{
		t_pile = p;
		while (t_pile->next != NULL)
			t_pile = t_pile->next;
		t_pile->next = NULL;
		t_pile->next = create_listenb(p);
		if (!t_pile->next)
			return (0);
		t_pile->next->number = t_pile->number + 1;
		return (t_pile);
	}
	return (p);
}
