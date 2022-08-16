#include "../include/minishell.h"

t_env	*create_liste(t_env *env)
{

	env = malloc(sizeof(t_env));
//	printf("node cree\n");
	*env = (t_env){0};
	env->next = NULL;
	return (env);
}
t_env	*ft_addback(t_env **stack)
{
	t_env	*t_pile;

	if (!(*stack))
	{
		create_liste(*stack);
	//	printf("MDR\n");
	}
	else
	{
		t_pile = *stack;
		while (t_pile->next != NULL)
		{
			t_pile = t_pile->next;
		//	printf("test\n");
		}
		//printf("LOL\n");
		t_pile->next = create_liste(t_pile->next);
	}
	return (*stack);
}
