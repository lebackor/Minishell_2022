/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebackor <lebackor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 18:58:58 by lebackor          #+#    #+#             */
/*   Updated: 2022/12/01 19:39:54 by lebackor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	check_legit_files(t_data *s, t_number *nbr)
{
	int		i;
	char	*str;

	i = 0;
	s->f = 1;
	if (ft_redir_input(s, nbr) < 1)
	{
		printf("No redirections\n");
		return (0);
	}
	while (s->cmds_tab[s->i_split][i])
	{
		if (ft_strcmp(s->cmds_tab[nbr->number - 1][i], "<") == 0)
		{
			if ((s->f = open(s->cmds_tab[s->i_split][i + 1], O_RDONLY)) > 0)
			{
				if (s->f > 0)
					close(s->f);
				printf("Infile exist\n");
				ft_execution_redir(nbr, s, i, 0);
			}
				if (s->f < 0)
				{
					printf("Infile dont exist\n");
					perror(s->cmds_tab[s->i_split][i + 1]);
				}
			i++;
			return (1);
		}
		else if (ft_strcmp(s->cmds_tab[nbr->number - 1][i], ">") == 0)
		{
			if ((s->f = open(s->cmds_tab[s->i_split][i + 1], O_CREAT | O_RDWR | O_TRUNC, 0644)) > 0)
			{
				printf("Outfile detected\n");
				str = lookforpaths_give(s->all, s, (i));
				if (str != NULL)
					printf("%s\n", str);
				if (s->f < 0)
					perror(s->cmds_tab[s->i_split][i + 1]);
			}
			i++;
			return (1);
		}
		i++;
	}

	return (0);
}
int ft_execution_redir(t_number *nbr, t_data *s, int x, int a)
{
	pid_t	i;

	s->pathexec = lookforpaths_give(s->all, s, x);
	printf("%s\n", s->pathexec);
	if (s->pathexec == NULL)
		return (1);
	if (a == 0)
		dup2(s->f, STDIN_FILENO);
	else
		dup2(s->f, STDOUT_FILENO);
	i = fork();
	if (i == 0)
	{
		if (x == 0)
			execve(s->pathexec, &s->cmds_tab[nbr->number - 1][x + 2], env_node_to_str(s->all));
		else 
			execve(s->pathexec, split_str_for_redir(s->cmds_tab[nbr->number - 1], nbr), env_node_to_str(s->all));
		perror("execve");
		return (0);
	}
	else
		waitpid(i, 0, 0);
	return (1);
}

char **split_str_for_redir(char **str, t_number *nbr)
{
	int i;
	(void) nbr;
	// int j;
	//char **str1;
	//str1 = malloc(sizeof(str) * ft_strlen_2table(str));
	i = 0;
	while (str[i])
	{
		if (ft_strcmp(str[i], "<") == 0)
		{
			//free (str[i]);
			str[i] = "\0";
			while (str[i])
			{
			//	free(str[i]);
				str[i] = "\0";
				i++;
			}
			ft_print_split (str);
			return (str);
		}
		i++;
	}
	//str[nbr->number][i] = '\0';
	return (str);
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
