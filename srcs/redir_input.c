/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebackor <lebackor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 18:58:58 by lebackor          #+#    #+#             */
/*   Updated: 2022/09/10 15:25:27 by lebackor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
/*
	dup2(p.f1, STDIN_FILENO);
	dup2(p.end[1], STDOUT_FILENO);

	dup2(p.end[0], STDIN_FILENO);
	dup2(p.f2, STDOUT_FILENO);
*/

int	check_legit_files(t_data *s, int c)
{
	int		i;
	int		f;
	char	*str;

	i = 1;
	f = 1;
	if (ft_redir_input(s) < 1)
	{
		printf("not good\n");
		return (0);
	}
	if (c == 0)
	{
		while (s->cmds_tab[s->i_split][i] && f > 0)
		{
			printf("ee\n");
			if (open(s->cmds_tab[s->i_split][i], O_RDONLY) > 0 || s->cmds_tab[s->i_split][i + 1][0] == '<')
			{
				if (f > 0)
					close(f);
				f = open(s->cmds_tab[s->i_split][i], O_RDONLY);
				//dup2(f, STDIN_FILENO);
				if (f < 0)
					perror(s->cmds_tab[s->i_split][i]);
				i++;
			}
			i++;
		}
		str = lookforpaths_give(s->all, s, (i));
		if (str != NULL)
			printf("%s\n", str);
	}
	return (0);
}

int	ft_redir_input(t_data *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (s->cmds_tab[s->i_split][0][0] == '\n')
		return (-1);
	while (s->cmds_tab[s->i_split][i])
	{
		if ((ft_strcmp(s->cmds_tab[s->i_split][i], "<") == 0)
		&& (i != (ft_strlen_2table(s->cmds_tab[s->i_split]) - 1)))
		{
			if ((i == 0) || (ft_strcmp(s->cmds_tab[s->i_split][i - 1], "<") != 0))
			{
				printf("Good redir input detected\n");
				count++;
			}
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
