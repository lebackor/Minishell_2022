#include "../include/minishell.h"

int	ft_search_bultins(t_data *s, t_env *env, t_number *nbr)
{
	if (ft_search_echo(s, nbr) == 0)
		return (ft_echo(s, env, nbr));
	if (ft_search_env(s, nbr) == 0)
		return (ft_env(env, s));
	if (ft_search_export(s, nbr) == 0)
		return (ft_export(s, env, nbr));
	if (ft_search_unset(s, nbr) == 0)
		return (ft_unset(s, &env, nbr));
	if (ft_search_cd(s, nbr) == 0)
		return (ft_cd(env, s, nbr));
	if (ft_search_pwd(s, nbr) == 0)
		return (ft_pwd());
	return (1);
}

int	ft_search_echo(t_data *s, t_number *nbr)
{
	if (ft_strcmp(s->cmds_tab[nbr->number - 1][0], "echo") == 0)
		return (0);
	else
		return (1);
}

int	ft_search_env(t_data *s, t_number *nbr)
{
	if (ft_strcmp(s->cmds_tab[nbr->number - 1][0], "env") == 0)
		return (0);
	else
		return (1);
}

int	ft_search_export(t_data *s, t_number *nbr)
{
	if (ft_strcmp(s->cmds_tab[nbr->number - 1][0], "export") == 0)
		return (0);
	else
		return (1);
}

int	ft_search_unset(t_data *s, t_number *nbr)
{
	if (ft_strcmp(s->cmds_tab[nbr->number - 1][0], "unset") == 0)
		return (0);
	else
		return (1);
}

int	ft_search_cd(t_data *s, t_number *nbr)
{
	if (ft_strcmp(s->cmds_tab[nbr->number - 1][0], "cd") == 0)
		return (0);
	else
		return (1);
}

int	ft_search_pwd(t_data *s, t_number *nbr)
{
	if (ft_strcmp(s->cmds_tab[nbr->number - 1][0], "pwd") == 0)
		return (0);
	else
		return (1);
}
