/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebackor <lebackor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 20:51:31 by lebackor          #+#    #+#             */
/*   Updated: 2022/12/23 15:22:06 by lebackor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(const char *s1, const char *s2, int n, int i)
{
	int	j;

	j = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[j] && s1[i] == s2[j] && j < (n - 1))
	{
		j++;
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[j]);
}
