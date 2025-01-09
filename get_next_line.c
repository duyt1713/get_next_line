/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duha <duha@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 08:04:31 by duha              #+#    #+#             */
/*   Updated: 2025/01/09 18:46:47 by duha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

/**
 * get_next_line - Returns a line read from a file descriptor.
 *
 * @fd: The file descriptor to read from.
 *
 * Helper function:
 * initialize:    Checks the validity of fd and initializes storage.
 * read_fail_eol: Handles end-of-file and read errors, frees buffers.
 * do_line:       Extracts line from storage and updates storage.
 * free_and_null: Frees storage and read buffer, sets them to NULL.
 *
 * Return: Read line: correct behavior
 *         or NULL if there is nothing else to read, or an error occurred.
 */
char		*get_next_line(int fd);
static int	initialize(int fd, char **storage);
static char	*read_fail_eol(ssize_t bytes, char **read_buffer, char **storage);
static char	*do_line(char **storage, char **read_buffer);
static void	free_and_null(char **storage, char **read_buffer);

char	*get_next_line(int fd)
{
	char		*read_buffer;
	static char	*storage;
	char		*tmp;
	ssize_t		bytes;

	if (initialize(fd, &storage) == 1)
		return (NULL);
	read_buffer = malloc((unsigned int)BUFFER_SIZE + 1);
	if (!read_buffer)
		return (NULL);
	while (!ft_strchr(storage, '\n'))
	{
		bytes = read(fd, read_buffer, BUFFER_SIZE);
		if (bytes <= 0)
			return (read_fail_eol(bytes, &read_buffer, &storage));
		read_buffer[bytes] = '\0';
		tmp = storage;
		storage = ft_strjoin_free(storage, read_buffer);
		if (!storage)
			return (free(tmp), free(read_buffer), NULL);
	}
	return (do_line(&storage, &read_buffer));
}

static int	initialize(int fd, char **storage)
{
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (1);
	if (!*storage)
		*storage = ft_strdup("");
	if (!*storage)
		return (1);
	return (0);
}

static char	*read_fail_eol(ssize_t bytes, char **read_buffer, char **storage)
{
	char	*line;

	free(*read_buffer);
	if (bytes == 0 && **storage)
	{
		line = ft_strdup(*storage);
		if (!line)
			return (NULL);
		free (*storage);
		*storage = NULL;
		return (line);
	}
	free (*storage);
	*storage = NULL;
	return (NULL);
}

static char	*do_line(char **storage, char **read_buffer)
{
	char	*newline_ptr;
	char	*remainer;
	char	*line;

	newline_ptr = ft_strchr(*storage, '\n');
	if (newline_ptr)
	{
		remainer = ft_strdup(newline_ptr + 1);
		if (!remainer)
			return (free_and_null(storage, read_buffer), NULL);
		*(newline_ptr + 1) = '\0';
		line = ft_strdup(*storage);
		if (!line)
			return (free_and_null(storage, read_buffer), NULL);
		free(*storage);
		*storage = remainer;
		free(*read_buffer);
		return (line);
	}
	line = ft_strdup(*storage);
	if (!line)
		return (free_and_null(storage, read_buffer), NULL);
	return (free_and_null(storage, read_buffer), line);
}

static void	free_and_null(char **storage, char **read_buffer)
{
	free(*storage);
	*storage = NULL;
	free(*read_buffer);
}
