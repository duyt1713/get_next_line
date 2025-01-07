/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duha <duha@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 08:04:31 by duha              #+#    #+#             */
/*   Updated: 2025/01/07 13:13:56 by duha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

/**
 * get_next_line - Returns a line read from a file descriptor.
 *
 * @fd: The file descriptor to read from.
 *
 * Return: Read line: correct behavior
 *         or NULL if there is nothing else to read, or an error occurred.
 */
char	*get_next_line(int fd)
{
	char		*read_buffer;
	static char	*storage;
	char		*line;
	char		*newline_ptr;
	char		*remainer;
	ssize_t		bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!storage)
		storage = ft_strdup("");
	if (!storage)
		return (NULL);
	read_buffer = malloc(BUFFER_SIZE + 1);
	if (!read_buffer)
		return (NULL);
	while (!ft_strchr(storage, '\n'))
	{
		bytes = read(fd, read_buffer, BUFFER_SIZE);
		if (bytes <= 0)
		{
			free(read_buffer);
			if (bytes == 0 && *storage)
			{
				line = ft_strdup(storage);
				free (storage);
				storage = NULL;
				return (line);
			}
			free (storage);
			storage = NULL;
			return (NULL);
		}
		read_buffer[bytes] = '\0';
		storage = ft_strjoin_free(storage, read_buffer);
		if (!storage)
		{
			free(read_buffer);
			return (NULL);
		}
	}
	newline_ptr = ft_strchr(storage, '\n');
	if (newline_ptr)
	{
		remainer = ft_strdup(newline_ptr + 1);
		if (!remainer)
		{
			free(storage);
			storage = NULL;
			free(read_buffer);
			return (NULL);
		}
		*(newline_ptr + 1) = '\0';
		line = ft_strdup(storage);
		if (!line)
		{
			free(storage);
			storage = NULL;
			free(read_buffer);
			return (NULL);
		}
		free(storage);
		storage = remainer;
		free(read_buffer);
		return (line);
	}
	line = ft_strdup(storage);
	free(storage);
	storage = NULL;
	free(read_buffer);
	return (line);
}