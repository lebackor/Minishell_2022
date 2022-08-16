#include "../include/minishell.h"

char    *looking_for_path(t_env *env, t_data *s)
{
	//int i = -1;
	t_env	*tmp;
	// char *str;
	tmp = env;

	while (ft_strcmp(tmp->content, "PATH") != 0)
		tmp = tmp->next;
	s->cmd = ft_split(tmp->value, ':');
	//str = looking_access(env, s);
//	while (s->words[++i])
//		printf("%s\n", s->words[i]);
	return (NULL);
}

char 	*looking_access(t_env *env, t_data *s)
{
	(void) env;
	(void) s;
	int i;
	int j;
	char *tmp;
	char *str;

	i = -1;
	j = 1;
	while (s->cmd[++i] && j != 0)
	{
		tmp = ft_strjoin(s->cmd[i], "/");
		str = ft_strjoin(tmp, s->words[i]);
		free(tmp);
		j = access(str, X_OK);
		if (j == 0)
		{
			printf("%s\n", str);
			return (str);
		}
		free(str);
		str = NULL;
	}
	return (NULL);
}


/*
char	*parsep1(t_data *p)
{
	char	*raciste;
	int		i;

	i = -1;
	while (p->paths[++i] && p->j != 0)
	{
		raciste = ft_strjoin(p->paths[i], "/");
		p->cmdargs = ft_strjoin(raciste, p->avsplit[0]);
		free(raciste);
		p->j = access(p->cmdargs, X_OK);
		if (p->j == 0)
			return (p->cmdargs);
		free(p->cmdargs);
		p->cmdargs = NULL;
	}
	return (NULL);
}*/
