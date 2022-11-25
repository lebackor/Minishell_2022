/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchan <vchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:12:26 by vchan             #+#    #+#             */
/*   Updated: 2022/11/25 11:29:27 by vchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	free_double_tab(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	destroy_cmds_args(char ***cmd_args)
{
	int	i;
	int	y;

	i = 0;
	while (cmd_args[i])
	{
		y = 0;
		while (cmd_args[i][y])
		{
			free(cmd_args[i][y]);
			cmd_args[i][y] = NULL;
			y++;
		}
		free(cmd_args[i]);
		cmd_args[i] = NULL;
		i++;
	}
	free(cmd_args);
	cmd_args = NULL;
}
