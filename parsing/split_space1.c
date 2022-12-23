#include "../include/minishell.h"

#include "../include/minishell.h"

static	int	ischarset(char c, char charset)
{
	if (c == charset)
	{
		return (1);
	}
	return (0);
}

static	unsigned int	countword(char const *str, char charset)
{
	unsigned int	i;
	unsigned int	count;
	int				quote;
	int				sq;

	sq = 0;
	quote = 0;
	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '"' && quote != 1)
		{
			i++;
			quote++;
			count++;
		}
		while (quote == 1 && str[i])
		{
			if (str[i] == '"')
				quote--;
			i++;
		}
		if (str[i] == '\'' && quote != 1)
		{
			i++;
			sq++;
			count++;
		}
		while (sq == 1 && str[i])
		{
			if (str[i] == '\'')
				sq--;
			i++;
		}
		while (str[i] && ischarset(str[i], charset) && str[i] != '"')
			i++;
		if (str[i] && !ischarset(str[i], charset) && str[i] != '"' && quote != 1 && sq != 1)
			count++;
		while (str[i] && !ischarset(str[i], charset) && str[i] != '"' && quote != 1 && sq != 1)
			i++;
	}
	return (count);
}

static int	lenword(char const *str, char charset)
{
	unsigned int	i;
	unsigned int	count;
	int				quote;

	quote = 0;
	count = 0;
	i = 0;
	while (str[i] != '"' && ischarset(str[i], charset) && str[i])
		i++;
	while (str[i] && !ischarset(str[i], charset))
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

char	**ft_split_space(char const *s, char c)
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
		k = 0;
		result[x] = ft_calloc(lenword(&s[i], c) + 1, sizeof(char));
		if (!result[x])
			result = ft_free(result, x);
		while (ischarset(s[i], c) && s[i])
			i++;
		while (s[i] && !ischarset(s[i], c))
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
	result[x] = NULL;
	return (result);
}
