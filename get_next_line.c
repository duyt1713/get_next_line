/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duha <duha@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 08:04:31 by duha              #+#    #+#             */
/*   Updated: 2024/12/21 06:16:33 by duha             ###   ########.fr       */
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
char	*store_line(int fd)
{
	char	*line;
	ssize_t	bytes;

	line = malloc(100);
	if (!line)
		return (NULL);
	bytes = read(fd, line, BUFFER_SIZE);
	
	return (line);
}

char	*get_next_line(int fd)
{
	char	*line;
	char	*buffer;
	ssize_t	bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);


	return (line);
}
