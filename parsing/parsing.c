#include "../include/minishell.h"

int	check_syntax(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '\\')
			return (printf("Syntax Error, '\\' found\n"), 1);
		if (str[i] == ';')
			return (printf("syntax error near unexpected token `;'\n"), 1);
		if (str[i] == '"')
			count++;
		i++;
	}
	if (count % 2 == 1)
		return (printf("syntax Error, missing quotes\n"), 1);
	return (0);
}

int	check_pipe(char *str)
{
	int	i;
	int	count;

	count = 1;
	i = 0;
	while (str[i])
	{
		if (str[i] == '|')
			count++;
		i++;
	}
	return (count);
}

void	isspace(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			i++;

	}
}



char	**check_quotes(char *str, t_pipe *cmds_list)
{
	int	count;
	int	y;
	int	i;

	i = 0;
	y = 0;
	count = check_pipe(str);
	// printf("count = %d\n", count);
	cmds_list->pipe[y] = malloc(sizeof(char *) * (count + 1));
	return (cmds_list->pipe);
}
