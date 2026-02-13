/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhant-z <kkhant-z@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 15:35:53 by kkhant-z          #+#    #+#             */
/*   Updated: 2026/02/13 08:29:55 by kkhant-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr(char *str, int c)
{
	int	i;

	if (!str)
		return (0);
	if (c == '\0')
		return (ft_strlen(str));
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (i + 1);
		i++;
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	count;

	if (!str)
		return (0);
	count = 0;
	while (str[count])
		count++;
	return (count);
}

void	ft_strcat_char(char *dest, char *src, char c)
{
	int	i;
	int	dest_len;

	i = 0;
	dest_len = ft_strlen(dest);
	while (src[i] != c)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	if (c != '\0')
		dest[dest_len + (i++)] = c;
	dest[dest_len + i] = '\0';
}

char	*combine_data(char *leftover, char *buf)
{
	int		len;
	char	*res;

	len = ft_strlen(leftover);
	res = malloc(len + BUFFER_SIZE + 1);
	if (!res)
		return (NULL);
	res[0] = '\0';
	if (leftover)
		ft_strcat_char(res, leftover, '\0');
	ft_strcat_char(res, buf, '\0');
	free(leftover);
	return (res);
}

char	*extract_line(char *str, char delimiter)
{
	int		len;
	char	*res;

	if (!str)
		return (NULL);
	len = ft_strchr(str, delimiter);
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	res[0] = '\0';
	ft_strcat_char(res, str, delimiter);
	return (res);
}
