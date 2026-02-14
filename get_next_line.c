/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhant-z <kkhant-z@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 15:35:41 by kkhant-z          #+#    #+#             */
/*   Updated: 2026/02/14 16:48:53 by kkhant-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*trim_delimiter(char *str, char delimiter)
{
	int		pos;
	int		i;
	char	*res;

	pos = ft_strchr(str, delimiter);
	if (pos == 0)
		return (free(str), NULL);
	res = malloc(ft_strlen(str) - pos);
	if (!res)
		return (NULL);
	i = 0;
	while (str[++pos] != '\0')
	{
		res[i] = str[pos];
		i++;
	}
	res[i] = '\0';
	return (free(str), res);
}

static char	*extract_and_trim(char **leftover, char delimiter)
{
	char	*res;

	res = ft_extract(*leftover, delimiter);
	*leftover = trim_delimiter(*leftover, delimiter);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*leftover = NULL;
	const char	delimiter = '\n';
	char		*buf;
	int			bytes_read;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	bytes_read = read(fd, buf, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buf[bytes_read] = '\0';
		leftover = ft_strjoin(leftover, buf);
		if (ft_strchr(leftover, delimiter))
			return (free(buf), extract_and_trim(&leftover, delimiter));
		bytes_read = read(fd, buf, BUFFER_SIZE);
	}
	if (bytes_read == 0 && leftover != NULL)
		return (free(buf), extract_and_trim(&leftover, delimiter));
	return (free(buf), NULL);
}
