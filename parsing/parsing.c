#include "../include/minishell.h"

//check "" | ""
//check remove SPACE PIPE SPACE ET PAS QUE PIPE
// MA FONCTION COUNTWORD A MODIFIER , j'ai +1
// characters in quote a modifier
int	check_syntax(char *str)
{
	if (pipe_syntax(str) == 1)
		return (printf("%s: syntax error near unexpected token `|'\n",
				CALLER), 1);
	if (check_first_quote(str, 39, '"') % 2 == 1
		|| check_first_quote(str, '"', 39) % 2 == 1)
		return (printf("%s: Syntax Error, missing quotes\n", CALLER), 1);
	if (characters_in_quote(str, '&'))
		return (printf("%s: Syntax Error, \"&\" found\n", CALLER), 1);
	if (characters_in_quote(str, '\\'))
		return (printf("%s: Syntax Error, \"\\\" found\n", CALLER), 1);
	if (characters_in_quote(str, ';'))
		return (printf("%s: Syntax Error, \";\" found\n", CALLER), 1);
	return (0);
}

char	***skip_isspace(char *str)
{
	char	**tmp;
	char	***args;
	int		i;
	int		j;
	int		x;

	// tmp = ft_split(str, '|');
	tmp = ft_split_pipe(str, " | ");
	i = 0;
	while (tmp[i])
	{
		printf("%s\n", tmp[i]);
		i++;
	}
	x = 0;
	args = ft_calloc(check_pipe(str) + 1, sizeof(char **));
	if (!args)
		return (NULL);
	i = 0;
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
	printf("---------------- RESULT ---------------\n\n");
	return (args);
}

int	characters_in_quote(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		else if (str[i] == '"')
		{
			i++;
			while (str[i] != '"' && str[i])
				i++;
		}
		if (str[i + 1])
			i++;
		else
			return (0);
	}
	return (0);
}
