/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchan <vchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:11:50 by vchan             #+#    #+#             */
/*   Updated: 2022/11/30 15:58:40 by vchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// Si valeur de retour = 1, il y a 0 pipe, mais une commande.
// Si la valeur de retour est 2, il y a 1 pipe, donc deux commandes.
int	check_pipe(char *str)
{
	int	i;
	int	count;

	count = 1;
	i = 0;
	while (str[i])
	{
		while ((str[i] != '\'' && str[i] != '"') && str[i])
		{
			if (str[i] == '|')
				count++;
			i++;
		}
		if (str[i] == '\'')
		{
			i++;
			while (str[i] != '\'' && str[i])
				i++;
			if (str[i] == '\'')
				i++;
		}
		else if (str[i] == '"')
		{
			i++;
			while (str[i] != '"' && str[i])
				i++;
			if (str[i] == '"')
				i++;
		}
		if (str[i] == '|')
		{
			i++;
			count++;
		}
	}
	return (count);
}

int	pipe_syntax(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '|')
		{
			printf("--Inside the if\n");
			while (str[i])
			{
				if (str[i] != ' ' || str[i] != '\t'
					|| str[i] != '|' || str[i] != '<' || str[i] != '>'
					|| str[i] == '\0')
					return (1);

				i++;
			}
		}
		i++;
	}
	return (0);
}
