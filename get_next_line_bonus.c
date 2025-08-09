/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmorais- <tmorais-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 15:42:15 by tmorais-          #+#    #+#             */
/*   Updated: 2025/08/09 16:15:06 by tmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*extract_line(char *buffer)
{
	char	*line;
	size_t	i;
	size_t	len;

	if (!buffer || !*buffer)
		return (NULL);
	len = 0;
	while (buffer[len] && buffer[len] != '\n')
		len++;
	if (buffer[len] == '\n')
		len++;
	line = malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*update_buffer(char *buffer)
{
	char	*new_buffer;
	char	*nl_pos;
	size_t	i;

	nl_pos = ft_strchr(buffer, '\n');
	if (!nl_pos || !*(nl_pos + 1))
	{
		free(buffer);
		return (NULL);
	}
	nl_pos++;
	new_buffer = malloc(ft_strlen(nl_pos) + 1);
	if (!new_buffer)
	{
		free(buffer);
		return (NULL);
	}
	i = -1;
	while (nl_pos[++i])
		new_buffer[i] = nl_pos[i];
	new_buffer[i] = '\0';
	free(buffer);
	return (new_buffer);
}

static char	*handle_read_error(char *temp, char *buffer)
{
	free(temp);
	free(buffer);
	return (NULL);
}

static char	*read_and_join(int fd, char *buffer)
{
	char	*temp;
	ssize_t	bytes_read;

	temp = malloc(BUFFER_SIZE + 1);
	if (!temp)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(buffer, '\n'))
	{
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read == -1)
			return (handle_read_error(temp, buffer));
		temp[bytes_read] = '\0';
		buffer = ft_strjoin(buffer, temp);
		if (!buffer)
			return (handle_read_error(temp, NULL));
	}
	free(temp);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffers[MAX_FD];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= MAX_FD)
		return (NULL);
	buffers[fd] = read_and_join(fd, buffers[fd]);
	if (!buffers[fd])
		return (NULL);
	line = extract_line(buffers[fd]);
	buffers[fd] = update_buffer(buffers[fd]);
	return (line);
}
