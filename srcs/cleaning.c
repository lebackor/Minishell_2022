/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebackor <lebackor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 17:17:03 by lebackor          #+#    #+#             */
/*   Updated: 2022/08/16 17:17:04 by lebackor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_clean(t_env *env, t_data *s)
{
	t_env	*tmp;

	(void) s;
	tmp = env;
	while (env->next)
	{
		tmp = env;
		env = env->next;
		if (tmp)
			free(tmp);
	}
}
