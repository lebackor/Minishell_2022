/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebackor <lebackor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 18:58:58 by lebackor          #+#    #+#             */
/*   Updated: 2022/08/30 19:44:19 by lebackor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
/*
	dup2(p.f1, STDIN_FILENO);
	dup2(p.end[1], STDOUT_FILENO);

	dup2(p.end[0], STDIN_FILENO);
	dup2(p.f2, STDOUT_FILENO);
*/

int	ft_redir_input(t_data *s)
{
	int fd;

	if (ft_strcmp('<', s->words[0]))
	{
		fd = open(s->word[s->i_split + 1], O_RDONLY); //
		

	}

}

int ft_redir_first_arg(t_data *s)
{

}
