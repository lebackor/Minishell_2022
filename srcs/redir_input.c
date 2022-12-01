/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebackor <lebackor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 18:58:58 by lebackor          #+#    #+#             */
/*   Updated: 2022/12/01 16:03:07 by lebackor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	check_legit_files(t_data *s, t_number *nbr)
{
	int		i;
	int		f;
//	char	*str;

	i = 0;
	f = 1;
	if (ft_redir_input(s, nbr) < 1)
	{
		printf("No redirections\n");
		return (0);
	}
	while (s->cmds_tab[s->i_split][i])
	{
		if (ft_strcmp(s->cmds_tab[nbr->number - 1][i], "<") == 0)
		{
			if (open(s->cmds_tab[s->i_split][i + 1], O_RDONLY) > 0)
			{
				if (f > 0)
					close(f);
				printf("Infile exist\n");
			}
				if (f < 0)
					perror(s->cmds_tab[s->i_split][i + 1]);
			i++;
			break;
		}
		else if (ft_strcmp(s->cmds_tab[nbr->number - 1][i], ">") == 0)
		{
			if (open(s->cmds_tab[s->i_split][i + 1], O_CREAT | O_RDWR | O_TRUNC, 0644) > 0)
			{
				if (f > 0)
					close(f);
				printf("Outfile detected\n");
			}
				if (f < 0)
					perror(s->cmds_tab[s->i_split][i + 1]);
			i++;
			break;
		}
		i++;
	}
//	str = lookforpaths_give(s->all, s, (i));
//	if (str != NULL)
//		printf("%s\n", str);
	return (0);
}

int	ft_redir_input(t_data *s, t_number *nbr)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (s->cmds_tab[nbr->number - 1][0][0] == '\n')
		return (-1);
	while (s->cmds_tab[nbr->number - 1][i])
	{
		if (ft_strcmp(s->cmds_tab[nbr->number - 1][i], "<") == 0 ||
		ft_strcmp(s->cmds_tab[nbr->number - 1][i], ">") == 0)
			count++;
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
