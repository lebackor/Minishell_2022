/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchan <vchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:33:06 by vchan             #+#    #+#             */
/*   Updated: 2022/12/22 17:46:17 by vchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	check_if_quotes(char q, char dq, char *str)
{
	int	i;
	int	count;
	int	ret_value;

	count = 0;
	ret_value = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && count == 1)
		{
			if (str[i] == q)
				count--;
			i++;
		}
		while (str[i] && count == 0)
		{
			if (str[i] == dq)
				ret_value++;
			else if (str[i] == q)
				count++;
			i++;
		}
	}
	if (ret_value % 2 == 1)
		return (printf("%s: Syntax Error, missing quotes\n", MINISH), 1);
	return (0);
}

void	removal(char *dest, char *src)
{
	int	i;
	int	j;
	int	quote;
	int	double_quote;

	quote = 0;
	double_quote = 0;
	j = 0;
	i = 0;
	printf("src = %s\n", src);
	while (src[i])
	{
		while (src[i] && src[i] != '"' && double_quote == 1 && quote == 0)
		{
			dest[j++] = src[i++];
			if (src[i] == '"')
			{
				i++;
				double_quote--;
			}
		}
		while (src[i] && double_quote == 0 && quote == 1)
		{
			dest[j++] = src[i++];
			if (src[i] == '\'')
			{
				i++;
				quote--;
			}
		}
		if (src[i] == '"' && double_quote == 0)
		{
			i++;
			double_quote++;
			if (src[i] == '"')
				break;
		}
		else if (src[i] == '\'' && quote == 0)
		{
			i++;
			quote++;
		}
		while (src[i] && double_quote == 0 && quote == 0)
		{
			dest[j++] = src[i++];
			if (src[i] == '"' || src[i] == '\'')
				break;
		}
	}
	dest[j] = '\0';
	printf("dest = %s8\n", dest);
	return ;
}

//"" chaine vide = '\0' , taille 1 charactere
void	remove_quote(char ***str)
{
	int	i;
	int	y;

	i = 0;
	while (str[i])
	{
		y = 0;
		while (str[i][y])
		{
			if (quote_or_not(str[i][y]))
			{
				if (which_quote(str[i][y]))
					removal(str[i][y], str[i][y]);
				else if (!(which_quote(str[i][y])))
					removal(str[i][y], str[i][y]);
			}
		y++;
		}
	i++;
	}
	return ;
}

char	***check_quotes(char *str, t_env *env)
{
	char	***cmds_args;

	cmds_args = NULL;
	cmds_args = skip_isspace(str);
	expand_fct(cmds_args, env);
	//expand check sans double quote et avec double quote
	remove_quote(cmds_args);
	// int	j = 0;
	// int x = 0;
	// while (cmds_args[x])
	// {
	// 	while (cmds_args[x][j])
	// 	{
	// 		printf("cmds_args[%d][%d] = %s\n", x, j, cmds_args[x][j]);
	// 		j++;
	// 	}
	// 	x++;
	// }
	printf("C BON\n");
	return (cmds_args);
}

int	check_first_quote(char *str, char c, char db_quote)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		while ((str[i] != c && str[i] != db_quote) && str[i])
			i++;
		if (str[i] == c)
		{
			count++;
			i++;
			while (str[i] != c && str[i])
				i++;
			if (str[i] == c)
			{
				count++;
				i++;
			}
		}
		else if (str[i] == db_quote)
		{
			i++;
			while (str[i] != db_quote && str[i])
				i++;
			if (str[i] == db_quote)
				i++;
		}
	}
	return (count);
}
