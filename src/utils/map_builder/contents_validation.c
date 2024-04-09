/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contents_validation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:38:49 by umeneses          #+#    #+#             */
/*   Updated: 2024/04/09 17:43:31 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	map_contents_checker(t_map *map)
{
	if (has_walls(map))
	{
		if ((has_specific_char(map, 'P', 1))
			&& (has_specific_char(map, 'E', 1))
			&& (has_specific_char(map, 'C', 999)))
		{
			if (!is_char_locked(map) && !has_illegal_char(map))
			{
				how_many_walls(map);
				ft_printf("\nspecific char APPROVED\n");
				return (true);
			}
		}
	}
	ft_printf("\n\nspecific char NOT passed\n");
	return (false);
}

bool	has_illegal_char(t_map *map)
{
	char	found;

	found = '\0';
	map->read_y = -1;
	while ((++map->read_y <= map->height - 1) && map->matrix)
	{
		map->read_x = -1;
		while (++map->read_x <= map->width - 1)
		{
			found = map->matrix[map->read_y][map->read_x];
			if (!(found == '1' || found == '0'
					|| found == 'P' || found == 'E' || found == 'C'))
			{
				ft_putendl_fd("\nError.\n"
					"Your MAP has an illegal char.", STDOUT_FILENO);
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

	found = 0;
	map->read_y = -1;
	while ((++map->read_y <= map->height - 1) && map->matrix)
	{
		map->read_x = -1;
		while (++map->read_x <= map->width - 1)
		{
			if (tofind == map->matrix[map->read_y][map->read_x])
				found++;
		}
		if ((map->read_y == map->height - 1) && (map->read_x == map->width -1))
			break ;
	}
	map->coin_index = found;
	if ((tofind == 'C' && found == 0) || (tofind != 'C' && found != limiter))
	{
		ft_putendl_fd("\nError.\nItems on MAP doesn't match requirements:"
			"\nPlayer = 1\nExit = 1\nCollectables = 1 or more...",
			STDOUT_FILENO);
		return (false);
	}
	return (true);
}

bool	is_char_locked(t_map *map)
{
	char	item;

	item = '\0';
	map->read_y = -1;
	while ((++map->read_y <= map->height - 1) && map->matrix)
	{
		map->read_x = -1;
		while (++map->read_x <= map->width)
		{
			item = map->matrix[map->read_y][map->read_x];
			if (item == 'P' || item == 'E' || item == 'C')
			{
				if ((map->matrix[map->read_y - 1][map->read_x] == '1')
					&& (map->matrix[map->read_y + 1][map->read_x] == '1')
					&& (map->matrix[map->read_y][map->read_x - 1] == '1')
					&& (map->matrix[map->read_y][map->read_x + 1] == '1'))
				{
					ft_putendl_fd("\nError.\nYour MAP is locking an item.",
						STDOUT_FILENO);
					return (true);
				}
			}
		}
	}
	return (false);
}
