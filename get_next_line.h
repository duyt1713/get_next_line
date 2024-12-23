/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duha <duha@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 08:04:29 by duha              #+#    #+#             */
/*   Updated: 2024/12/21 05:33:16 by duha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

#include <stdlib.h>

char	*get_next_line(int fd);
size_t	ft_strlen(char *s);
void	*ft_memmove(void *dest, const void *src, size_t n);
char	*ft_strjoin(const char *s1, const char *s2);

char	*store_line(int fd);
char	*get_next_line(int fd);
#endif
