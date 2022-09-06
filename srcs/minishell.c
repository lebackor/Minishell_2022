/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebackor <lebackor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 17:30:41 by lebackor          #+#    #+#             */
/*   Updated: 2022/09/02 18:06:05 by lebackor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	minishell_init(t_data *s, t_env *env, t_pipe *cmds_list)
{
	s->rdline = readline(MINISH _GREEN"$ " _END);
	while (s->rdline)
	{
		if (check_syntax(s->rdline) == 1)
			free(s->rdline);
		if (ft_strcmp(s->rdline, "exit") == 0)
			return (free (s->rdline), printf("exit\n"), 1);
		add_history(s->rdline);
		s->cmds_tab = check_quotes(s->rdline, cmds_list);
		ft_redir_input(s);
		if (ft_search_bultins(s, env) != 0)
			ft_execution(env, s);
		destroy_cmds_args(s->cmds_tab);
		free(s->rdline);
		s->rdline = readline(MINISH _GREEN"$ " _END);
	}
	return (0);
}

int	main(int ac, char **av, char **envp)
{
	t_data	*s;
	t_env	*env;
	t_pipe	cmds_list;

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
		minishell_init(s, env, &cmds_list);
		ft_clean(env, s);
	}
	return (0);
}
