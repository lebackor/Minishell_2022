 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multichilds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebackor <lebackor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:30:02 by lebackor          #+#    #+#             */
/*   Updated: 2022/12/07 17:40:59 by lebackor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	mchild_process(t_data *p, t_env *env, t_number *nb)
{
	char	*str;

	str = lookforpaths(env, p, nb);
	if (!str)
	{
		printf("Malloc issue = lookforpaths\n");
		exit(1);
	}
	if (nb->number == 1)
	{
		dup2(p->end[1], STDOUT_FILENO);
	}
	else
		multidup(p, env, nb);
	closepipe(p, env, nb);
	if (check_legit_files(p, nb) == 0)
	{
		// printf("Not bultin\n");
		if (ft_search_bultins(p, env, nb) == 1)
		{
			execve(str, p->cmds_tab[nb->number - 1], p->env);
			ft_putstr_fd(":command not found\n", STDOUT_FILENO);
		}	
	}
	exit(1);
}

void	multidup(t_data *p, t_env *env, t_number *nb)
{
	(void) env;
	if (nb->number != ft_strlen_3table(p->cmds_tab))
	{
		if (nb->number % 2 == 0)
		{
			dup2(p->end[0], STDIN_FILENO);
			dup2(p->end2[1], STDOUT_FILENO);
		}
		else
		{
			dup2(p->end2[0], STDIN_FILENO);
			dup2(p->end[1], STDOUT_FILENO);
		}
	}
	else
	{
		if (nb->number % 2 == 0)
		{
			dup2(p->end[0], STDIN_FILENO);
		}
		else
		{
			dup2(p->end2[0], STDIN_FILENO);
		}
	}
}

void	closepipe(t_data *p, t_env *env, t_number *nb)
{
	(void) env;
	if (nb->number % 2 == 0)
	{
		close(p->end[0]);
		close(p->end2[1]);
		close(p->end2[0]);
		close(p->end[1]);
	}
	else
	{
		if (nb->number > 1)
		{
			close(p->end2[1]);
			close(p->end2[0]);
		}
		close(p->end[0]);
		close(p->end[1]);
	}
}
