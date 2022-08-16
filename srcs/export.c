#include "../include/minishell.h"

int ft_export(t_data *s, t_env *envp)
{
	s->i = 0;
	while (s->rdline[s->i] != ' ')
		s->i++;
	while (s->rdline[s->i] == ' ')
		s->i++;
	while ((s->rdline[s->i] >= 'a' && s->rdline[s->i] <= 'z')
		|| (s->rdline[s->i] >= 'A' && s->rdline[s->i] <= 'Z'))
		s->i++;
	if (s->rdline[s->i] != '=')
		return (ft_printf("bash: export: `%c': not a valid identifier\n", s->rdline[s->i]));
	else
	{
		if (!((s->rdline[s->i + 1] >= 'a' && s->rdline[s->i + 1] <= 'z') || (s->rdline[s->i + 1] >= 'A' && s->rdline[s->i + 1] <= 'Z') || (s->rdline[s->i + 1] >= '0' && s->rdline[s->i + 1] <= '9')))
			return (ft_printf("bash: export: `%c': not a valid identifier\n", s->rdline[s->i + 1]));
		return (ft_put_in_env(s, envp));
	}
	return (ft_printf("bash: export: `%c': not a valid identifier\n", s->rdline[s->i]));
}

int ft_put_in_env(t_data *s, t_env *envp)
{
	int		i;
	(void)	envp;
	i = 0;
	while (s->rdline[i] != ' ')
		i++;
	while (s->rdline[i] == ' ')
		i++;
   // ft_addback(&envp, &s->rdline[i]);
	return (0);
}
