/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhant-z <kkhant-z@student.42singapor      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 15:31:24 by kkhant-z          #+#    #+#             */
/*   Updated: 2026/02/11 15:31:27 by kkhant-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

char	*get_next_line(int fd);

// utils
int	    ft_strchr(char *str, int c);
int	    ft_strlen(char *str);
void	ft_strcat(char *dest, char *src);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_extract(char *str, char delimiter);

#endif
