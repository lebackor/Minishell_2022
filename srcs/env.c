/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebackor <lebackor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 17:17:20 by lebackor          #+#    #+#             */
/*   Updated: 2022/08/24 17:16:28 by lebackor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_env	*put_env(t_env *env, char **envp, t_data *s)
{
	int		i;

	(void) s;
	i = 0;
	while (envp[i])
	{
		ft_addback(&env, NULL, NULL);
		i++;
	}
	ft_put_first_env(env, envp);
	ft_put_second_env(env, envp);
	return (env);
}

void	ft_put_second_env(t_env *env, char **envp)
{
	int		i;
	int		j;
	int		k;
	char	*str;
	t_env	*tmp;

	i = 0;
	tmp = env;
	while (envp[i])
	{
		j = 0;
		k = 0;
		str = malloc(sizeof(char *) * (ft_strlen(envp[i] + 1)));
		while (envp[i][j] && envp[i][j] != '=')
			j++;
		j++;
		while (envp[i][j])
		{
			str[k] = envp[i][j];
			j++;
			k++;
		}
		str[k] = '\0';
		tmp->value = ft_strdup(str);
		tmp = tmp->next;
		free(str);
		str = NULL;
		i++;
	}
}

void	ft_put_first_env(t_env *env, char **envp)
{
	int		i;
	int		j;
	char	*str;
	t_env	*tmp;

	i = 0;
	tmp = env;
	while (envp[i])
	{
		j = 0;
		str = malloc(sizeof(char *) * (ft_strlen(envp[i]) + 1));
		while (envp[i][j])
		{
			if (envp[i][j] == '=')
				break ;
			str[j] = envp[i][j];
			j++;
		}
		str[j] = '\0';
		tmp->content = ft_strdup(str);
		tmp = tmp->next;
		free(str);
		str = NULL;
		i++;
	}
}

int	ft_env(t_env *envp, t_data *s)
{
	t_env	*tmp;
	(void )s;
	tmp = envp;
	while (tmp != NULL)
	{
		printf("%s", tmp->content);
		printf("=");
		printf("%s\n", tmp->value);
		tmp = tmp->next;
	}
	return (0);
}
