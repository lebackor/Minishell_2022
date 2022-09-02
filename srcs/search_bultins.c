/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_bultins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebackor <lebackor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 18:34:41 by lebackor          #+#    #+#             */
/*   Updated: 2022/09/02 18:00:24 by lebackor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_search_bultins(t_data *s, t_env *env)
{
	if (ft_search_echo(s) == 0)
		return (ft_echo(s));
	if (ft_search_env(s) == 0)
		return (ft_env(env, s));
	if (ft_search_export(s) == 0)
		return (ft_export(s, env));
	if (ft_search_unset(s) == 0)
		return (ft_unset(s, env));
	if (ft_search_cd(s) == 0)
		return (ft_cd(env, s));
	if (ft_search_pwd(s) == 0)
		return (ft_pwd());
	return (1);
}

int	ft_search_echo(t_data *s)
{
	if (ft_strlen_3table(s->cmds_tab) == 1)
	{
		if (ft_strcmp(s->cmds_tab[s->i_split][s->i_split], "echo") == 0)
		{
			return (0);
		}
		else
			return (1);
	}
	else if (ft_strlen_3table(s->cmds_tab) > 1)
	{
		printf("Wait pipex\n");
		return (1);
	}
	else
		return (1);
}

int	ft_search_env(t_data *s)
{
	if (ft_strlen_3table(s->cmds_tab) == 1)
	{
		if (ft_strcmp(s->cmds_tab[s->i_split][s->i_split], "env") == 0)
		{
			return (0);
		}
		else
			return (1);
	}
	else if (ft_strlen_3table(s->cmds_tab)> 1)
	{
		printf("Wait pipex\n");
		return (1);
	}
	else
		return (1);
}

int	ft_search_export(t_data *s)
{
	if (ft_strlen_3table(s->cmds_tab) == 1)
	{
		if (ft_strcmp(s->cmds_tab[s->i_split][s->i_split], "export") == 0)
		{
			return (0);
		}
		else
			return (1);
	}
	else if (ft_strlen_3table(s->cmds_tab) > 1)
	{
		printf("Wait pipex\n");
		return (1);
	}
	else
		return (1);
}

int	ft_search_unset(t_data *s)
{
	if (ft_strlen_3table(s->cmds_tab) == 1)
	{
		if (ft_strcmp(s->cmds_tab[s->i_split][s->i_split], "unset") == 0)
		{
			return (0);
		}
		else
			return (1);
	}
	else if (ft_strlen_3table(s->cmds_tab) > 1)
	{
		printf("Wait pipex\n");
		return (1);
	}
	else
		return (1);
}

int	ft_search_cd(t_data *s)
{
	if (ft_strlen_3table(s->cmds_tab) == 1)
	{
		if (ft_strcmp(s->cmds_tab[s->i_split][s->i_split], "cd") == 0)
		{
			return (0);
		}
		else
			return (1);
	}
	else if (ft_strlen_3table(s->cmds_tab) > 1)
	{
		printf("Wait pipex\n");
		return (1);
	}
	else
		return (1);
}

int	ft_search_pwd(t_data *s)
{
	if (ft_strlen_3table(s->cmds_tab) == 1)
	{
		if (ft_strcmp(s->cmds_tab[s->i_split][s->i_split], "pwd") == 0)
		{
			return (0);
		}
		else
			return (1);
	}
	else if (ft_strlen_3table(s->cmds_tab) > 1)
	{
		printf("Wait pipex\n");
		return (1);
	}
	else
		return (1);
}

