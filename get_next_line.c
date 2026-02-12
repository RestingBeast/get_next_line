/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhant-z <kkhant-z@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 15:35:41 by kkhant-z          #+#    #+#             */
/*   Updated: 2026/02/13 03:47:57 by kkhant-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	char		*res;
	size_t		size;
	const char	delimiter = '\n';
	static char	buf[BUFFER_SIZE + 1];

	size = 2 * BUFFER_SIZE;
	res = malloc(size + 1);
	if (!res)
		return (NULL);
	res[0] = '\0';
	if (ft_strlen(buf) > 0 && append_until_delimiter(res, buf, delimiter))
		return (res);
	while (read(fd, buf, BUFFER_SIZE) > 0)
	{
		buf[BUFFER_SIZE] = '\0';
		if (append_until_delimiter(res, buf, delimiter))
			return (res);
		res = expand_mem(res, size, (size + BUFFER_SIZE));
		size += BUFFER_SIZE;
	}
	free(res);
	return (NULL);
}
