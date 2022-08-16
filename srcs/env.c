#include "../include/minishell.h"

t_env *put_env(t_env *env, char **envp, t_data *s)
{
	int		i;
	(void)	s;

	i = 0;
	while (envp[i])
	{
		ft_addback(&env);
		i++;
	}
	ft_put_first_env(env, envp);
	ft_put_second_env(env, envp);
	return (env);
}

void    ft_put_second_env(t_env *env, char **envp)
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

	tmp = envp;
	while (tmp->next != NULL)
	{
		printf("%s", tmp->content);
		printf("=");
		printf("%s\n", tmp->value);
		tmp = tmp->next;
	}
	if (tmp->content)
	{
		printf("%s", tmp->content);
		printf("=");
		printf("%s\n", tmp->value);
	}
	looking_for_path(envp, s);
	return (1);
}
