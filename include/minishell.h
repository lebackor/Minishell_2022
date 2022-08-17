/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebackor <lebackor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 17:33:08 by lebackor          #+#    #+#             */
/*   Updated: 2022/08/17 19:06:20 by lebackor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdarg.h>
# include <sys/wait.h>
# include <errno.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <errno.h>
# include <stdbool.h>
# include "../libft/libft.h"
# include "../include/token.h"

typedef struct s_data
{
	char	*rdline;
	char	**cmd;
	char	**words;
	int		i;
	int		i_split;
}	t_data;

typedef struct t_env
{
	char			*content;
	char			*value;
	struct t_env	*next;
}	t_env;

int		ft_search_bultins(t_data *s, t_env *envp);
int		ft_search_echo(t_data *s);
int		ft_print_echo(t_data *s, int a);
int		ft_echo(t_data *s);
t_env	*ft_addback(t_env **stack, char *content, char *value);
t_env	*create_liste(t_env *env, char *content, char *value);
t_env	*put_env(t_env *env, char **envp, t_data *s);
int		ft_search_env(t_data *s);
int		ft_env(t_env *envp, t_data *s);
int		ft_search_export(t_data *s);
int		ft_export(t_data *s, t_env *envp);
int		ft_put_in_env(t_data *s, t_env *envp);
void	ft_put_first_env(t_env *env, char **envp);
void	ft_put_second_env(t_env *env, char **envp);
void	ft_clean(t_env *env, t_data *s);
char	*looking_for_path(t_env *env, t_data *s);
char	*looking_access(t_env *env, t_data *s);
void	ft_print_split(char **str);
char	*ft_split_env(char *str, int count);
void	ft_addback_new_env(t_env *env, char *content, char *value);
int		ft_search_unset(t_data *s);
int		ft_unset(t_data *s, t_env *env);
/**************************************************************************** */
/*								PARSING										  */
/**************************************************************************** */
int		check_syntax(char *str);

#endif
