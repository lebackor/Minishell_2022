/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebackor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 19:19:28 by lebackor          #+#    #+#             */
/*   Updated: 2021/12/06 19:22:07 by lebackor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*l;

	if (!new)
		return ;
	l = *alst;
	if (!*alst)
		(*alst) = new;
	else
	{
		while (l->next)
			l = l->next;
		l->next = new;
	}
}
