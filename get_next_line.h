/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbahin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:30:12 by tbahin            #+#    #+#             */
/*   Updated: 2024/11/27 15:56:51 by tbahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 4
#endif

#include <unistd.h>
#include <stdlib.h>

char    *get_next_line(int fd);
char    *ft_strcpy(char *line, char *dest);
char    *ft_switch(char *line, size_t len);
size_t  ft_strlen(char *str);
char    *ft_strcat(char *src, char *line);
int     ft_check(char *line);
#endif
