/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebackor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:54:13 by lebackor          #+#    #+#             */
/*   Updated: 2022/04/22 16:24:51 by lebackor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_search_n(char *new_line)
{
	int	i;

	i = 0;
	if (!new_line)
		return (1);
	while (new_line[i])
	{
		if (new_line[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

char	*str_endcpy(char *str, char *new_line)
{
	int	k;

	k = 0;
	while (new_line[k] && new_line[k] != '\n')
		k++;
	if (new_line[k] == '\n')
		str = ft_strcpy(str, &new_line[++k]);
	new_line[--k] = '\0';
	return (new_line);
}

char	*str_n(char *str, char *buffer, char *new_line, int i)
{
	if (i == 0 && ft_search_n(str) == 1)
	{
		if (*str == '\0' && *new_line == '\0')
		{
			free(buffer);
			free(new_line);
			return (NULL);
		}
		else
			free(buffer);
		*str = '\0';
		return (new_line);
	}
	free(buffer);
	free(new_line);
	return (NULL);
}

char	*get_next_line(int fd)
{
	int				i;
	static char		*str = 0;
	char			*buffer;
	char			*new_line;

	i = 1;
	if (!str)
		str = malloc(sizeof(*str) * (BUFFER_SIZE + 1));
	buffer = malloc(sizeof(*buffer) * (BUFFER_SIZE + 1));
	new_line = ft_strdup(str);
	while (ft_search_n(new_line) && i > 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i < 0)
			return (str_n(str, buffer, new_line, i));
		if (i == 0 && ft_search_n(str) == 1)
			return (str_n(str, buffer, new_line, i));
		buffer[i] = '\0';
		new_line = ft_strjoin(new_line, buffer);
	}
	new_line = str_endcpy(str, new_line);
	free(buffer);
	return (new_line);
}
