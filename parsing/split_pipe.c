#include "../include/minishell.h"

static	int	ischarset(char const *c, char *charset, int i)
{
	if (ft_strncmp(c, charset, 3, i) == 0)
		return (1);
	return (0);
}

static	unsigned int	countword(char const *str, char *charset)
{
	unsigned int	i;
	unsigned int	count;
	int				quote;

	quote = 0;
	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '"')
		{
			quote++;
			i++;
		}
		while (quote == 1 && str[i])
		{
			if (str[i] == '"')
				quote--;
			i++;
		}
		while (str[i] && ischarset(str, charset, i) && str[i] != '"')
			i = i + 3;
		if (str[i] && !ischarset(str, charset, i) && str[i] != '"')
			count++;
		while (str[i] && !ischarset(str, charset, i) && str[i] != '"')
			i++;
	}
	printf("before count = %d\n", count);
	count = countword_quote(str) + count;
	printf("count + count = %d\n", count);
	return (count);
}

// static	unsigned int	countword2(char const *str, char *charset)
// {
// 	unsigned int	i;
// 	unsigned int	count;
// 	int				quote;

// 	quote = 0;
// 	count = 0;
// 	i = 0;
// 	while (str[i])
// 	{
// 		if (str[i] == '\'')
// 		{
// 			quote++;
// 			i++;
// 		}
// 		while (quote == 1 && str[i])
// 		{
// 			if (str[i] == '\'')
// 				quote--;
// 			i++;
// 		}
// 		while (str[i] && ischarset(str, charset, i) && str[i] != '\'')
// 			i = i + 3;
// 		if (str[i] && !ischarset(str, charset, i) && str[i] != '\'')
// 			count++;
// 		while (str[i] && !ischarset(str, charset, i) && str[i] != '\'')
// 			i++;
// 	}
// 	printf("before count = %d\n", count);
// 	count = countword_quote(str) + count;
// 	printf("count + count = %d\n", count);
// 	return (count);
// }

static int	lenword(char const *str, char *charset)
{
	unsigned int	i;
	unsigned int	count;
	int				quote;

	quote = 0;
	count = 0;
	i = 0;
	while (str[i] != '"' && ischarset(str, charset, i) && str[i])
		i++;
	while (str[i] && !ischarset(str, charset, i))
	{
		if (str[i] == '"')
			quote++;
		count++;
		i++;
		while (quote == 1 && str[i])
		{
			count++;
			if (str[i] == '"')
				quote--;
			i++;
		}
	}
	return (count);
}

// static int	lenword2(char const *str, char *charset)
// {
// 	unsigned int	i;
// 	unsigned int	count;
// 	int				quote;

// 	quote = 0;
// 	count = 0;
// 	i = 0;
// 	while (str[i] != '\'' && ischarset(str, charset, i) && str[i])
// 		i++;
// 	while (str[i] && !ischarset(str, charset, i))
// 	{
// 		if (str[i] == '\'')
// 			quote++;
// 		count++;
// 		i++;
// 		while (quote == 1 && str[i])
// 		{
// 			count++;
// 			if (str[i] == '\'')
// 				quote--;
// 			i++;
// 		}
// 	}
// 	return (count);
// }


static char	**ft_free(char **str, int i)
{
	while (str[i] != 0)
	{
		free (str[i]);
		i--;
	}
	free(str);
	return (NULL);
}

char	**ft_split_pipe(char const *s, char *c)
{
	unsigned int	i;
	unsigned int	k;
	unsigned int	x;
	char			**result;
	int				quote;

	quote = 0;
	if (!s)
		return (NULL);
	result = ft_calloc(countword(s, c) + 1, sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	x = 0;
	while (result && x < countword(s, c))
	{
		while (ischarset(s, c, i) == 1)
			i = i + 3;
		k = 0;
		result[x] = ft_calloc(lenword(&s[i], c) + 1, sizeof(char));
		if (!result[x])
			result = ft_free(result, x);
		while (s[i] && !ischarset(s, c, i))
		{
			if (s[i] == '"')
			{
				quote++;
				while (quote == 1 && s[i])
				{
					result[x][k++] = s[i++];
					if (s[i] == '"')
						quote--;
				}
			}
			result[x][k++] = s[i++];
		}
		result[x][k] = '\0';
		x++;
	}
	return (result);
}

