/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebackor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:17:59 by lebackor          #+#    #+#             */
/*   Updated: 2021/12/03 14:23:56 by lebackor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	get_pos(char const *s1, char const *set, int sign)
{
	int	i;

	if (sign == 1)
	{
		i = 0;
		while (is_set(s1[i], set))
			i++;
		return (i);
	}
	else
	{
		i = ft_strlen(s1);
		while (is_set(s1[i - 1], set))
			i--;
		return (i);
	}
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		k;
	int		cnt;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	j = 0;
	cnt = 0;
	i = get_pos(s1, set, 1);
	k = get_pos(s1, set, 0);
	while (i++ < k)
		cnt++;
	str = ft_calloc(cnt + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (is_set(s1[i], set))
		i++;
	while (i < k)
		str[j++] = s1[i++];
	return (str);
}
