/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebackor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:44:24 by lebackor          #+#    #+#             */
/*   Updated: 2021/12/03 12:59:32 by lebackor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
char	*ft_strjoin(char const *s1, char const *s2)
{
	int		a;
	size_t	i;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	a = ft_strlen(s1);
	str = ft_calloc(a + ft_strlen(s2) + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		str[a] = s2[i];
		a++;
		i++;
	}
	return (str);
}*/
char	*ft_strjoin(char *s1, char *s2)
{
	int		a;
	size_t	i;
	char	*str;

	if (!s2)
		return (NULL);
	if (!s1)
		return (s2);
	i = -1;
	a = ft_strlen(s1);
	str = ft_calloc(a + ft_strlen(s2) + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	i = 0;
	while (s2[i])
	{
		str[a] = s2[i];
		a++;
		i++;
	}
	free(s1);
	return (str);
}
