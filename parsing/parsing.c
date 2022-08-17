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

char *fakejoin(char **str)
{
	int		i;
	char	*tmp;
	int		len;
	int		k;
	int		j;

	i = 0;
	j = 0;
	len = 0;
	tmp = NULL;
	while (str[i])
	{
		len += ft_strlen(str[i]) + 1;
		i++;
	}
	tmp = malloc(sizeof(char) * (len - 1));
	i = 0;
	while (str[i])
	{
		k = 0;
		while (str[i][k])
		{
			tmp[j] = str[i][k];
			j++;
			k++;
		}
		if (j != len - 1)
			tmp[j] = ' ';
		j++;
		tmp[j] = '\0';
		i++;
	}
	return (tmp);
}

char	*skip_isspace(char *str)
{
	char	*ret;
	char	**tmp;
	int		i;

	ret = NULL;
	i = 0;
	tmp = ft_split(str, ' ');
	ret = fakejoin(tmp);
	return (ret);
}

int	get_words(char *str)
{
	int	i;
	int	countword;

	countword = 0;
	i = 0;
	while (str[i] != '|' && str[i])
	{
		if (str[i] == 127)
			i++;
		i++;
		countword++;
	}
	if (str[i] == '|')
		countword = countword - 2;
	return (countword);
}

void	update_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '|')
		{
			str[i] = 127;
			return ;
		}
		str[i] = 127;
		i++;
	}
}

char	**check_quotes(char *str, t_pipe *cmds_list)
{
	int		count;
	int		y;
	int		i;
	char	*test;
	int		x;

	i = 0;
	y = 0;
	count = check_pipe(str);
	test = skip_isspace(str);
	if (cmds_list->pipe[y])
	{
		free(cmds_list->pipe[y]);
		y++;
	}
	y = 0;
	cmds_list->pipe = malloc(sizeof(char *) * (count));
	while (y < count)
	{
		cmds_list->pipe[y] = malloc(sizeof(char) * (get_words(test) + 1));
		x = 0;
		while (test[i] && test[i] != '|')
		{
			if (test[i] != 127)
			{
				cmds_list->pipe[y][x] = test[i];
				x++;
			}
			i++;
		}
		cmds_list->pipe[y][x] = '\0';
		printf("----------> cmds_list = %sB\n", cmds_list->pipe[y]);
		update_str(test);
		y++;
	}
	return (cmds_list->pipe);
}













// 		x = 0;
// 		while (test[i])
// 		{
// 			if (test [i] == '|')
// 			{
// 				i++;
// 				break;
// 			}
// 			cmds_list->pipe[y][x] = test[i];
// 			i++;
// 			x++;
// 		}
// 		cmds_list->pipe[y][x] = '\0';
// 		printf("cmds_list =  %sB\n", cmds_list->pipe[y]);
// 		y++;
// 	}
// 	free(test);
// 	return (cmds_list->pipe);
// }

