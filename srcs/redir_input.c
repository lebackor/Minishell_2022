/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebackor <lebackor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 18:58:58 by lebackor          #+#    #+#             */
/*   Updated: 2022/09/07 15:11:21 by lebackor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
/*
	dup2(p.f1, STDIN_FILENO);
	dup2(p.end[1], STDOUT_FILENO);

	dup2(p.end[0], STDIN_FILENO);
	dup2(p.f2, STDOUT_FILENO);
*/

int	ft_redir_input(t_data *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s->cmds_tab[s->i_split][i])
	{
		if ((ft_strcmp(s->cmds_tab[s->i_split][i], "<") == 0) && (i != (ft_strlen_2table(s->cmds_tab[s->i_split]) -	 1)))
		{
			printf("Good redir input detected\n");
			count++;
		}
		i++;
	}
	if (count == 0)
		return (0);
	else
		return (count);

}
/*
int ft_redir_first_arg(t_data *s)
{

}
*/
