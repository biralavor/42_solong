/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contents_validation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:38:49 by umeneses          #+#    #+#             */
/*   Updated: 2024/04/06 19:14:15 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	map_contents_checker(t_map *map)
{
	if ((has_walls(map) == true) &&						\
		(has_specific_char(map, 'P', 1) == true) &&		\
		(has_specific_char(map, 'E', 1) == true) &&		\
		(has_specific_char(map, 'C', 999) == true) && 	\
		(is_char_locked(map) == false)
		&& (has_illegal_char(map) == false))
		how_many_walls(map);
		return (true);
	return (false);
}

bool	has_illegal_char(t_map *map)
{
	char	found;
	int32_t	x;
	int32_t	y;

	found = '\0';
	y = -1;
	while ((++y <= map->height - 1) && map->matrix)
	{
		x = -1;
		while (++x <= map->width - 1)
		{
			found = map->matrix[y][x];
			if (!(found == '1' || found == '0' || found == 'P' || found == 'E' || found == 'C'))
			{
				ft_putendl_fd("\nError.\nYour MAP has an illegal char.", STDOUT_FILENO);
				return (true);
				break ;
			}
		}
	}
	return (false);
}

bool	has_specific_char(t_map *map, char tofind, int limiter)
{
	int32_t	found;
	int32_t	x;
	int32_t	y;

	map->coin_index = 0;
	found = 0;
	y = -1;
	while ((++y <= map->height - 1) && map->matrix)
	{
		x = -1;
		while (++x <= map->width - 1)
		{
			if (tofind == map->matrix[y][x])
				found++;
		}
		if ((y == map->height - 1) && (x == map->width))
			break ;
	}
	map->coin_index = found;
	if ((found > limiter) || (tofind == 'C' && found == 0))
	{
		ft_putendl_fd("\nError.\nItems on MAP doesn't match requirements: \
						\nPlayer = 1\nExit = 1\nCollectables = 1 or more...", \
						STDOUT_FILENO);
		return (false);
	}
	return (true);
}

bool	is_char_locked(t_map *map)
{
	int32_t	x;
	int32_t	y;
	char	item;

	item = '\0';
	y = -1;
	while ((++y <= map->height - 1) && map->matrix)
	{
		x = -1;
		while (++x <= map->width)
		{
			item = map->matrix[y][x];
			if (item == 'P' || item == 'E' || item == 'C')
			{
				if ((map->matrix[y - 1][x] == '1') 
					&& (map->matrix[y + 1][x] == '1'))
				{
					if ((map->matrix[y][x - 1] == '1') 
						&& (map->matrix[y][x + 1] == '1'))
					{
						ft_putendl_fd("\nError.\nYour MAP is locking an item.", 
										STDOUT_FILENO);
						return (true);
					}	
				}
			}
		}
	}
	return (false);
}
