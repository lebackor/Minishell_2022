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
	if (count % 2 == 1)
		return (printf("%s: Syntax Error, missing quotes\n", MINISH), 1);
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

void	free_double_tab(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
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
	printf("ici\n");
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

int	quote_or_not(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '"' || str[i] == '\'')
			return (1);
		i++;
	}
	return (0);
}

int	which_quote(char *str)
{
	int	i;
	int	double_quote;
	int	quote;

	i = 0;
	quote = 0;
	double_quote = 0;
	while (str[i])
	{
		if (str[i] == '"')
			double_quote = i;
		else if (str[i] == '\'')
			quote = i;
		if (quote < double_quote)
			return (1);
		else
			return (0);
		i++;
	}
	return (0);
}

void	removal(char *dest, char *src)
{
	int	i;
	int	j;
	int	quote;
	int	double_quote;

	quote = 0;
	double_quote = 0;
	j = 0;
	i = 0;
	printf("src = %s\n", src);
	while (src[i])
	{
		while (src[i] && double_quote == 1 && quote == 0)
		{
			dest[j++] = src[i++];
			if (src[i] == '"')
			{
				i++;
				double_quote--;
			}
		}
		while (src[i] && double_quote == 0 && quote == 1)
		{
			dest[j++] = src[i++];
			if (src[i] == '\'')
			{
				i++;
				quote--;
			}
		}
		if (src[i] == '"' && double_quote == 0)
		{
			i++;
			double_quote++;
		}
		else if (src[i] == '\'' && quote == 0)
		{
			i++;
			quote++;
		}
		while (src[i] && double_quote == 0 && quote == 0)
			dest[j++] = src[i++];
	}
	dest[j] = '\0';
	printf("dest = %s\n", dest);
	return ;
}

void	remove_quote(char ***str)
{
	int	i;
	int	y;

	i = 0;
	while (str[i])
	{
		y = 0;
		while (str[i][y])
		{
			if (quote_or_not(str[i][y]))
			{
				if (which_quote(str[i][y]))
					removal(str[i][y], str[i][y]);
				if (!(which_quote(str[i][y])))
					removal(str[i][y], str[i][y]);
			}
		y++;
		}
	i++;
	}
	return ;
}

char	***check_quotes(char *str, t_pipe *cmds_list)
{
	char	***cmds_args;

	(void)cmds_list;
	cmds_args = skip_isspace(str);
	printf("ici\n");
	remove_quote(cmds_args);
	return (cmds_args);
}

void	destroy_cmds_args(char ***cmd_args)
{
	int	i;
	int	y;

	i = 0;
	while (cmd_args[i])
	{
		y = 0;
		while (cmd_args[i][y])
		{
			free(cmd_args[i][y]);
			cmd_args[i][y] = NULL;
			y++;
		}
		free(cmd_args[i]);
		cmd_args[i] = NULL;
		i++;
	}
	free(cmd_args);
	cmd_args = NULL;
}

