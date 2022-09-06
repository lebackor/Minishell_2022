/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchan <vchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 17:30:41 by lebackor          #+#    #+#             */
/*   Updated: 2022/09/06 15:26:22 by vchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	minishell_init(t_data *s, t_env *env, t_pipe *cmds_list)
{
	s->rdline = readline(MINISH _GREEN"$ " _END);
	while (s->rdline)
	{
		if (check_syntax(s->rdline) == 1)
			return (free(s->rdline), 1);
		if (ft_strcmp(s->rdline, "exit") == 0)
			return (free (s->rdline), printf("exit\n"), 1);
		add_history(s->rdline);
		s->cmds_tab = check_quotes(s->rdline, cmds_list);
		if (ft_search_bultins(s, env) != 0)
		{
			printf("ici ca marche\n");
			ft_execution(env, s);
			printf("ici ca marche plus\n");
		}
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
