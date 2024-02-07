/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contents_validation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bira <bira@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:38:49 by umeneses          #+#    #+#             */
/*   Updated: 2024/02/06 21:17:24 by bira             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	map_contens_checker(t_map *map)
{
	ft_printf("\nEntering MAP_ITEMS_CHECKER:\n");
	if ((has_specific_char(map, 'P', 1) == true) &&		\
		(has_specific_char(map, 'E', 1) == true) &&		\
		(has_specific_char(map, 'C', 999) == true))
		if (has_walls(map) == true)
			ft_printf("\nhas wall = true\n");
		return (true);
	return (false);
}

bool	has_specific_char(t_map *map, char tofind, int limiter)
{
	int32_t	found;
	int32_t	x;
	int32_t	y;

	found = 0;
	x = -1;
	while ((++x <= map->height - 1) && map->matrix)
	{
		y = -1;
		while (++y <= map->width - 1)
		{
			if (tofind == map->matrix[x][y])
				found++;
		}
		if ((x == map->height - 1) && (y == map->width))
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

bool	has_walls(t_map *map)
{
	char	tofind;
	int32_t	x;
	int32_t	y;

	tofind = '1';
	x = 0;
	y = -1;
	while ((++y <= map->height - 1) && (map->matrix) && (x <= map->width - 1))
	{
		while ((y == 0) && (x <= map->width - 1))
		{
			if (matching_matrix_x_pos(y, x, map, tofind) == true)
			{
				ft_printf("matching map->matrix topo [%d][%d] = %c\n", y, x, map->matrix[y][x]);
				x++;
			}
			else
				break ;
		}
		ft_printf("----primeiro while já foi\n");
		x = 0;
		ft_printf("y após primeiro while = %d\n", y);
		ft_printf("x após primeiro while = %d\n", x);
		while ((y >= 1) && (y < map->height - 1) && (x <= map->width - 1))
		{
			if ((tofind == map->matrix[y][x]) && (tofind == map->matrix[y][map->width - 1]))
			{
				ft_printf("matching map->matrix meio [%d][%d] = %c\n", y, x, map->matrix[y][x]);
				ft_printf("matching map->matrix meio [%d][%d] = %c\n", y, map->width - 1, map->matrix[y][map->width - 1]);
				ft_printf("y inside = %d\n", y);
				y++;
			}
			else
				break ;
		}
		ft_printf("----segundo while foi lido\n");
		// y++;
		ft_printf("y após segundo while = %d\n", y);
		ft_printf("x após segundo while = %d\n", x);
		ft_printf("map->height[%d] - 1 = %d\n", map->height, map->height - 1);
		while ((y == map->height - 1) && (x <= map->width - 1))
		{
			if (matching_matrix_x_pos(y, x, map, tofind) == true)
			{
				ft_printf("matching map->matrix topo [%d][%d] = %c\n", y, x, map->matrix[y][x]);
				x++;
			}
			else
				break ;
		}
	}
	return (false);
}

bool	matching_matrix_x_pos(int32_t y, int32_t x, t_map *map, char tofind)
{
	while (x <= map->width - 1)
	{
		if (tofind == map->matrix[y][x])
			x++;
		else
		{
			ft_putendl_fd("\nError\nYou has a breach on the Wall!\n", STDOUT_FILENO);
			return (false);
			break ;
		}
	}
	return (true);
}

// bool	is_char_locked(t_map *map)