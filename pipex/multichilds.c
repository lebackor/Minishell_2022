/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multichilds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebackor <lebackor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:30:02 by lebackor          #+#    #+#             */
/*   Updated: 2022/11/24 20:18:42 by lebackor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
//#include "pipex.h"
void	mchild_process(t_data *p, t_env *env, int i)
{
	if (i == 0)
	{
	//	dup2(p->f1, STDIN_FILENO);
		dup2(p->end[1], STDOUT_FILENO);
	}
	else
		multidup(p, env, i);
	//closepipe(p, nb, i);
	//execve(p->cmd_args[p->i_split][0], p->cmd_args[i], p->env); // me faut le /bin etc
	exit(1);
}

void	multidup(t_data *p, t_env *env, int i)
{
	(void) env;
	if (i < ft_strlen_3table(p->cmds_tab))
	{
		if (i % 2 != 0)// == ou != car commence a 0 la et non 1 comme pipex
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
		if (i % 2 != 0) //
		{
			dup2(p->end[0], STDIN_FILENO);
		//	dup2(p->f2, STDOUT_FILENO);
		}
		else
		{
			dup2(p->end2[0], STDIN_FILENO);
		//	dup2(p->f2, STDOUT_FILENO);
		}
	}
}
void	closepipe(t_data *p, t_env *env, int i)
{
		(void) p;
	(void) i;
	(void) env;
	// if (i % 2 == 0)
	// {
	// 	close(p->end[0]);
	// 	close(p->end2[1]);
	// 	close(p->end2[0]);
	// 	close(p->end[1]);
	// }
	// else
	// {
	// 	if (i > 1)
	// 	{
	// 		close(p->end2[1]);
	// 		close(p->end2[0]);
	// 	}
	// 	close(p->end[0]);
	// 	close(p->end[1]);
	// }
}

/*
void	mchild_process(t_data *p, t_env *env)
{
	p->str = parse_split(p, nb);
	if (!p->str)
	{
		ft_free_table(p->paths);
		free(p->cmdargs);
		ft_putstr_fd(p->av[2], STDOUT_FILENO);
		ft_putstr_fd(": command not found\n", STDOUT_FILENO);
		exit(EXIT_FAILURE);
	}
	if (nb->number == 1)
	{
		dup2(p->f1, STDIN_FILENO);
		dup2(p->end[1], STDOUT_FILENO);
	}
	else if (nb->number != (p->ac - 3))
		multidup(p, nb);
	else if (nb->number == (p->ac - 3))
		multidup(p, nb);
	closepipe(p, nb);
	ft_free_table(p->paths);
	execve(p->str, p->avsplit, p->env);
	free(p->cmdargs);
	perror("");
	exit(1);
}



*/
