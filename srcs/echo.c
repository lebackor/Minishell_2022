/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebackor <lebackor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 17:17:16 by lebackor          #+#    #+#             */
/*   Updated: 2022/09/02 18:40:56 by lebackor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_echo(t_data *s)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (s->cmds_tab[s->i_split][i])
	{
		j = 1;
		if (s->cmds_tab[s->i_split][i][j - 1] == '-'
		&& s->cmds_tab[s->i_split][i][j] == 'n')
		{
			while (s->cmds_tab[s->i_split][i][j]
			&& s->cmds_tab[s->i_split][i][j] == 'n')
				j++;
			if (s->cmds_tab[s->i_split][i][j]
			&& s->cmds_tab[s->i_split][i][j] != 'n')
				break ;
		}
		i++;
	}
	ft_print_echo(s, i);
	return (0);
}

/*
int	ft_echo(t_data *s)
{
	int	i;

	i = 1;
	while (s->cmds_tab && ft_strcmp(s->cmds_tab[s->i_split][i], "-n") == 0)
		i++;
	return (0);
}
*/
int	ft_print_echo(t_data *s, int a)
{
	int	i;

	i = 0;
	if (a == 0)
	{
		while (s->cmds_tab[s->i_split][++i])
			printf("%s ", s->cmds_tab[s->i_split][i]);
		printf("\n");
	}
	else
	{
		while (s->cmds_tab[s->i_split][a])
		{
			printf("%s", s->cmds_tab[s->i_split][a]);
			if (s->cmds_tab[s->i_split][a + 1] != NULL)
				printf(" ");
			a++;
		}
	}
	return (0);
}
