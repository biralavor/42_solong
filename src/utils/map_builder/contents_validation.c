/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contents_validation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:38:49 by umeneses          #+#    #+#             */
/*   Updated: 2024/02/05 18:56:46 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	map_contens_checker(t_map *map)
{
	ft_printf("\nEntering MAP_ITEMS_CHECKER:\n");
	if ((has_specific_char(map, 'P', 1) == true) &&		\
		(has_specific_char(map, 'E', 1) == true) &&		\
		(has_specific_char(map, 'C', 999) == true) &&	\
		(has_walls(map) == true))
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
	y = 0;
	while ((x <= map->height - 1) && (map->matrix) && (y <= map->width - 1))
	{
		while ((x == 0) && (y <= map->width - 1))
		{
			ft_printf("matching map->matrix[%d][%d] = %c\n", x, y, map->matrix[x][y]);
			if (matching_matrix_x_pos(x, y, map, tofind) == true)
				y++;
			else
				break ;
		}
		x++;
		ft_printf("x = %d\n", x);
		y = 0;
		while (x >= 1)
		{
			if ((tofind == map->matrix[x][0]) && (tofind == map->matrix[x][map->height - 1]))
			{
				ft_printf("matching map->matrix[%d][%d] = %c\n", x, y, map->matrix[x][y]);
				x++;
			}
			else
				break ;
		}
		while ((x == map->height - 1) && (y <= map->width - 1))
		{
			if (matching_matrix_x_pos(x, y, map, tofind) == true)
				y++;
			else
				break ;
		}
	}
	return (false);
}

bool	matching_matrix_x_pos(int32_t x, int32_t y, t_map *map, char tofind)
{
	while (y <= map->width - 1)
	{
		if (tofind == map->matrix[x][y])
			y++;
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