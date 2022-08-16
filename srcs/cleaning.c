#include "../include/minishell.h"

void	ft_clean(t_env *env, t_data *s)
{
	t_env	*tmp;

	(void) s;
	tmp = env;
	while (env->next)
	{
		tmp = env;
		env = env->next;
		if (tmp)
			free(tmp);
	}
}
