/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 16:19:08 by umeneses          #+#    #+#             */
/*   Updated: 2023/09/29 17:38:43 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_file_container	file;

	if ((!fd || fd < 0) && fd != 0)
		return (NULL);
	if (file.index >= file.read || file.index == 0)
	{
		file.index = 0;
		while (file.index < BUFFER_SIZE)
			file.buffer[file.index++] = '\0';
		file.index = 0;
		file.str = NULL;
		file.len = 0;
		file.fd = fd;
		file.read = read(fd, file.buffer, BUFFER_SIZE);
	}
	if (file.read <= 0 || file.buffer[file.index] == '\0')
		return (NULL);
	return (ft_get_line(&file));
}

char	*ft_get_line(t_file_container *file)
{
	file->len = 0;
	while (file->read > 0)
	{
		ft_join_let(&file->str, ft_get_let(*(file->buffer + file->index)));
		if (*(file->buffer + file->index) == '\n'
			|| *(file->buffer + file->index) == '\0')
			break ;
		file->index++;
		file->len++;
		if (file->index >= file->read)
		{
			file->index = 0;
			file->read = read(file->fd, file->buffer, BUFFER_SIZE);
		}
	}
	if (file->read == -1)
		return (ft_clear_nodes(file->str));
	file->index++;
	file->len++;
	return (ft_join_line(file));
}

char	*ft_join_line(t_file_container *file)
{
	t_char	*next;
	char	*line;
	int		index;

	line = (char *)ft_calloc((file->len + 1), sizeof(char));
	if (!line)
	{
		free (line);
		return (NULL);
	}
	index = 0;
	next = NULL;
	while (file->str)
	{
		next = file->str->next;
		line[index] = file->str->c;
		free(file->str);
		file->str = next;
		index++;
	}
	line[index] = '\0';
	return (line);
}
