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
	char	buf[BUFFER_SIZE + 1];

	len = 0;
	dest = NULL;
	nb_read = -1;
	len = ft_check(line);
	if (len != (-1))
	{
		dest = malloc(sizeof(char) * (len + 1));
		if (!dest)
			return (NULL);
		line = ft_strcpy(line, dest);
		return (dest);
	}
	nb_read = read(fd, buf, BUFFER_SIZE);
	if (nb_read == -1)
	{
		return (NULL);
	}
	buf[nb_read] = '\0';
	if (nb_read == 0 && line)
	{
		dest = malloc(sizeof(char) * (ft_strlen(line) + 1));
		if (!dest)
			return (NULL);
		line = ft_strcpy(line, dest);
		return (dest);
	}
	else if (buf[0] == '\0' && !line)
		return (NULL);
	line = ft_strcat(buf, line, nb_read + 1);
	dest = get_next_line(fd);
	return (dest);
}
