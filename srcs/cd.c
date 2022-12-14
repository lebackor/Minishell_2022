/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebackor <lebackor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:44:44 by lebackor          #+#    #+#             */
/*   Updated: 2022/11/29 17:21:32 by lebackor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_cd(t_env *env, t_data *s, t_number *nbr)
{
	(void) env;
	if (chdir(s->cmds_tab[nbr->number - 1][1]) == -1)
	{
		printf("Error, not found directory\n");
	}
	else
	{
		edit_pwd_env(s, env);
		printf("Entered\n");
	}
	return (0);
}
