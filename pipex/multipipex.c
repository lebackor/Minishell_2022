/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multipipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebackor <lebackor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:30:10 by lebackor          #+#    #+#             */
/*   Updated: 2022/11/22 17:22:33 by lebackor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	multipipe(t_data *p, t_env *env)
{
	int		i;
	(void) env;
	i = -1;
	while (++i < ft_strlen_3table(p->cmds_tab))
	{
		if (p->cmds_tab[i] % 2 == 0)
			pipe(p->end2);
		else
			pipe(p->end);
		p->parent = fork();
		if (p->parent < 0)
			return ;
		p->stock[i] = p->parent;
		printf("PID = %d\n", p->stock[i]);
		/*if (p->parent == 0)
			mchild_process(p, nb);
		closepipe2(p, nb, i);
	*/
	}
	i = -1;
	while (++i < ft_strlen_3table(p->cmds_tab))
		waitpid(p->stock[i], &p->status, 0);
	ft_exit(p, nb);
	exit(0);
}

/*void	multipipe(t_datapipe *p, t_nb *nb)
{
	int		i;
	t_nb	*tmp;

	i = -1;
	tmp = nb;
	while (++i < (p->ac - 3))
	{
		if (nb->number % 2 == 0)
			pipe(p->end2);
		else
			pipe(p->end);
		p->parent = fork();
		if (p->parent < 0)
			return ;
		p->stock[i] = p->parent;
		if (p->parent == 0)
			mchild_process(p, nb);
		closepipe2(p, nb, i);
		tmp = tmp->next;
	}
	i = -1;
	while (++i < (p->ac - 3))
		waitpid(p->stock[i], &p->status, 0);
	ft_exit(p, nb);
	exit(0);
}
*/
void	closepipe2(t_datapipe *p, t_nb *nb, int i)
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
