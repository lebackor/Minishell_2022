/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebackor <lebackor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 17:25:35 by lebackor          #+#    #+#             */
/*   Updated: 2022/08/17 19:38:38 by lebackor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_export(t_data *s, t_env *envp)
{
	s->i = 0;
	if (!s->rdline[s->i])
		return (ft_printf("declare -x not coded yet\n"));
	while (s->rdline[s->i] && s->rdline[s->i] != ' ')
		s->i++;
	while (s->rdline[s->i] && s->rdline[s->i] == ' ')
		s->i++;
	while (s->rdline[s->i]
		&& ((s->rdline[s->i] >= 'a' && s->rdline[s->i] <= 'z')
			|| (s->rdline[s->i] >= 'A' && s->rdline[s->i] <= 'Z')
			|| (s->rdline[s->i] >= '0' && s->rdline[s->i] <= '9')))
		s->i++;
	if (s->rdline[s->i] && s->rdline[s->i] != '=')
		return (ft_printf("bash: export: `%c': not a valid identifier\n",
				s->rdline[s->i]));
	else
	{
		/*if (!((s->rdline[s->i + 1] >= 'a' && s->rdline[s->i + 1] <= 'z')
				|| (s->rdline[s->i + 1] >= 'A' && s->rdline[s->i + 1] <= 'Z')
				|| (s->rdline[s->i + 1] >= '0' && s->rdline[s->i + 1] <= '9')))*/
		if (s->rdline[s->i] && s->rdline[s->i + 1] == ' ')
			return (ft_printf("bash: export: `%c': not a valid identifier\n",
					s->rdline[s->i + 1]));
		return (ft_put_in_env(s, envp));
	}
	return (ft_printf("bash: export: `%c': not a valid identifier\n",
			s->rdline[s->i]));
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
			printf("Error, export\n");
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
		printf("Error, export\n");
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
	//	printf("%s\n", tmp->content);
		if (ft_strcmp(tmp->content, ft_split_env(s->words[s->i_split + 1], 0))
			== 0)
		{
		/* i_split fait gaffe aux futur add de env
		*/
			if (ft_strcmp(tmp->value, ft_split_env(s->words[s->i_split + 1], 1))
				!= 0)
			{
				printf("Meme variable paslamemevaleur\n");
				free(tmp->value);
				tmp->value = ft_strdup(ft_split_env(s->words[s->i_split + 1],
							1));
				return (1);
			}
			if (ft_strcmp(tmp->value, ft_split_env(s->words[s->i_split + 1], 1))
				== 0)
				return (1); //ecrire u msg deror ou de dire c la mm lesdeux
		}
		tmp = tmp->next;
	}
//	printf("%s %s\n", tmp->content, tmp->value);
	ft_addback_new_env(envp, ft_split_env(s->words[s->i_split + 1], 0),
		ft_split_env(s->words[s->i_split + 1], 1));
	return (0);
}
