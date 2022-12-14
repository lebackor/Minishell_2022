/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebackor <lebackor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:26:51 by lebackor          #+#    #+#             */
/*   Updated: 2022/11/22 14:44:30 by lebackor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*parsing(t_datapipe *p)
{
	char	*str;

	p->i = 0;
	while (p->i < 62)
	{
		p->k = 0;
		p->j = 0;
		str = malloc(sizeof(char) * ft_strlen(p->env[p->i]) + 1);
		if (!str)
			ft_exit_fail(p);
		while (p->env[p->i][p->j])
		{
			str[p->k] = p->env[p->i][p->j];
			p->k++;
			p->j++;
		}
		str[p->k] = '\0';
		if (str[0] == 'P' && str[1] == 'A' && str[2] == 'T')
			break ;
		free(str);
		str = NULL;
		p->i++;
	}
	return (str);
}

char	*parse_split(t_datapipe *p, t_nb *nb)
{
	char	*str;
	int		i;

	i = 0;
	p->j = 1;
	str = parsing(p);
	while (str[i] != '/' && str[i])
		i++;
	p->paths = ft_split(&str[i], ':');
	if (str)
		free(str);
	if (p->ac > 5)
	{
		p->avsplit = ft_split(p->av[nb->number + 1], ' ');
	}
	else
		p->avsplit = ft_split(p->av[2], ' ');
	p->cmdargs = parsep1(p);
	if (p->cmdargs != NULL)
		return (p->cmdargs);
	ft_free_table(p->avsplit);
	p->avsplit = NULL;
	return (NULL);
}

char	*parse_child(t_datapipe *p)
{
	char	*str;
	int		i;

	i = 0;
	p->j = 1;
	str = parsing(p);
	while (str[i] != '/')
		i++;
	p->pathschild = ft_split(&str[i], ':');
	if (str)
		free(str);
	p->avsplitchild = ft_split(p->av[3], ' ');
	p->cmdargschild = parsep2(p);
	if (p->cmdargschild != NULL)
		return (p->cmdargschild);
	ft_free_table(p->avsplitchild);
	p->avsplitchild = NULL;
	return (NULL);
}

char	*parsep1(t_datapipe *p)
{
	char	*raciste;
	int		i;

	i = -1;
	while (p->paths[++i] && p->j != 0)
	{
		raciste = ft_strjoin(p->paths[i], "/");
		p->cmdargs = ft_strjoin(raciste, p->avsplit[0]);
		free(raciste);
		p->j = access(p->cmdargs, X_OK);
		if (p->j == 0)
			return (p->cmdargs);
		free(p->cmdargs);
		p->cmdargs = NULL;
	}
	return (NULL);
}

char	*parsep2(t_datapipe *p)
{
	char	*raciste;
	int		i;

	i = -1;
	while (p->pathschild[++i] && p->j != 0)
	{
		raciste = ft_strjoin(p->pathschild[i], "/");
		p->cmdargschild = ft_strjoin(raciste, p->avsplitchild[0]);
		free(raciste);
		p->j = access(p->cmdargschild, X_OK);
		if (p->j == 0)
			return (p->cmdargschild);
		free(p->cmdargschild);
		p->cmdargschild = NULL;
	}
	return (NULL);
}
