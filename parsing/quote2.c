/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchan <vchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:48:46 by vchan             #+#    #+#             */
/*   Updated: 2022/11/14 14:49:26 by vchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	quote_or_not(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '"' || str[i] == '\'')
			return (1);
		i++;
	}
	return (0);
}

int	if_quote(char c, int quote)
{
	if (c == '\'' && quote == 0)
		return (1);
	return (0);
}

int	if_double_quote(char c, int double_quote)
{
	if (c == '"' && double_quote == 0)
		return (1);
	return (0);
}

int	which_quote(char *str)
{
	int	i;
	int	double_quote;
	int	quote;

	i = 0;
	quote = 0;
	double_quote = 0;
	while (str[i])
	{
		if (str[i] == '"')
			double_quote = i;
		else if (str[i] == '\'')
			quote = i;
		if (quote < double_quote)
			return (1);
		else
			return (0);
		i++;
	}
	return (0);
}
