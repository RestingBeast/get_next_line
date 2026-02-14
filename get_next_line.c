/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhant-z <kkhant-z@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 15:35:41 by kkhant-z          #+#    #+#             */
/*   Updated: 2026/02/14 20:20:30 by kkhant-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*trim_delimiter(char *str, char delimiter)
{
	int		pos;
	int		i;
	int		len;
	char	*res;

	pos = ft_strchr(str, delimiter);
	if (pos == 0)
		return (free(str), NULL);
	len = ft_strlen(str) - pos;
	if (len == 0)
		return (free(str), NULL);
	res = malloc(len + 1);
	if (!res)
		return (free(str), NULL);
	i = 0;
	while (str[pos] != '\0')
	{
		res[i] = str[pos];
		pos++;
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
