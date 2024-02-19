/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contents_validation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:38:49 by umeneses          #+#    #+#             */
/*   Updated: 2024/02/19 16:02:35 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	map_contents_checker(t_map *map)
{
	if ((has_walls(map) == true) &&						\
		(has_illegal_char(map) == false) &&				\
		(has_specific_char(map, 'P', 1) == true) &&		\
		(has_specific_char(map, 'E', 1) == true) &&		\
		(has_specific_char(map, 'C', 999) == true) && 	\
		(is_char_locked(map) == false))
		return (true);
	return (false);
}

bool	has_walls(t_map *map)
{
	char	tofind;
	int32_t	x;
	int32_t	y;

	tofind = '1';
	y = 0;
	x = 0;
	while ((y <= map->height - 1) && (map->matrix))
	{
		if  ((map->matrix[y][0] == tofind) && \
			(map->matrix[y][map->width] == tofind))
			{
				y++;
				if ((y == map-> height - 1) && \
					(map->matrix[y][0] == tofind) && \
					(map->matrix[map->height - 1][map->width] == tofind))
						return (true);
			}
		else
			break ;
	}
	ft_putendl_fd("\nError.\nYour MAP has a breach on the wall.\n", \
					STDOUT_FILENO);
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
				ft_putendl_fd("Error\n Your Map has an illegal char.", STDOUT_FILENO);
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
	if ((found > limiter) || (tofind == 'C' && found == 0))
	{
		ft_putendl_fd("\nError\nItems on Map doesn't match requirements: \
						\nPlayer = 1\nExit = 1\nCollectables = 1 or more...\n", \
						STDOUT_FILENO);
		return (false);
	}
	map->coin_index = found;
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
				if ((map->matrix[y - 1][x] == '1') && \
					(map->matrix[y + 1][x] == '1'))
					if ((map->matrix[y][x - 1] == '1') && \
						(map->matrix[y][x + 1] == '1'))
					{
						ft_putendl_fd("Error\nYour MAP is locking an item.\n", \
									STDOUT_FILENO);
						return (true);	
					}
					else
						break ;
		}
	}
	return (false);
}
