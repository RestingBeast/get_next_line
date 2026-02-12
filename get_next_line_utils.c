/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhant-z <kkhant-z@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 15:35:53 by kkhant-z          #+#    #+#             */
/*   Updated: 2026/02/13 03:47:37 by kkhant-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*expand_mem(void *ptr, size_t o_size, size_t size)
{
	void	*res;

	if (size < o_size)
		return (ptr);
	res = malloc(size + 1);
	if (!res)
		return (NULL);
	if (ptr)
	{
		while (o_size-- > 0)
			((unsigned char *)res)[o_size]
				= ((unsigned char *)ptr)[o_size];
		free(ptr);
	}
	return (res);
}

size_t	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

void	clear_buffer(char *buf)
{
	int	i;

	i = 0;
	while (buf[i] != '\0')
	{
		buf[i] = '\0';
		i++;
	}
}

void	trim_buffer(char *buf, int index)
{
	int	i;

	i = 0;
	while (buf[index + i] != '\0')
	{
		buf[i] = buf[index + i];
		i++;
	}
	buf[i] = '\0';
}

int	append_until_delimiter(char *dest, char *buf, char delimiter)
{
	int	i;
	int	dest_len;

	dest_len = ft_strlen(dest);
	i = 0;
	while (buf[i] != '\0')
	{
		dest[dest_len + i] = buf[i];
		if (dest[dest_len + i] == delimiter)
		{
			trim_buffer(buf, i + 1);
			dest[dest_len + i + 1] = '\0';
			return (1);
		}
		i++;
	}
	dest[dest_len + i] = '\0';
	clear_buffer(buf);
	return (0);
}
