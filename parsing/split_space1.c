#include "../include/minishell.h"

static int	ischarset(char c, char charset)
{
	if (c == charset)
	{
		return (1);
	}
	return (0);
}

static unsigned int	countword(char const *str, char charset)
{
	unsigned int	i;
	unsigned int	count;
	char			*tmp;
	int				quote;

	tmp = (char *)str;
	count = 0;
	i = 0;
	quote = 0;
	while (str[i])
	{
		if (str[i] == '"' && quote == 0)
		{
			quote++;
			count++;
			while (str[i] != '"' && quote == 1)
				i++;
			if (str[i] == '"')
				quote--;
			i++;
		}
		while ((str[i] != '"' && ischarset(tmp[i], charset) && str[i]) || str[i] == ' ')
			i++;
		if (!ischarset(tmp[i], charset) && str[i] && str[i] != ' ')
		{
			i++;
			count++;
		}
		while ((str[i] != '"' && !ischarset(tmp[i],charset) && str[i]) || str[i] == ' ')
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
	while (str[i])
	{
		if (str[i] == '"' && quote == 0)
		{
			quote++;
			while (str[i] != '"')
			{
				count++;
				i++;
			}
			if (str[i] == '"')
			{
				quote--;
				count++;
				i++;
			}
		}
		while ((str[i] != '"' && ischarset(str[i], charset) && str[i]) || str[i] == ' ')
			i++;
		while (str[i] != '"' && !ischarset(str[i], charset) && str[i] && str[i] != ' ')
		{
			count++;
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
	i = 0;
	x = 0;
	printf("%d countword\n", countword(s, c));
	while (result && x < countword(s, c))
	{
		k = 0;
		result[x] = malloc(sizeof(char) * (lenword(&s[i], c) + 1));
		if (!result[x])
			result = ft_free(result, x);
		printf("lenword = %d\n", lenword(&s[i], c) +1);
		while ((quote == 0 && (ischarset(s[i], c) && s[i])) || s[i] == ' ')
			i++;
		while (!ischarset(s[i], c) && s[i] && s[i])
		{
			if (s[i] == '"')
				quote++;
			while (quote == 1 && s[i])
			{
				if (s[i] == '"')
					quote--;
				i++;
				result[x][k++] = s[i++];
			}
			while (quote == 0 && s[i])
			{
				if (s[i] != ' ')
					result[x][k++] = s[i];
				i++;
			}
		}
		result[x][k] = '\0';
		x++;
	}
	return (result);
}
