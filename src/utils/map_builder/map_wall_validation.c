/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_wall_validation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 19:13:01 by umeneses          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/04/09 15:13:20 by umeneses         ###   ########.fr       */
=======
/*   Updated: 2024/04/08 20:38:01 by umeneses         ###   ########.fr       */
>>>>>>> dad2e5dada0fe18a405dcce6cae523743cec0cc7
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	top_wall_reading(t_map *map)
{
	char	tofind;
	int32_t	x;

	tofind = '1';
	x = -1;
	if (map->matrix[0][0] == tofind)
	{
		while (++x <= map->width - 1)
		{
			if (map->matrix[0][x] == tofind)
				if (map->matrix[0][map->width - 1] == tofind)
					return (true);
		}
	}
	ft_putendl_fd("\nError.\nYour MAP has a breach on the top_wall.", \
					STDOUT_FILENO);
	return (false);
}

bool	middle_wall_reading(t_map *map)
{
	char	tofind;
	int32_t	y;

	tofind = '1';
<<<<<<< HEAD
	y = 1;
	if ((map->matrix[y][0] == tofind)
=======
	y = 0;
	if ((map->matrix[y][0] == tofind) 
>>>>>>> dad2e5dada0fe18a405dcce6cae523743cec0cc7
			&& (map->matrix[y][map->width - 1] == tofind))
	{
		while (y == map->height - 1)
			return (true);
		y++;
	}
	else
	{
		ft_putendl_fd("\nError.\nYour MAP has a breach on the middle_wall.", \
						STDOUT_FILENO);
		return (false);
	}
}

bool	bottom_wall_reading(t_map *map)
{
	char	tofind;
	int32_t	x;

	tofind = '1';
	x = -1;
	if (map->matrix[map->height - 1][0] == tofind)
	{
		while (++x <= map->width - 1)
		{
			if (map->matrix[map->height - 1][x] == tofind)
				if (map->matrix[map->height - 1][map->width - 1] == tofind)
					return (true);
		}
	}
	ft_putendl_fd("\nError.\nYour MAP has a breach on the bottom_wall.", \
					STDOUT_FILENO);
	return (false);
}

bool	has_walls(t_map *map)
{
	while (map->matrix)
	{
		if (top_wall_reading(map))
		{
			if (middle_wall_reading(map))
				if (bottom_wall_reading(map))
					return (true);
		}
		else
			ft_putendl_fd("\nError.\nBreach on the wall.", STDOUT_FILENO);
	}
	return (false);
}

void	how_many_walls(t_map *map)
{
	char	wall;
	int32_t	y;
	int32_t	x;

	wall = '1';
	y = -1;
	map->border_index = -1;
	while ((++y <= map->height - 1) && map->matrix)
	{
		x = -1;
		while (++x <= map->width)
		{
			if (wall == map->matrix[y][x])
				map->border_index++;
		}
	}
}
