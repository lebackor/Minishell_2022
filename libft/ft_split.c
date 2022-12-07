/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebackor <lebackor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 21:11:42 by lebackor          #+#    #+#             */
/*   Updated: 2022/11/22 16:40:44 by lebackor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	char			*strs;

	strs = (char *)str;
	count = 0;
	i = 0;
	while (str[i])
	{
		while (ischarset(strs[i], charset) && str[i])
			i++;
		if (!ischarset(strs[i], charset) && str[i])
			count++;
		while (!ischarset(strs[i], charset) && str[i])
			i++;
	}
	return (count);
}

static int	lenword(char const *str, char charset)
{
	unsigned int	i;
	unsigned int	count;

	count = 0;
	i = 0;
	while (ischarset(str[i], charset) && str[i])
		i++;
	while (!ischarset(str[i], charset) && str[i])
	{
		count++;
		i++;
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

char	**ft_split(char const *s, char c)
{
	unsigned int	i;
	unsigned int	k;
	unsigned int	x;
	char			**result;

	if (!s)
		return (NULL);
	result = ft_calloc(countword(s, c) + 1, sizeof(char *));
	i = 0;
	x = 0;
	while (result && x < countword(s, c))
	{
		k = 0;
		result[x] = malloc(sizeof(char) * (lenword(&s[i], c) + 1));
		if (!result[x])
			result = ft_free(result, x);
		while (ischarset(s[i], c) && s[i])
			i++;
		while (!ischarset(s[i], c) && s[i])
			result[x][k++] = s[i++];
		result[x][k] = '\0';
		x++;
	}
	return (result);
}
