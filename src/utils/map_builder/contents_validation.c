/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contents_validation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:38:49 by umeneses          #+#    #+#             */
/*   Updated: 2024/01/31 17:18:36 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	*map_contens_checker(t_map *map)
{
	ft_printf("\nEntering MAP_ITEMS_CHECKER:\n");
	if (has_specific_char(map, 'P', 1) == true)
		ft_printf("Player = true\n");
	if (has_specific_char(map, 'C', 0) == true)
		ft_printf("Collectable = true\n");
	if (has_specific_char(map, 'E', 1) == true)
		ft_printf("Exit = true\n");
	return (false);
}

bool	*has_specific_char(t_map *map, char tofind, int limiter)
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
	if (limiter == 0)
		limiter = 999;
	ft_printf("%c = %d found! Limiter was = %d", tofind, found, limiter);
	if (found > limiter)
	{
		ft_putendl_fd("\nError\nToo much specific items on map!", \
						STDOUT_FILENO);
		return (false);
	}
	return (true);
}

// bool	*has_wall(t_map *map)
// {
// 	char	*tofind;
// 	int		wall_topdown;

// 	tofind = "1";
// 	x = 0;
// 	while (x <= map->height - 1)
// 	{
// 		wall_topdown = ft_strnstr(map->matrix[x], tofind, map->width - 1);
// 		while (!wall_topdown)
// 		{
// 			x++;
// 			wall = ft_strnstr(map->matrix[x], tofind, map->width - 1);
// 			if (x == map->height - 1)
// 			{
// 				ft_putendl_fd("\nError\nWall not found!\n", STDOUT_FILENO);
// 				return (false);
// 			}
// 		}
// 		break ;
// 	}
// 	return (true);
// }
