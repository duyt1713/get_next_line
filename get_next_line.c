/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duha <duha@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 08:04:31 by duha              #+#    #+#             */
/*   Updated: 2025/01/03 08:06:24 by duha             ###   ########.fr       */
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
	char	*read_buffer;
	

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	if (!gnl.storage_buffer)
		gnl.storage_buffer = ft_calloc(1, sizeof(char));
	if (!gnl.read_buffer)
	{
		gnl.read_buffer = malloc(BUFFER_SIZE + 1);
		if (!gnl.read_buffer)
			return (NULL);
	}

	while (ft_strchr(gnl.storage_buffer, '\n') == NULL)
	{
		gnl.bytes_read = read(fd, gnl.read_buffer, BUFFER_SIZE);
		if (gnl.bytes_read <= 0)
		{
			free(gnl.read_buffer);
			gnl.read_buffer = NULL;
			if (gnl.bytes_read == 0 && *gnl.storage_buffer)
				return (gnl.storage_buffer);
			free(gnl.storage_buffer);
			return (NULL);
		}
		gnl.read_buffer[gnl.bytes_read] = '\0';
		gnl.storage_buffer = ft_strjoin_free(gnl.storage_buffer, gnl.read_buffer);
		if (!gnl.storage_buffer)
		{
			free(gnl.read_buffer);
			return (NULL);
		}
	}
	gnl.new_line_remainer = ft_strchr(gnl.storage_buffer, '\n');
    if (gnl.new_line_remainer)
    {
        *gnl.new_line_remainer = '\0';
        gnl.complete_line = ft_strdup(gnl.storage_buffer);
        gnl.new_line_remainer = ft_strdup(gnl.new_line_remainer + 1);
        free(gnl.storage_buffer);
        gnl.storage_buffer = gnl.new_line_remainer;
        return (gnl.complete_line);
    }
    gnl.complete_line = ft_strdup(gnl.storage_buffer);
    free(gnl.storage_buffer);
    gnl.storage_buffer = NULL;
    return (gnl.complete_line);
}
