/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathparse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchan <vchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 17:14:59 by lebackor          #+#    #+#             */
/*   Updated: 2022/12/02 18:39:37 by vchan            ###   ########.fr       */
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
