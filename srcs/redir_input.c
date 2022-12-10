/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebackor <lebackor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 18:58:58 by lebackor          #+#    #+#             */
/*   Updated: 2022/12/09 17:59:46 by lebackor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	check_legit_files(t_data *s, t_number *nbr)
{
	int		i;

	i = 0;
	s->f = 1;
	if (ft_redir_input(s, nbr) < 1)
	{
		//printf("No redirections\n");
		return (0);
	}
	while (s->cmds_tab[s->i_split][i])
	{
		if (ft_strcmp(s->cmds_tab[nbr->number - 1][i], "<") == 0)
		{
			if ((s->f = open(s->cmds_tab[nbr->number - 1][i + 1], O_RDONLY)) > 0)
			{
				printf("Infile exist\n");
				ft_execution_redir(nbr, s, i, 0);
				if (s->f > 0)
					close(s->f);
			}
				if (s->f < 0)
				{
					printf("Infile dont exist\n");
					perror(s->cmds_tab[s->i_split][i + 1]);
				}
		//	i++;
			return (1);
		}
		else if (ft_strcmp(s->cmds_tab[nbr->number - 1][i], ">") == 0)
		{
			if ((s->f = open(s->cmds_tab[nbr->number - 1][i + 1], O_CREAT | O_RDWR | O_TRUNC, 0644)) > 0)
			{
				printf("Outfile detected\n");
				ft_execution_redir(nbr, s, i, 1);
				if (s->f < 0)
					perror(s->cmds_tab[s->i_split][i + 1]);
			}
		//	i++;
			return (1);
		}
		else if (ft_strcmp(s->cmds_tab[nbr->number - 1][i], "<<") == 0 && s->cmds_tab[nbr->number - 1][i + 1])
		{
			printf("heredoc detected\n");
			if (i == 0)
				ft_heredoc(s, s->all, nbr, i);
			return (1);
		}
		i++;
	}
	return (0);
}
int ft_execution_redir(t_number *nbr, t_data *s, int x, int a)
{
	pid_t	i;

	s->pathexec = lookforpaths_give(s->all, s, x, nbr);
	//printf("%s\n", s->pathexec);
	if (s->pathexec == NULL)
		return (1);
	if (ft_strlen_3table(s->cmds_tab) == 1)
	{
		i = fork();
		if (i == 0)
		{
			if (a == 0)
				dup2(s->f, STDIN_FILENO);
			else
				dup2(s->f, STDOUT_FILENO);
			if (x == 0)
			{
				close(s->f);
				execve(s->pathexec, &s->cmds_tab[nbr->number - 1][x + 2], env_node_to_str(s->all));
			}
			else
			{
				close(s->f);
				execve(s->pathexec, split_str_for_redir(s->cmds_tab[nbr->number - 1], nbr), env_node_to_str(s->all));
			}
			perror("execve");
			return (0);
		}
		else
			waitpid(i, 0, 0);
	}
	else
	{
		if (a == 0)
			dup2(s->f, STDIN_FILENO);
		else
			dup2(s->f, STDOUT_FILENO);
		if (x == 0)
		{
			close(s->f);
			execve(s->pathexec, &s->cmds_tab[nbr->number - 1][x + 2], env_node_to_str(s->all));
		}
		else
		{
			close(s->f);
			execve(s->pathexec, split_str_for_redir(s->cmds_tab[nbr->number - 1], nbr), env_node_to_str(s->all));
		}
		perror("execve");
		return (0);
	}
	return (1);
}

static int count_word(char **str)
{
	int i = 0;
	int count = 0;

	while (str[i])
	{
		if (!(ft_strcmp(str[i], "<") == 0
			|| ft_strcmp(str[i], ">") == 0) && !(i > 0 && (ft_strcmp(str[i - 1], "<") == 0
			|| ft_strcmp(str[i - 1], ">") == 0)))
			count++;
		i++;
	}
	return (count);
}

char **split_str_for_redir(char **str, t_number *nbr)
{
	int i;
	int j;
	(void) nbr;
	char **str1;
	str1 = NULL;
	// str1 = malloc(sizeof(char *) * (ft_strlen_2table(str) + 1));
	printf("%d\n", count_word(str));
	str1 = ft_calloc(count_word(str) + 1, sizeof(char *));
	i = 0;
	j = 0;
	while (i < ft_strlen_2table(str))
	{
		if (ft_strcmp(str[i], "<") == 0
			|| ft_strcmp(str[i], ">") == 0)
			break;
		str1[j] = ft_strdup(str[i]);
//		printf("ocho %s\n", str1[i]);
		i++;
		j++;
	}
	str1[j] = NULL;
	ft_print_split(str1);
	return (str1);
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
		ft_strcmp(s->cmds_tab[nbr->number - 1][i], ">") == 0 ||
		ft_strcmp(s->cmds_tab[nbr->number - 1][i], "<<") == 0)
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
