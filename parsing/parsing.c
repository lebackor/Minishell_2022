#include "../include/minishell.h"

int	check_syntax2(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '|' && str[i + 1] == '|')
			return (printf("%s: Syntax Error, \"||\" found\n", MINISH), 1);
		if (str[i] == '&' && str[i + 1] == '&')
			return (printf("%s: Syntax Error, \"&&\" found\n", MINISH), 1);
		i++;
	}
	return (0);
}

int	check_syntax(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (check_syntax2(str))
		return (1);
	while (str[i])
	{
		if (str[i] == '\\')
			return (printf("%s: Syntax Error, '\\' found\n", MINISH), 1);
		else if (str[i] == ';')
			return (printf("%s: Syntax error near unexpected token `;'\n",
					MINISH), 1);
		else if (str[i] == '"')
			count++;
		i++;
	}
	// if (check_if_quotes('\'','"', str))
	// 	return (1);
	if (count % 2 == 1)
		return (printf("%s: Syntax Error, missing quotes\n", MINISH), 1);
	return (0);
}

char	***skip_isspace(char *str)
{
	char	**tmp;
	char	***args;
	int		i;
	int		j;
	int		x;

	i = 0;
	tmp = ft_split(str, '|');
	j = 0;
	x = 0;
	args = ft_calloc(check_pipe(str) + 1, sizeof(char **));
	if (!args)
		return (NULL);
	while (tmp[i])
	{
		args[x] = ft_split_space(tmp[i], ' ');
		i++;
		x++;
	}
	free_double_tab(tmp);
	args[x] = NULL;
	j = 0;
	x = 0;
	while (args[x])
	{
		j = 0;
		while (args[x][j])
		{
			printf("args[%d] = %s\n", x, args[x][j]);
			j++;
		}
		x++;
	}
	return (args);
}
