/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebackor <lebackor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 18:03:40 by lebackor          #+#    #+#             */
/*   Updated: 2022/12/07 16:30:25 by lebackor         ###   ########.fr       */
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
	str = ft_calloc(ft_strlen_of_nodes(env), sizeof(str));
	while (tmp != NULL)
	{
		//str[i] = ft_strdup(tmp->content);
		str[i] = ft_strjoin(tmp->content, "=");
		str[i] = ft_strjoin(str[i], tmp->value);
	//	printf("%s\n", str[i]);
		i++;
		tmp = tmp->next;
	}
	return (str);
}

int	ft_strlen_of_nodes(t_env *env)
{
	t_env	*tmp;
	int		i;

	tmp = env;
	i = 0;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
