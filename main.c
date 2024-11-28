/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbahin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:02:05 by tbahin            #+#    #+#             */
/*   Updated: 2024/11/28 17:15:44 by tbahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int	fd;
	int	fd2;
	char	*line;
	int	i;

	i = 0;
	fd = open("test.txt", O_RDONLY);
	fd2 = open("dest.txt", O_WRONLY);
	if (fd == -1 || fd2 == -1)
		return (1);
	line = get_next_line(fd);
	while (line)
	{
		i = 0;
		printf("%s", line);
		while (line[i])
		{
			write(fd2, &line[i], 1);
			i++;
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	close(fd2);
	return (0);
}
