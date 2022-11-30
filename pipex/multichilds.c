/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multichilds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchan <vchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:30:02 by lebackor          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/11/30 16:04:22 by vchan            ###   ########.fr       */
=======
/*   Updated: 2022/11/30 18:15:18 by lebackor         ###   ########.fr       */
>>>>>>> 7d19203 (test commit check if git pull.ff worked)
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	mchild_process(t_data *p, t_env *env, t_number *nb)
{
	char	*str;

	str = lookforpaths(env, p, nb);
	if (nb->number == 1)
	{
		dup2(p->end[1], STDOUT_FILENO);
	}
	else
		multidup(p, env, nb);
	closepipe(p, env, nb);
	if (ft_search_bultins(p, env, nb) == 1)
	{
		// printf("Not bultin\n");
		execve(str, p->cmds_tab[nb->number - 1], p->env);
		ft_putstr_fd(":command not found\n", STDOUT_FILENO);
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
