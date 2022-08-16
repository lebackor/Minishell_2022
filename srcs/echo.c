/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebackor <lebackor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 17:17:16 by lebackor          #+#    #+#             */
/*   Updated: 2022/08/16 17:17:17 by lebackor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_echo(t_data *s)
{
	while (s->rdline[s->i] != ' ' && s->rdline[s->i])
		s->i++;
	while (s->rdline[s->i] == ' ' && s->rdline[s->i])
		s->i++;
	if (s->rdline[s->i] == '-' && s->rdline[s->i])
	{
		if (s->rdline[s->i + 1] == 'n' && (s->rdline[s->i + 2] == ' '
				|| s->rdline[s->i + 2] == '\0'))
			ft_print_echo(s, 0);
		else
			ft_print_echo(s, 1);
		return (0);
	}
	ft_print_echo(s, 1);
	return (0);
}

int	ft_print_echo(t_data *s, int a)
{
	if (a == 0)
	{
		write(1, &s->rdline[s->i + 3], ft_strlen(&s->rdline[s->i + 3]));
	}
	if (a == 1)
	{
		if (ft_strlen(s->rdline) == 4)
			ft_printf("\n");
		else
			ft_printf("%s\n", &s->rdline[s->i]);
	}
	return (0);
}
