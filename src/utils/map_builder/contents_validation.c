/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contents_validation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bira <bira@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:38:49 by umeneses          #+#    #+#             */
/*   Updated: 2024/02/15 16:28:37 by bira             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	map_contens_checker(t_map *map)
{
	ft_printf("\nEntering MAP_ITEMS_CHECKER:\n");
	if ((has_specific_char(map, 'P', 1) == true) &&		\
		(has_specific_char(map, 'E', 1) == true) &&		\
		(has_specific_char(map, 'C', 999) == true) && 	\
		(has_walls(map) == true) &&						\
		(is_char_locked(map) == false) &&				\
		(has_illegal_char(map) == false))
		return (true);
	return (false);
}

/* TODO has_illegal_char*/

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
	ft_printf("%c = %d found! Limiter was = %d\n", tofind, found, limiter);
	if ((found > limiter) || (tofind == 'C' && found == 0))
	{
		ft_putendl_fd("\nError \
					\nThe specific items on map doesn't match requirements! \
					\n Player = 1;\n Exit = 1;\n Collectables = 1 or more.\n", \
						STDOUT_FILENO);
		return (false);
	}
	return (true);
}

/* TODO reduce function size */

bool	has_walls(t_map *map)
{
	char	tofind;
	int32_t	x;
	int32_t	y;

	tofind = '1';
	x = 0;
	y = -1;
	while ((++y <= map->height - 1) && (map->matrix) && (x <= map->width))
	{
		while ((y == 0) && (x <= map->width))
		{
			if (matching_matrix_x_pos(y, x, map, tofind) == true)
				x++;
			else
			{
				return (false);
				break ;
			}
		}
		x = 0;
		while ((y >= 1) && (y < map->height - 1))
		{
			if ((tofind == map->matrix[y][0]) && (tofind == map->matrix[y][map->width]))
				y++;
			else
			{
				return (wall_err_msg());
				break ;
			}
		}
		while ((y == map->height - 1) && (x <= map->width))
		{
			if (matching_matrix_x_pos(y, x, map, tofind) == true)
				x++;
			else
			{
				return (false);
				break ;
			}
		}
	}
	return (true);
}

bool	matching_matrix_x_pos(int32_t y, int32_t x, t_map *map, char tofind)
{
	while (x <= map->width - 1)
	{
		if (tofind == map->matrix[y][x])
			x++;
		else
		{
			wall_err_msg();
			return (false);
		}
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
				if ((map->matrix[y - 1][x] == '1') && \
					(map->matrix[y + 1][x] == '1'))
					if ((map->matrix[y][x - 1] == '1') && \
						(map->matrix[y][x + 1] == '1'))
					{
						ft_putendl_fd("Error\nYour map is locking an item.\n", \
									STDOUT_FILENO);
						return (true);	
					}
					else
						break ;
		}
	}
	return (false);
}
