/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebackor <lebackor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 17:34:34 by lebackor          #+#    #+#             */
/*   Updated: 2022/08/18 17:55:02 by lebackor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_print_split(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		printf("[%s] ", str[i]);
	printf("\n");
}

void	print_list(t_env	*env)
{
	t_env	*tmp;

	tmp = env;
	while (tmp)
	{
		printf("%s\n", tmp->content);
		tmp = tmp->next;
	}
}


int	ft_is_there_equal(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if(str[i] && str[i] == '=')
			return (0);
		i++;
	}
	return (1);
}
