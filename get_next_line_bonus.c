/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aausman <aausman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:58:02 by aausman           #+#    #+#             */
/*   Updated: 2024/02/05 12:44:48 by aausman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= 2147483647)
		return (NULL);
	buffer[fd] = ft_read(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = ft_new_line(buffer[fd]);
	buffer[fd] = ft_remaining(buffer[fd]);
	return (line);
}

char	*ft_read(int fd, char *store)
{
	char	*buffer;
	int		len;

	len = 1;
	buffer = malloc(((size_t)(BUFFER_SIZE) + 1));
	if (!buffer)
		return (NULL);
	if (store == NULL)
		store = ft_strdup("");
	while (len > 0)
	{
		len = read(fd, buffer, BUFFER_SIZE);
		if (len == -1)
		{
			free(store);
			free(buffer);
			return (NULL);
		}
		buffer[len] = '\0';
		store = ft_strjoin(store, buffer);
		if (ft_strchr(store, '\n') != NULL)
			break ;
	}
	free(buffer);
	return (store);
}

char	*ft_new_line(char *buffer)
{
	char		*line;
	int			i;
	int			a;

	i = 0;
	line = NULL;
	if (buffer == NULL || buffer[i] == '\0')
		return (NULL);
	while (buffer[i] != '\0')
		i++;
	line = (char *) malloc(i + 2);
	if (!line)
		return (NULL);
	i = 0;
	a = 0;
	while (buffer[a] && buffer[a] != '\n')
		line[i++] = buffer[a++];
	if (buffer[a] == '\n')
		line[i++] = buffer[a++];
	line[i] = '\0';
	return (line);
}

char	*ft_remaining(char *buffer)
{
	char		*line;
	int			i;
	int			a;

	i = 0;
	a = 0;
	line = NULL;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\0')
	{
		free(buffer);
		return (NULL);
	}
	line = malloc(ft_strlen(buffer) - i);
	if (!line)
		return (NULL);
	i++;
	while (buffer[i] != '\0')
		line[a++] = buffer[i++];
	line[a] = '\0';
	free(buffer);
	return (line);
}
