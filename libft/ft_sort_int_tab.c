/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebackor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 19:56:37 by lebackor          #+#    #+#             */
/*   Updated: 2022/03/07 17:50:52 by lebackor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	*ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	swp;

	i = 0;
	j = size - 1;
	swp = 1;
	while (j > 0)
	{
		if (tab[i] > tab[j])
		{
			swp = tab[i];
			tab[i] = tab[j];
			tab[j] = swp;
			i++;
		}	
		else
			i++;
		if (i == j)
		{
			i = 0;
			j--;
		}
	}
	return (tab);
}
