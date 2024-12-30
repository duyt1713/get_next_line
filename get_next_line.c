/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duha <duha@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 08:04:31 by duha              #+#    #+#             */
/*   Updated: 2024/12/24 05:31:15 by duha             ###   ########.fr       */
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
	static char	*buffer;
	char		*line;
	char		*new_line;
	ssize_t		bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
		buffer = ft_strdup("");
	buffer = read_and_store_line(fd, buffer);
	new_line = ft_strchr(buffer, '\n');
	if (new_line)
	{

	}
	return (line);
}

static char	*read_and_store_line(int fd, char *buffer)
{
	ssize_t	bytes;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL); //NULL or -1?
	bytes = read(fd, buffer, BUFFER_SIZE);
	if (bytes <= 0)
	{
		free(buffer);
		return (NULL);
	}
	buffer[bytes] = '\0';
	return (buffer);
}


Steps:
Read from fd repeatedly until new line or end of file is foud.
At the same time, join read buffers into a big buffer.
When new line is found, split the current read buffer into join, join the part up until the new line to the big buffer.
Big bufer is now the result needed to be parsed to get_next_line.
