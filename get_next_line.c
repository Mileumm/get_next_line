/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbahin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:26:15 by tbahin            #+#    #+#             */
/*   Updated: 2024/11/25 17:50:36 by tbahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>

static ft_cnletters(char *line)
{
	size_t	count;

	count = 0;
	while (line[count] != '\0' && line[count] != '\n')
		count++;
	return  (count);
}

char	*get_next_line(int fd)
{
	char		*line;
	static size_t	nbletters;
	size_t		nblines;
	char	buf[1000]
	line =  NULL;
	nbletters = 0;
	nblines = 0;
	read(fd,  buf, BUFFER_SIZE);
	nbletters += ft_cnletters();
	
}
