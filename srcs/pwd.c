/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebackor <lebackor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:50:24 by lebackor          #+#    #+#             */
/*   Updated: 2022/08/30 18:10:39 by lebackor         ###   ########.fr       */
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
/*
int	ft_pwd_maj(t_env *env, t_data *s)
{
	(void) s;
	t_env *tmp;
	char *str;

	tmp = env;
	while (ft_strcmp(tmp->content, "PWD") != 0)
		tmp = tmp->next;
	str = ft_strdup("/");
	str = ft_strjoin(str, s->words[s->i_split + 1]);
	tmp->value = ft_strjoin(tmp->value, str);
	printf("%s\n", tmp->value);
	return (0);
}*/

/*
int	ft_pwd_back(t_env *env, t_data *s)
{
	t_env	*tmp;
	char	*str;

	(void) s;

	tmp = env;
	while (ft_strcmp(tmp->content, "PWD") != 0)
		tmp = tmp->next;
	str = ft_strdup("/");
	str = ft_strjoin(str, s->words[s->i_split + 1]);
	tmp->value = ft_strjoin(tmp->value, str);
	printf("%s\n", tmp->value);
	return (0);
}

*/
