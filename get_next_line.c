/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbahin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:29:46 by tbahin            #+#    #+#             */
/*   Updated: 2024/12/01 20:37:55 by tbahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*line = NULL;
	char	*dest;
	int	len;
	int	nb_read;
	char	*buf;

	len = 0;
	nb_read = -1;
	len = ft_check(line);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	if (len != (-1))
	{
		dest = malloc(sizeof(char) * (len + 1));
		if (!dest)
		{
			free(buf);
			return (NULL);
		}
		line = ft_strcpy(line, dest);
		free(buf);
		return (dest);
	}
	nb_read = read(fd, buf, BUFFER_SIZE);
	if (nb_read == -1)
	{
		free(line);
		line = NULL;
		free(buf);
		return (NULL);
	}
	buf[nb_read] = '\0';
	if (nb_read == 0 && line)
	{
		dest = malloc(sizeof(char) * (ft_strlen(line) + 1));
		if (!dest)
			return (NULL);
		line = ft_strcpy(line, dest);
		free (buf);
		return (dest);
	}
	else if (nb_read == 0 && !line)
	{
		free(buf);
		return (NULL);
	}
	line = ft_strcat(buf, line, nb_read + 1, ft_strlen(line));
	free(buf);
	dest = get_next_line(fd);
	return (dest);
}
