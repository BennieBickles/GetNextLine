/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtortrot <mtortrot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 12:26:59 by mtortrot          #+#    #+#             */
/*   Updated: 2022/09/12 09:14:21 by mtortrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(int fd, char **line)
{
	int	i;
	char	*str;

	i = 1;
	str = (char *)malloc (BUFFER_SIZE + 1);
	if (*line == NULL)
		*line = ft_strdup("");
	while (i && !ft_strchr(*line, '\n'))
	{
		i = read (fd, str, BUFFER_SIZE);
		if (i == -1)
		{
			free (str);
			return (NULL);
		}
		str[i] = '\0';
		*line = ft_strjoin (*line, str);
	}
	free (str);
	return (NULL);
}

char	*split_line(char **line)
{
	char	*str;
	char	*tmp;

	if (!ft_strchr(*line, '\n'))
	{
		tmp = ft_strdup (*line);
		free (*line);
		*line = NULL;
	}
	else
	{
		tmp = ft_substr(*line, 0, ft_strchr (*line, '\n') - *line + 1);
		str = ft_strdup (ft_strchr (*line, '\n') + 1);
		free (*line);
		*line = str;
	}
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	get_line(fd, &rest);
	if (rest && rest[0] != 0)
		line = split_line(&rest);
	if (rest && rest[0] == 0)
	{
		free (rest);
		rest = NULL;
	}
	return (line);
}
