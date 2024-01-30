/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contents_validation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:38:49 by umeneses          #+#    #+#             */
/*   Updated: 2024/01/30 19:19:37 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	*map_contens_checker(t_map *map)
{
	ft_printf("\nEntering MAP_ITEMS_CHECKER:\n");
	if (has_specific_char(map, "P", 1) == true)
		ft_printf("Player = true\n");
	if (has_specific_char(map, "C", NULL) == true)
		ft_printf("Collectable = true\n");
	if (has_specific_char(map, "E", 1) == true)
		ft_printf("Exit = true\n");
	return (false);
}

bool	*has_specific_char(t_map *map, char *tofind, int limiter)
{
	char	*line;
	int32_t	found;
	int32_t	x;

	x = 0;
	while (x <= map->height - 1)
	{
		line = ft_strnstr(map->matrix[x], tofind, map->width - 1);
		while (!line)
		{
			x++;
			line = ft_strnstr(map->matrix[x], tofind, map->width - 1);
			if (x == map->height - 1)
			{
				ft_putendl_fd("\nError\nPlayer not found!\n", STDOUT_FILENO);
				return (false);
			}
		}
		found++;
		break ;
	}
	/* TODO */
	ft_printf("\nTODO = ADD LIMITER on has_specific_char\n");
	if (found > limiter)
	{
		ft_putendl_fd("\nError\nToo much specific items on map!\n", STDOUT_FILENO);
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
