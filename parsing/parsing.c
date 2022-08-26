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


// void	better_strcpy(char *dest, char *src)
// {
// 	int	i;
// 	int	j;
// 	int	quote;

// 	quote = 0;
// 	i = 0;
// 	j = 0;
// 	while (src[i])
// 	{
// 		if (src[i] != ' ' && quote == 0)
// 		{
// 			if (src[i] == '"')
// 				quote++;
// 			dest[j] = src[i];
// 			j++;
// 		}
// 		else if (src[i] && quote > 0)
// 		{
// 			while(src[i] && src[i] != '"')
// 			{
// 				dest[j] = src[i];
// 				i++;
// 				j++;
// 			}
// 			if (src[i] == '"')
// 			{
// 				quote--;
// 				dest[j] = src[i];
// 				j++;
// 			}
// 		}
// 		i++;
// 	}
// 	dest[j] = '\0';
// }

// void	put_space(char *dest, char *src)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	while (src[i])
// 	{
// 		while (src[i] != '-' || src[i] != '"')
// 		{
// 			dest[j] = src[i];
// 			j++;
// 			i++;
// 		}
// 		if (src[i] == '"' || src[i] == '-')
// 		{
// 			printf("ici\n");
// 			dest[j] = ' ';
// 			j++;
// 			break ;
// 		}
// 	}
// 	while (src[i])
// 	{
// 		dest[j] = src[i];
// 		j++;
// 		i++;
// 	}
// 	dest[j] = '\0';
// 	return ;
// }

char	**skip_isspace(char *str)
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
	args = malloc(sizeof(char **) * 3);
	while (tmp[i])
	{
		args[x] = ft_split_space(tmp[i], ' ');
		printf("tmp[%d] = %s\n", i, tmp[i]);
		i++;
		x++;
	}
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
	return (tmp);
}

// char	**skip_isspace(char *str)
// {
// 	char	**tmp;
// 	int		i;

// 	i = 0;
// 	tmp = ft_split(str,'|');
// 	i = 0;
// 	while (tmp[i])
// 	{
// 		printf("before tmp[%d] = %s\n", i, tmp[i]);
// 		better_strcpy(tmp[i], tmp[i]);
// 		printf("after tmp[%d] = %s\n", i, tmp[i]);
// 		printf("-------------------------------\n");
// 		// printf("before tmp[%d] = %s\n", i, tmp[i]);
// 		// put_space(tmp[i], tmp[i]);
// 		// printf("after tmp[%d] = %s\n", i, tmp[i]);
// 		i++;
// 	}
// 	return (tmp);
// }

char	**check_quotes(char *str, t_pipe *cmds_list)
{
	(void)cmds_list;
	skip_isspace(str);
	return (NULL);
}
