/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchan <vchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 17:17:03 by lebackor          #+#    #+#             */
/*   Updated: 2022/08/31 17:56:15 by vchan            ###   ########.fr       */
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
	free(s);
}
