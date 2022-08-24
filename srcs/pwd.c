/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebackor <lebackor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:50:24 by lebackor          #+#    #+#             */
/*   Updated: 2022/08/24 16:53:08 by lebackor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_pwd(t_env *env, t_data *s)
{
	(void) s;
	t_env *tmp;

	tmp = env;
	while (ft_strcmp(tmp->content, "PWD") != 0)
		tmp = tmp->next;
	if (tmp->value)
		printf("%s\n", tmp->value);
	return (0);
}

