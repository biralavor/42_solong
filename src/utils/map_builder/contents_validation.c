/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contents_validation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:38:49 by umeneses          #+#    #+#             */
/*   Updated: 2024/01/31 16:24:28 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	*map_contens_checker(t_map *map)
{
	ft_printf("\nEntering MAP_ITEMS_CHECKER:\n");
	if (has_specific_char(map, 'P', 1) == true)
		ft_printf("Player = true\n");
	if (has_specific_char(map, 'C', NULL) == true)
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
	x = 0;
	while ((x <= map->height - 1) && map->matrix)
	{
		y = 0;
		while (y <= map->width - 1)
		{
			ft_printf("map->matrix[%d][%d] = %c\n", x, y, map->matrix[x][y]);
			if (tofind == map->matrix[x][y])
				found++;
			y++;
		}
		if ((x == map->height - 1) && (y == map->width))
			break ;
		x++;
	}
	if (limiter == NULL)
		limiter = 999;
	ft_printf("%c = %d found! Limiter was = %d\n", tofind, found, limiter);
	if (found > limiter)
	{
		ft_putendl_fd("\nError\nToo much specific items on map!\n", \
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
