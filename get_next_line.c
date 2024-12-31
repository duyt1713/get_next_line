/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duha <duha@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 08:04:31 by duha              #+#    #+#             */
/*   Updated: 2024/12/31 20:21:35 by duha             ###   ########.fr       */
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
	t_struct	gnl;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

















		
	if (!gnl.storage_buffer)
		gnl.storage_buffer = ft_calloc(1, sizeof(char));
	gnl.read_buffer = malloc(BUFFER_SIZE + 1);
	if (!gnl.read_buffer)
		return (NULL);
	while (!ft_strchr(buffer, '\n'))
	{
		if (*buffer)
		{
			current_line = ft_strjoin_free(current_line, buffer);
			*buffer = '\0';
		}
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes <= 0)
			return (bytes == 0 && *current_line ? current_line : (free(current_line), NULL));
		buffer[bytes] = '\0';
	}
	new_line = ft_strchr(buffer, '\n');
	current_line = ft_strjoin_free(current_line, buffer);
	current_line = ft_strjoin_free(current_line, "\n");
	ft_memmove(buffer, new_line + 1, ft_strlen(new_line + 1) + 1);
	return (current_line);
}
