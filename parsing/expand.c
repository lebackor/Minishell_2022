#include "../include/minishell.h"

int	is_expand(char **cmds_list)
{
	int	x;
	int	j;

	j = 0;
	x = 0;
	while (cmds_list[j])
	{
		x = 0;
		while (cmds_list[j][x])
		{
			if (cmds_list[j][x] == '$')
				return (1);
			x++;
		}
		j++;
	}
	return (0);
}


char	*changing_str(char *str, t_env *env)
{
	char	*tmp = NULL;
	int		i;
	int		j;

	i = 0;
	printf("%s\n", str);
	while (str[i] != '$')
		i++;
	if (str[i] == '$')
		i++;
	j = i;
	while (str[j] && str[j] != ' ' && str[j] != '"' && str[j] != '\'')
		j++;
	tmp = ft_calloc(j + 1, sizeof(char));
	if (!tmp)
		return (NULL);
	j = 0;
	while (str[i] && str[i] != ' ' && str[i] != '"' && str[i] != '\'')
		tmp[j++] = str[i++];
	tmp[j] = '\0';
	printf("tmp = %s\n", tmp);
	printf("-------------------------------------------\n");
	while (env)
	{
		if (ft_strcmp(env->content, tmp) == 0)
			return (printf("value = %s\n", env->value), env->value);
		env = env->next;
		if (!env)
			return (NULL);
	}
	return ("\n");
}

void	*time_to_expand(char **str, t_env *env)
{
	int	x;
	int	j;
	char *tmp;

	x = 0;
	j = 0;
	while (str[j])
	{
		x = 0;
		while (str[j][x])
		{
			if (str[j][x] == '$')
			{
				tmp = changing_str(str[j], env);
				str[j] = ft_strdup(tmp);
				break ;
			}
			x++;
		}
		j++;
	}
	free(tmp);
	return (NULL);
}

void	expand_fct(char ***cmd_list, t_env *env)
{
	int	j;

	j = 0;
	while (cmd_list[j])
	{
		if (is_expand(cmd_list[j]))
			time_to_expand(cmd_list[j], env);
		j++;
	}
}
