/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebackor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 19:36:06 by lebackor          #+#    #+#             */
/*   Updated: 2021/12/06 19:38:17 by lebackor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*l;
	t_list	*tmp;

	if (!lst)
		return (NULL);
	l = ft_lstnew(f(lst->content));
	if (!l)
	{
		ft_lstclear(&lst, del);
		return (NULL);
	}
	lst = lst->next;
	while (lst)
	{
		tmp = ft_lstnew(f(lst->content));
		if (!tmp)
		{
			ft_lstclear(&l, del);
			ft_lstclear(&lst, del);
			return (NULL);
		}
		ft_lstadd_back(&l, tmp);
		lst = lst->next;
	}
	return (l);
}
