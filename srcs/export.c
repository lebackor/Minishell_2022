/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebackor <lebackor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 17:25:35 by lebackor          #+#    #+#             */
/*   Updated: 2022/08/31 17:16:19 by lebackor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_export(t_data *s, t_env *envp)
{
	char **export;
	(void) envp;
	export = ft_split(s->cmds_tab[s->i_split][s->i_split], '=');
	ft_print_split(export);
	if (!s->cmds_tab[s->i_split][s->i_split + 1])
		return (ft_printf("declare -x not coded yet\n"));
	if (s->cmds_tab[s->i_split][s->i_split + 1] && search_export_equal_not(s->cmds_tab[s->i_split][s->i_split + 1]) != NULL)
		return (ft_printf("bash: export: `%c': not a valid identifier\n",
				search_export_equal_not(s->cmds_tab[s->i_split][s->i_split + 1]));
	else
	{
		if (s->rdline[s->i] && s->rdline[s->i + 1] == ' ')
			return (ft_printf("bash: export: `%c': not a valid identifier\n",
					s->rdline[s->i + 1]));
		return (ft_put_in_env(s, envp));
	}
	return (ft_printf("bash: export: `%c': not a valid identifier\n",
			s->rdline[s->i]));
}

char search_export_equal_not(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (i = 0 && str[i] == '=')
			return (str[i]);
		if (str[i] && str[i] '=')
			count++;
		i++;
	}
	if (count == 0)
		return (str[i]);
	else
		return (NULL);
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

int	ft_put_in_env(t_data *s, t_env *envp)
{
	int		i;
	t_env	*tmp;

	i = 0;
	tmp = envp;
	s->i_split = 0;
	while (s->rdline[i] != ' ')
		i++;
	while (s->rdline[i] == ' ')
		i++;
	while (tmp != NULL)
	{
		if (ft_strcmp(tmp->content, ft_split_env(s->words[s->i_split + 1], 0))
			== 0)
		{
		/* i_split fait gaffe aux futur add de env
		*/
			if (ft_strcmp(tmp->value, ft_split_env(s->words[s->i_split + 1], 1))
				!= 0)
			{
				free(tmp->value);
				tmp->value = ft_strdup(ft_split_env(s->words[s->i_split + 1],
							1));
				return (0);
			}
			if (ft_strcmp(tmp->value, ft_split_env(s->words[s->i_split + 1], 1))
				== 0)
				return (0); //ecrire u msg deror ou de dire c la mm lesdeux
		}
		tmp = tmp->next;
	}
	ft_addback_new_env(envp, ft_split_env(s->words[s->i_split + 1], 0),
		ft_split_env(s->words[s->i_split + 1], 1));
	return (0);
}
