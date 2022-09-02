/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebackor <lebackor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:44:44 by lebackor          #+#    #+#             */
/*   Updated: 2022/09/02 18:03:58 by lebackor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_cd(t_env *env, t_data *s)
{
	(void) env;
	if (chdir(s->cmds_tab[s->i_split][s->i_split + 1]) == -1)
	{
		printf("Error, not found directory\n");
	}
	else
	{
		printf("Entered\n");
	}
	return (0);
}
/*
int	is_point(t_data *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s->words[s->i_split + 1][i])
	{
		if (s->words[s->i_split + 1][i] == '.')
			count++;
		i++;
	}
	if (count > 1)
		return (0);
	else
		return (1);
}

int	count_backslash(t_data *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s->words[s->i_split + 1][i])
	{
		if (s->words[s->i_split + 1][i] == '/')
			count++;
		i++;
	}
	return (count);
}
*/
