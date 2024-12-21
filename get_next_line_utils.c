/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duha <duha@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 08:04:34 by duha              #+#    #+#             */
/*   Updated: 2024/12/21 06:12:40 by duha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	const unsigned char	*s;

	if (!dest || !src)
		return (NULL);
	d = dest;
	s = src;
	if (d > s && d < (s + n))
	{
		while (n--)
			d[n] = s[n];
	}
	else
	{
		while (n--)
			*d++ = *s++;
	}
	return (dest);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*res;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (s2);
	if (!s2)
		return (s1);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	res = malloc(len1 + len2 + 1);
	if (!res)
		return (NULL);
	ft_memmove(res, s1, len1);
	ft_memmove(res + len1, s2, len2);
	res[len1 + len2] = '\0';
	return (res);
}

char	*ft_strchr(const char *s, int c)
{
	const char *p;

	if (!s)
		return (NULL);
	p = s;
	while (*p)
	{
		if (*p == c)
			return (*p);
		p++;
	}
	return (NULL);
}
