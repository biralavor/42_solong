/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_gnl_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:38:49 by umeneses          #+#    #+#             */
/*   Updated: 2024/04/06 16:18:15 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*gnl_init(t_map *map)
{
	char	*gnl_temp;

	gnl_temp = ft_get_next_line(map->fd);
	map->line = ft_strtrim(gnl_temp, "\n");
	free (gnl_temp);
	if (map->line != NULL)
		map->first_lenght = ft_strlen(map->line) - 1;
	return (gnl_temp);
}

bool	map_size_approved(t_map *map)
{
	char	*gnl_temp;

	gnl_temp = gnl_init(map);
	while (map->line != NULL)
	{
		map->width = ft_strlen(map->line) - 1;
		if (!map_bad_format(map))
		{
			map->matrix = map_allocation(map->matrix, map->line, map->height);
			map->height++;
			map->size = map->height * map->width;
			gnl_temp = ft_get_next_line(map->fd);
			map->line = ft_strtrim(gnl_temp, "\n");
			free (gnl_temp);
		}
		else
		{
			free(map->line);
			return (close(map->fd), false);
			break ;
		}
	}
	free(map->line);
	close(map->fd);
	return (true);
}
