/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebackor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:00:53 by lebackor          #+#    #+#             */
/*   Updated: 2021/12/03 13:30:10 by lebackor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_fill_tab(int i, long long nb, int sign)
{
	char	*str;

	str = ft_calloc(i + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (--i >= sign)
	{
		str[i] = nb % 10 + 48;
		nb /= 10;
	}
	if (sign == 1)
		str[0] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	int			i;
	long long	nb;
	char		*str;
	int			sign;

	i = -1;
	sign = 0;
	nb = (long long) n;
	if (nb < 0)
	{
		sign++;
		i++;
		nb = -nb;
	}
	while (n)
	{
		n = n / 10;
		i++;
	}
	if (nb == 0)
		i = 0;
	str = ft_fill_tab(i + 1, nb, sign);
	return (str);
}
