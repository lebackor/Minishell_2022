/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebackor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 21:24:01 by lebackor          #+#    #+#             */
/*   Updated: 2021/12/03 14:24:27 by lebackor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen((char *)s);
	while (i > 0)
	{
		if (s[i] == (unsigned char) c)
			return ((char *) &s[i]);
		i--;
	}
	if (s[i] == (unsigned char) c)
		return ((char *) &s[i]);
	return (NULL);
}
