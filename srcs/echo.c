/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebackor <lebackor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 17:17:16 by lebackor          #+#    #+#             */
/*   Updated: 2022/11/29 16:56:20 by lebackor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_echo(t_data *s, t_env *env, t_number *nbr)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (s->cmds_tab[nbr->number - 1][i] && s->cmds_tab[nbr->number - 1][i]
	[j - 1] == '-' && s->cmds_tab[nbr->number - 1][i][j] == 'n')
	{
		if (s->cmds_tab[nbr->number - 1][i][j - 1] == '-'
		&& s->cmds_tab[nbr->number - 1][i][j] == 'n')
		{
			while (s->cmds_tab[nbr->number - 1][i][j]
			&& s->cmds_tab[nbr->number - 1][i][j] == 'n')
				j++;
			if (s->cmds_tab[nbr->number - 1][i][j]
			&& s->cmds_tab[nbr->number - 1][i][j] != 'n')
				break ;
		}
		j = 1;
		i++;
	}
	if (i == 1)
		i = 0;
	ft_print_echo(s, env, i, nbr);
	return (0);
}

int	ft_print_echo(t_data *s, t_env *env, int a, t_number *nbr)
{
	int		i;
	t_env	*tmp;

	i = 1;
	if (a == 0)
	{
		while (s->cmds_tab[nbr->number - 1][i])
		{
			if (s->cmds_tab[nbr->number - 1][i][0] == '$')
			{
				tmp = env;
				while (tmp != NULL && ft_strcmp(&s->cmds_tab[nbr->number - 1][i][1],
				tmp->content) != 0)
					tmp = tmp->next;
				if (tmp == NULL)
				{
					printf("%s", s->cmds_tab[nbr->number - 1][i]);
					if (s->cmds_tab[nbr->number - 1][i + 1] != NULL)
						printf(" ");
					i++;
				}
				else if (ft_strcmp(&s->cmds_tab[nbr->number - 1][i][1],
				tmp->content) == 0)
				{
					printf("%s", tmp->value);
					if (s->cmds_tab[nbr->number - 1][i + 1] != NULL)
						printf(" ");
					i++;
				}
			}
			else
			{
				printf("%s ", s->cmds_tab[nbr->number - 1][i]);
				i++;
			}
		}
		printf("\n");
	}
	else
	{
		while (s->cmds_tab[nbr->number - 1][a])
		{
			printf("%s", s->cmds_tab[nbr->number - 1][a]);
			if (s->cmds_tab[nbr->number - 1][a + 1] != NULL)
				printf(" ");
			a++;
		}
	}
	return (0);
}
