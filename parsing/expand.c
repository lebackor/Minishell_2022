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
	t_env	*tmp2;

	tmp2 = env;
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



	while (tmp2)
	{
		if (ft_strcmp(tmp2->content, tmp) == 0)
			return (printf("value = %s\n", tmp2->value), tmp2->value);
		// printf("%s=%s\n", tmp2->content, tmp2->value);
		tmp2 = tmp2->next;
		if (!tmp2)
			return (NULL);
	}
	return ("\n");
}

// char	*find_expand(char *str)
// {
// 	char	*tmp;
// 	int		i;
// 	int		j;

// 	tmp = NULL;
// 	i = 0;
// 	printf("%s\n", str);
// 	while (str[i] != '$')
// 		i++;
// 	if (str[i] == '$')
// 		i++;
// 	j = i;
// 	while (str[j] && str[j] != ' ' && str[j] != '"' && str[j] != '\'')
// 		j++;
// 	tmp = ft_calloc(j + 1, sizeof(char));
// 	if (!tmp)
// 		return (NULL);
// 	j = 0;
// 	while (str[i] && str[i] != ' ' && str[i] != '"' && str[i] != '\'')
// 		tmp[j++] = str[i++];
// 	tmp[j] = '\0';
// 	return (tmp);
// }

// char	*changing_str(char *str, t_env *env)
// {
// 	t_env	*tmp2;
// 	char	*tmp;

// 	tmp = find_expand(str);
// 	tmp2 = env;
// 	while (tmp2)
// 	{
// 		if (ft_strcmp(tmp2->content, tmp) == 0)
// 			return (printf("value = %s\n", tmp2->value), tmp2->value);
// 		tmp2 = tmp2->next;
// 		if (!tmp2)
// 			return ("\0");
// 	}
// 	return ("\0");
// }

void	*time_to_expand(char **str, t_env *env)
{
	int		x;
	int		j;
	char	*tmp;

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
