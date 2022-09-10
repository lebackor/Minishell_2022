/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebackor <lebackor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:44:44 by lebackor          #+#    #+#             */
/*   Updated: 2022/09/10 15:29:32 by lebackor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_cd(t_env *env, t_data *s)
{
	(void) env;
	if (chdir(s->cmds_tab[s->i_split][s->i_split + 1]) == -1)
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
