/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleite-b <aleite-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:36:15 by aleite-b          #+#    #+#             */
/*   Updated: 2023/11/15 13:11:45 by aleite-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = -1;
	j = 0;
	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	while (s2[j])
		str[i++] = s2[j++];
	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (str);
}

int	ft_strchr(const char *s, int c)
{
	if (!s || c == '\0')
		return (0);
	while (*s != '\0' && *s != (unsigned char)c)
		s++;
	if (*s == (unsigned char)c)
		return (1);
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	void			*arr;
	size_t			i;
	unsigned char	*p;

	i = 0;
	if (size != 0 && (count * size / count != size))
		return (NULL);
	if (count == 0 || size == 0)
		return (malloc(0));
	arr = malloc(count * size);
	if (!arr)
		return (NULL);
	p = arr;
	while (i < count * size)
	{
		*p++ = 0;
		i++;
	}
	return (arr);
}
