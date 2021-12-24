/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriouic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 20:25:53 by adriouic          #+#    #+#             */
/*   Updated: 2021/12/21 22:48:20 by adriouic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/get_next_line.h"
#define BUFFER_SIZE 3

char	*ft_strip(char **s, int rv, char *buff)
{
	int		len;
	char	*temp;
	char	*temp1;

	free(buff);
	buff = NULL;
	if (!(*s) || rv < 0)
		return (NULL);
	len = 0;
	while ((*s)[len] != '\n' && (*s)[len])
		len++;
	temp = ft_substr(*s, 0, len + 1);
	temp1 = ft_substr(*s, len + 1, ft_strlen(*s) - len);
	free(*s);
	if (temp1[0] == '\0')
	{
		*s = NULL;
		free(temp1);
	}
	else
		*s = temp1;
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*s;
	char		*buffer;
	char		*temp;
	int			rv;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	rv = read(fd, buffer, BUFFER_SIZE);
	while (rv > 0)
	{
		buffer[rv] = '\0';
		if (!s)
			s = ft_strdup(buffer);
		else if (buffer)
		{
			temp = ft_strjoin(s, buffer);
			free(s);
			s = temp;
		}
		if (ft_strchr(s, '\n'))
			break ;
		rv = read(fd, buffer, BUFFER_SIZE);
	}
	return (ft_strip(&s, rv, buffer));
}
