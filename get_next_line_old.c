/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhant-z <kkhant-z@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 15:35:41 by kkhant-z          #+#    #+#             */
/*   Updated: 2026/02/13 08:31:22 by kkhant-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*trim_delimiter(char *str, char delimiter)
{
	int		len;
	int		d_index;
	int		i;
	char	*res;

	if (!str)
		return (NULL);
	d_index = ft_strchr(str, delimiter);
	len = ft_strlen(str) - d_index;
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (str[d_index] != '\0')
	{
		res[i] = str[d_index++];
		i++;
	}
	res[i] = '\0';
	free(str);
	return (res);
}

static char	*handle_zero_bytes_read(char **str, char delimiter)
{
	char	*res;

	if (ft_strchr(*str, delimiter))
		return (extract_line(*str, delimiter));
	else if (ft_strlen(*str) > 0)
	{
		res = extract_line(*str, '\0');
		free(*str);
		*str = NULL;
		return (res);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*leftover = NULL;
	const char	delimiter = '\n';
	char		buf[BUFFER_SIZE + 1];
	int			bytes_read;

	leftover = trim_delimiter(leftover, delimiter);
	bytes_read = read(fd, buf, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buf[bytes_read] = '\0';
		leftover = combine_data(leftover, buf);
		if (ft_strchr(leftover, delimiter))
			return (extract_line(leftover, delimiter));
		bytes_read = read(fd, buf, BUFFER_SIZE);
	}
	if (bytes_read == 0)
		return (handle_zero_bytes_read(&leftover, delimiter));
	return (NULL);
}
