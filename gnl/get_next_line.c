/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleite-b <aleite-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:36:13 by aleite-b          #+#    #+#             */
/*   Updated: 2023/11/14 14:45:59 by aleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*new_line(char *str)
{
	char	*new_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	new_str = ft_calloc(ft_strlen(str) - i + 1, sizeof(char));
	i++;
	while (str[i])
		new_str[j++] = str[i++];
	free(str);
	return (new_str);
}

char	*get_line(char *str)
{
	char	*line_str;
	int		i;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	line_str = malloc(i + 2);
	if (!line_str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line_str[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line_str[i] = '\n';
		i++;
	}
	line_str[i] = '\0';
	return (line_str);
}

char	*line_to_str(int fd, char *str)
{
	char	*buffer;
	int		bytes;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	bytes = 1;
	while (!(ft_strchr(str, '\n')) && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(buffer);
			return (str);
		}
		else
		{
			buffer[bytes] = '\0';
			str = ft_strjoin(str, buffer);
		}
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = line_to_str(fd, str);
	if (!str)
		return (NULL);
	line = get_line(str);
	str = new_line(str);
	return (line);
}
