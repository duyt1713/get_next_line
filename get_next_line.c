/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duha <duha@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 08:04:31 by duha              #+#    #+#             */
/*   Updated: 2025/01/05 22:10:53 by duha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

/**
 * get_next_line - Returns a line read from a file descriptor.
 *
 * @fd: The file descriptor to read from.
 *
 * External functions: read, malloc, free
 *
 * Return: Read line: correct behavior
 *         or NULL if there is nothing else to read, or an error occurred.
 */
char	*get_next_line(int fd)
{
	char		*read_buffer;
	static char	*storage;
	char		*line;
	char		*remainer_ptr;
	char 		*remainer;
	ssize_t		bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!storage)
	{
		storage = ft_strdup("");
		if (!storage)
			return (NULL);
	}
	read_buffer = malloc(BUFFER_SIZE + 1);
	if (!read_buffer)
		return (NULL);
	while (ft_strchr(read_buffer, '\n') == NULL)
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
	}
	remainer_ptr = ft_strchr(storage, '\n');
	if (remainer_ptr)
	{
		remainer = ft_strdup(remainer_ptr);
		*remainer_ptr = '\0';
		line = ft_strdup(storage);
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