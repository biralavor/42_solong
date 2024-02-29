/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:29:17 by umeneses          #+#    #+#             */
/*   Updated: 2024/02/29 11:22:26 by umeneses         ###   ########.fr       */
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

bool	map_read(char **argv, t_map *map)
{
	int32_t		fd_temp;
	char		buffer[(MAX_MAP_WIDTH * MAX_MAP_HEIGHT)];

	fd_temp = open(argv[1], O_RDONLY);
	if (fd_temp == -1)
	{
		ft_putendl_fd("Error!\nInvalid map file T.T", STDOUT_FILENO);
		close(fd_temp);
		return (false);
	}
	map->bytes_read = read(fd_temp, buffer, sizeof(buffer));
	if (map->bytes_read > 0)
	{
		map->buffer = ft_calloc(map->bytes_read + 1, sizeof(char));
		ft_memcpy(map->buffer, buffer, map->bytes_read);
		map->buffer[map->bytes_read] = '\0';
		close (fd_temp);
		return (true);
	}
	close (fd_temp);
	return (false);
}
