/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 16:45:52 by salimon           #+#    #+#             */
/*   Updated: 2022/05/22 09:11:16 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_eof(char **reader, char **line)
{
	if ((*reader)[0] == '\0')
	{
		*line = malloc(sizeof(char) * 1);
		if (!(*line))
			return (-1);
		(*line)[0] = '\0';
	}
	return (0);
}

int		ft_is_n(char **reader, char **line)
{
	char	*tmp;
	int		to_n;

	to_n = 0;
	while ((*reader)[to_n] && (*reader)[to_n] != '\n')
		to_n++;
	*line = ft_substr(*reader, 0, to_n);
	if (!(*line))
		return (-1);
	tmp = ft_substr(*reader, to_n + 1, ft_strlen(*reader));
	if (!tmp)
		return (-1);
	free(*reader);
	*reader = tmp;
	return (1);
}

char	*ft_manage_reader(char **reader, char *buf)
{
	char	*tmp;

	if (!(*reader))
		*reader = ft_strdup(buf);
	else
	{
		tmp = ft_strjoin(*reader, buf);
		if (!tmp)
			return (NULL);
		free(*reader);
		*reader = ft_strdup(tmp);
		free(tmp);
	}
	return (*reader);
}

int		get_next_line(int fd, char **line)
{
	static char	*reader[260];
	char		buf[BUFFER_SIZE + 1];
	int			check;

	if (!line || fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	while ((check = read(fd, buf, BUFFER_SIZE)) >= 0)
	{
		buf[check] = '\0';
		if (!(reader[fd] = ft_manage_reader(&reader[fd], buf)))
			return (-1);
		if (ft_strchr(reader[fd], '\n'))
			return (ft_is_n(&reader[fd], line));
		*line = reader[fd];
		if (check == 0 || reader[fd] == NULL || reader[fd][0] == '\0')
			return (ft_eof(&reader[fd], line));
	}
	if (check < 0)
		return (-1);
	return (1);
}
