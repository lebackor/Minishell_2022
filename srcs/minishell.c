/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebackor <lebackor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 17:30:41 by lebackor          #+#    #+#             */
/*   Updated: 2022/08/24 17:15:22 by lebackor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	minishell_init(t_data *s, t_env *env)
{
	s->rdline = readline(">$");
	s->words = ft_split(s->rdline, ' ');
	ft_search_bultins(s, env);
	ft_free_table(s->words);
	while (ft_strcmp(s->rdline, "exit") != 0)
	{
		if (check_syntax(s->rdline) == 1)
			free(s->rdline);
		add_history(s->rdline);
		s->rdline = readline(">$");
		s->words = ft_split(s->rdline, ' ');
		ft_print_split(s->words);
		if (ft_search_bultins(s, env) != 0)
			ft_execution(env, s);
		ft_free_table(s->words);
	}
	if (ft_strcmp(s->rdline, "exit") == 0)
		return (free(s->rdline), printf("exit\n"), 1);
	return (0);
}

int	main(int ac, char **av, char **envp)
{
	t_data	*s;
	t_env	*env;

	(void)av;
	(void)envp;
	if (ac == 1)
	{
		env = NULL;
		s = malloc(sizeof(t_data));
		*s = (t_data){0};
		//env->all = s;
		s->env = envp;
		env = put_env(env, envp, s);
		minishell_init(s, env);
		ft_clean(env, s);
	}
	return (0);
}
