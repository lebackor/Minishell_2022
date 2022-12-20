#include "../include/minishell.h"

// int	is_expand(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		if (str[i] == '$')
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

// int	countword_quote(char const *str)
// {
// 	int	i;
// 	int	count;
// 	int	j;

// 	j = 0;
// 	count = 0;
// 	i = 0;
// 	while (str[i])
// 	{
// 		while (str[i])
// 		{
// 			if (str[i] == '|')
// 				break;
// 			i++;
// 		}
// 		printf("str[i] = %c\n", str[i]);
// 		if (str[i] && str[i] == '|')
// 		{
// 			j = 0;
// 			i++;
// 			printf("first\n");
// 			while (str[i] && str[i] == '|')
// 			{
// 				if (str[i] == 33 || (str[i] > 34 && str[i] < 127))
// 				{
// 					while (str[i] == '"')
// 						i++;
// 					j = 1;
// 				}
// 			}
// 		}
// 		i++;
// 		if (j == 0)
// 			count++;
// 	}
// 	return (count);
// }

// "ls" | "cat"

int	countword_quote(char const *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] && str[i] != '|')
	{
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		if (str[i] != '"' && str[i] != '\'')
		{
			while (str[i] && str[i] != '|')
				i++;
		}
		else if (str[i] == '"' || str[i] == '\'')
		{
			count++;
			while (str[i] && str[i] != '|')
				i++;
		}
		if (str[i] == '|')
			i++;
	}
	return (count);
}
