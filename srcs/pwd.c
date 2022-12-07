/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebackor <lebackor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:50:24 by lebackor          #+#    #+#             */
/*   Updated: 2022/11/20 16:25:46 by lebackor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	ft_pwd(void)
{
	char	*str = NULL;
	size_t	len;

	len = 2048; ///faire un while demande a jeremy
	str = getcwd(str, len);
	printf("%s\n", str);
	return (0);
}

int	edit_pwd_env(t_data *s, t_env *env)
{
	t_env	*tmp;
	t_env	*tmp2;
	tmp = env;
	tmp2 = env;
	char	*str = NULL;
	(void) s;

	while (tmp != NULL && ft_strcmp(tmp->content, "PWD") != 0)
		tmp = tmp->next;
	while (tmp2 != NULL && ft_strcmp(tmp2->content, "OLDPWD") != 0)
		tmp2 = tmp2->next;
	if (ft_strcmp(tmp->content, "PWD") == 0 && ft_strcmp(tmp2->content, "OLDPWD") == 0)
	{
		free(tmp2->value);
		tmp2->value = ft_strdup(tmp->value);
		free(tmp->value);
		tmp->value = ft_strdup(getcwd(str, 2048));
	}
	return (0);
}
