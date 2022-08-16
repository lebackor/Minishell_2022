/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebackor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 11:53:39 by lebackor          #+#    #+#             */
/*   Updated: 2021/12/03 12:47:56 by lebackor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char	*s_1;
	unsigned const char	*s_2;
	size_t				i;

	s_1 = (unsigned const char *)s1;
	s_2 = (unsigned const char *)s2;
	i = 0;
	if (s_1 == NULL && s_2 == NULL)
		return (0);
	while (i < n)
	{
		if (s_1[i] != s_2[i])
			return (s_1[i] - s_2[i]);
		i++;
	}
	if (i >= n)
		return (0);
	else
		return (s_1[i] - s_2[i]);
}
