/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   declare_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebackor <lebackor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:02:05 by lebackor          #+#    #+#             */
/*   Updated: 2022/09/07 15:23:48 by lebackor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_declare(t_env *env)
{
	t_env	*tmp;

	tmp = env;
	while (tmp)
	{
		printf("declare -x %s=%s\n", tmp->content, tmp->value);
		tmp = tmp->next;
	}
}
