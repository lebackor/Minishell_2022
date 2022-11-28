/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multipipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebackor <lebackor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:30:10 by lebackor          #+#    #+#             */
/*   Updated: 2022/11/28 20:20:52 by lebackor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	multipipe(t_data *p, t_env *env)
{
	t_number	*nbr;
	t_number	*tmp;
	int			i;

	i = -1;
	nbr = NULL;
	nbr = create_listenb(nbr);
	while (++i < ft_strlen_3table(p->cmds_tab))
		ft_addback_number(nbr, i);
	tmp = nbr;
	i = 0;
	while (tmp != NULL)
	{
		if (tmp->number % 2 == 0)
			pipe(p->end2);
		else
			pipe(p->end);
		p->parent = fork();
		if (p->parent < 0)
			return ;
		p->stock[i] = p->parent;
		if (p->parent == 0)
			mchild_process(p, env, tmp);
		closepipe2(p, tmp, i);
		tmp = tmp->next;
		i++;
	}
	i = -1;
	while (++i < ft_strlen_3table(p->cmds_tab))
		waitpid(p->stock[i], &p->status, 0);
	//ft_exit(p, nb);
}

void	closepipe2(t_data *p, t_number *nb, int i)
{
	if (nb->number % 2 == 0)
	{
		close(p->end[0]);
		close(p->end2[1]);
	}
	else
	{
		if (i > 0)
			close(p->end2[0]);
		close(p->end[1]);
	}
}

