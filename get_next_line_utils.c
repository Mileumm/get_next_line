/* ***********************************line = ft_strcpy(line, dest);
                *************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbahin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 18:14:32 by tbahin            #+#    #+#             */
/*   Updated: 2024/11/29 16:43:19 by tbahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_check(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (-1);
	while (line[i] != '\0')
	{
		if (line[i] == '\n')
			return (i + 1);
		i++;
	}
	if (line[0] == '\0')
		return (0);
	return (-1);
}

char	*ft_switch(char *line, size_t len)
{
	size_t	i;
	char	*newline;
	size_t	newlen;

	i = 0;
	newlen = ft_strlen(&line[len]);
	newline = malloc(sizeof(char) * (newlen + 1));
	if (!newline)
	{
		free(line);
		return (NULL);
	}
	while (line[len + i] != '\0')
	{
		newline[i] = line[len + i];
		i++;
	}
	newline[i] = '\0';
	if (newline[0] == '\0')
	{
		free (newline);
		free(line);
		return (NULL);
	}
	free(line);
	return (newline);
}

char	*ft_strcpy(char *line, char *dest)
{
	size_t	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '\n')
		{	
			dest[i] = line[i];
			i++;
			break ;
		}
		dest[i] = line[i];
		i++;
	}
	line = ft_switch(line, i);
	dest[i] = '\0';
	return (line);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcat(char *src, char *line, int lens)
{
	int	i;
	char	*str;

	i = 0;
	str = NULL;
	str = malloc(sizeof(char) * (lens + ft_strlen(line) + 1));
	if (!str)
	{
		free(line);
		return (NULL);
	}
	while (i < ft_strlen(line))
	{
		str[i] = line[i];
		i++;
	}
	i = 0;
	while (src[i] && i < lens)
	{
		str[ft_strlen(line) + i] = src[i];
		i++;
	}
	str[ft_strlen(line) + i] = '\0';
	free(line);
	return (str);
}
