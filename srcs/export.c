/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebackor <lebackor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 17:25:35 by lebackor          #+#    #+#             */
/*   Updated: 2022/11/29 18:34:57 by lebackor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_export(t_data *s, t_env *envp, t_number *nbr)
{
	char	**export;

	(void) envp;
	export = ft_split(s->cmds_tab[nbr->number - 1][0], '=');
	ft_print_split(export);
	if (!s->cmds_tab[nbr->number - 1][0])
	{
		ft_declare(envp);
		return (0);
	}
	else
		return (ft_put_in_env(s, envp, nbr));
	return (ft_printf("bash: export: `%c': not a valid identifier\n",
			s->rdline[s->i]));
}

char	search_export_equal_not(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (i == 0 && str[i] == '=')
			return (str[i]);
		if (str[i] && str[i] == '=')
			count++;
		i++;
	}
	if (count == 0)
		return (str[i]);
	else
		return ('\0');
}

char	*ft_split_env(char *str, int count)
{
	char	*env;
	int		i;
	int		j;

	i = 0;
	j = 0;
	env = malloc(sizeof(str) * (ft_strlen(str) + 1));
	if (count == 0)
	{
		while (str[i] && str[i] != '=')
		{
			env[i] = str[i];
			i++;
		}
		env[i] = '\0';
		return (env);
	}
	else if (count == 1)
	{
		while (str[i] && str[i] != '=')
			i++;
		if (str[i] != '=')
		{
			printf("Error, export 1\n");
			return (NULL);
		}
		while (str[++i])
		{
			env[j] = str[i];
			j++;
		}
		env[j] = '\0';
		return (env);
	}
	else
	{
		printf("Error, export 2\n");
		return (NULL);
	}
}

int	ft_put_in_env(t_data *s, t_env *envp, t_number *nbr)
{
	int		i;
	t_env	*tmp;

	i = 1;
	while (s->cmds_tab[nbr->number - 1][i])
	{
		tmp = envp;
		while (tmp != NULL)
		{
			if (ft_strcmp(tmp->content, ft_split_env(s->cmds_tab[nbr->number - 1]
						[i], 0)) == 0)
			{
				if (ft_strcmp(tmp->value, ft_split_env(s->cmds_tab[nbr->number - 1]
							[i], 1))
					!= 0)
				{
					free(tmp->value);
					if (ft_split_env(s->cmds_tab[nbr->number - 1][i], 1) != NULL)
						tmp->value = ft_strdup(ft_split_env(s->cmds_tab[nbr->number - 1][i], 1));
				//	return (0);
				}
				// else if (ft_strcmp(tmp->value, ft_split_env(s->cmds_tab[nbr->number - 1]
				// 			[i], 1))
				// 	== 0)
				// 	break; //ecrire u msg deror ou de dire c la mm lesdeux
			}
			tmp = tmp->next;
		}
		ft_addback_new_env(envp, ft_split_env(s->cmds_tab[nbr->number - 1]
			[i], 0), ft_split_env(s->cmds_tab[nbr->number - 1]
			[i], 1));
		i++;
	}
	return (0);
}
