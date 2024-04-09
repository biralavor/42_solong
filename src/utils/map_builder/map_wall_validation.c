/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_wall_validation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 19:13:01 by umeneses          #+#    #+#             */
/*   Updated: 2024/04/09 18:34:10 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	top_wall_reading(t_map *map)
{
	char	tofind;

	tofind = '1';
	map->read_x = -1;
	if (map->matrix[0][0] == tofind)
	{
		while ((++map->read_x <= map->width - 1)
			&& (map->matrix[0][map->read_x] == tofind))
		{
			if (map->read_x == map->width)
			{
				return (true);
				break ;
			}
		}
	}
	ft_putendl_fd("\nError.\nYour MAP has a breach on the top_wall.",
		STDOUT_FILENO);
	return (false);
}

bool	middle_wall_reading(t_map *map)
{
	char	tofind;

	tofind = '1';
	map->read_y = 1;

	if (map->matrix[map->read_y][0] == tofind)
	{
		while (++map->read_y <= map->height - 1)
		{
			if (map->matrix[map->read_y][map->width - 1] == tofind)
			{
				if (map->read_y == map->height - 1)
				{
					return (true);
					break ;
				}
			}
		}
	}
	ft_putendl_fd("\nError.\nYour MAP has a breach on the middle_wall.",
		STDOUT_FILENO);
	return (false);
}

bool	bottom_wall_reading(t_map *map)
{
	char	tofind;

	tofind = '1';
	map->read_x = -1;
	if (map->matrix[map->height - 1][0] == tofind)
	{
		while (++map->read_x <= map->width - 1)
		{
			if (map->matrix[map->height - 1][map->read_x] == tofind)
				if (map->matrix[map->height - 1][map->width - 1] == tofind)
				{
					return (true);
					break ;
				}
		}
	}
	ft_putendl_fd("\nError.\nYour MAP has a breach on the bottom_wall.",
		STDOUT_FILENO);
	return (false);	
}

bool	has_walls(t_map *map)
{
	if (top_wall_reading(map))
	{
		if (middle_wall_reading(map))
			if (bottom_wall_reading(map))
				return (true);
	}		
	ft_putendl_fd("\nError.\nBreach on the wall.", STDOUT_FILENO);
	return (false);
}

void	how_many_walls(t_map *map)
{
	char	wall;

	wall = '1';
	map->read_y = -1;
	map->border_index = -1;
	while ((++map->read_y <= map->height - 1) && map->matrix)
	{
		map->read_x = -1;
		while (++map->read_x <= map->width)
		{
			if (wall == map->matrix[map->read_y][map->read_x])
				map->border_index++;
		}
	}
}
