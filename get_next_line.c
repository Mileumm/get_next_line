/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbahin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:29:46 by tbahin            #+#    #+#             */
/*   Updated: 2024/11/28 16:19:32 by tbahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*line = NULL;
	char	*dest;
	long long	len;
	char	buf[BUFFER_SIZE];

	len = 0;
	while (len < BUFFER_SIZE)
	{
		buf[len] = '\0';
		len++;
	}
	len = ft_check(line);
	dest = NULL;
	if (len != (-1))
	{
		if (len == 0)
			return (NULL);
		dest = malloc(sizeof(char) * (len + 1));
		if (!dest)
			return (NULL);
		line = ft_strcpy(line, dest);
		return (dest);
	}
	read(fd, buf, BUFFER_SIZE);
	if (buf[0] == '\0')
		return (NULL);
	line = ft_strcat(buf, line);
	dest = get_next_line(fd);
	return (dest);
}
