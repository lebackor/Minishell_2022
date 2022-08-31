/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_bultins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebackor <lebackor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 18:34:41 by lebackor          #+#    #+#             */
/*   Updated: 2022/08/30 18:11:05 by lebackor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_search_bultins(t_data *s, t_env *env)
{
	s->i = 0;
	while (s->rdline[s->i] == ' ')
		s->i++;
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
	if (s->rdline[s->i] == 'e' && s->rdline[s->i + 1] == 'c'
		&& s->rdline[s->i + 2] == 'h' && s->rdline[s->i + 3] == 'o')
	{
		return (0);
	}
	else
		return (1);
}

int	ft_search_env(t_data *s)
{
	if (s->rdline[s->i] == 'e'
		&& s->rdline[s->i + 1] == 'n' && s->rdline[s->i + 2] == 'v')
	{
		return (0);
	}
	else
		return (1);
}

int	ft_search_export(t_data *s)
{
	if (s->rdline[s->i] == 'e' && s->rdline[s->i + 1] == 'x'
		&& s->rdline[s->i + 2] == 'p' && s->rdline[s->i + 3] == 'o'
		&& s->rdline[s->i + 4] == 'r' && s->rdline[s->i + 5] == 't')
	{
		return (0);
	}
	else
		return (1);
}

int	ft_search_unset(t_data *s)
{
	if (s->rdline[s->i] && s->rdline[s->i] == 'u' && s->rdline[s->i + 1] == 'n'
		&& s->rdline[s->i + 2] == 's' && s->rdline[s->i + 3] == 'e'
		&& s->rdline[s->i + 4] == 't')
	{
		return (0);
	}
	else
		return (1);
}

int	ft_search_cd(t_data *s)
{
	if (s->rdline[s->i] == 'c' && s->rdline[s->i + 1] == 'd'
		&& s->rdline[s->i + 2] == ' ')
	{
		return (0);
	}
	else
		return (1);
}

int	ft_search_pwd(t_data *s)
{
	if (s->rdline[s->i] == 'p' && s->rdline[s->i + 1] == 'w'
		&& s->rdline[s->i + 2] == 'd')
	{
		return (0);
	}
	else
		return (1);
}

