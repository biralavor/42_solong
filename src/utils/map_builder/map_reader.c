/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:29:17 by umeneses          #+#    #+#             */
/*   Updated: 2024/01/29 11:21:53 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	map_opener(char **argv, t_map *map)
{
	map->fd = open(argv[1], O_RDONLY);
	ft_printf("map->fd = %d\n", map->fd);
	if (map->fd == -1)
	{
		ft_putendl_fd("Error!\nInvalid map file T.T", STDOUT_FILENO);
		close(map->fd);
		return (false);
	}
	return (true);
}

bool	map_reader(t_map *map)
{
	int32_t	buffer_len;
	char	*buffer;

	buffer_len = 1;
	map->line = ft_calloc(1,sizeof(char));
	buffer = ft_calloc(BUFFERSIZE + 1, sizeof(char));
	while ((buffer_len > 0))
	{
		buffer_len = read(map->fd, buffer, BUFFERSIZE);
		if (buffer < 0)
		{
			free (buffer);
			return (false);
		}
		// if (buffer == 0)
		// 	return (map->line);
		buffer[buffer_len] = '\0';
		map->line = ft_strjoin(map->line, buffer);
	}
	// close(fd);
	return (true);
}
