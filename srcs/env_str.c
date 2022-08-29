/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebackor <lebackor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 18:03:40 by lebackor          #+#    #+#             */
/*   Updated: 2022/08/29 18:18:07 by lebackor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	**env_node_to_str(t_env *env)
{
	t_env	*tmp;
	char	**str;
	int		i;

	i = 0;
	tmp = env;
	str = NULL;
	while (tmp != NULL)
	{
		str[i] = ft_strjoin(tmp->content, "=");
		str[i] = ft_strjoin(str[i], tmp->value);
		printf("%s\n", str[i]);
		i++;
		tmp = tmp->next;
	}
	return (str);
}
