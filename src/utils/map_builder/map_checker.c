/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:50:18 by umeneses          #+#    #+#             */
/*   Updated: 2024/01/26 16:52:27 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	map_check(char **argv, t_map *map)
{
	map->fd = open(argv[1], O_RDONLY);
	if (map_size_check(map) == true)
	{
		// map->fd = open(argv[1], O_RDONLY);
		// map->line = map_reader(map->fd);
		// close(map->fd);
		ft_printf("map.line after map_read = %s\n", map->line);
		ft_printf("map->line strlen = %d\n", ft_strlen(map->line));
		ft_printf("map->size = %d\n", map->size);
		ft_printf("map->width = %d\n", map->width);
		ft_printf("map->height = %d\n", map->height);
		ft_printf("\nrunning matrix now->->->\n");
		map->matrix = ft_split(map->line, '\n');
		if (map->matrix == (void *)0)
		{
			err_msg_free(3, "\nMap allocation error.\n", 0, map);
			return (false);
		}
		return (true);
	}
	return (false);
}


// while (map.line)
// {
// 	if (has_wall(map.line) == true)
// 	{
// 		ft_printf(COLOR_CYAN);
// 		ft_printf("wall found!!\n");
// 		ft_printf(COLOR_RESET);
// 	}
// 	else
// 	{
// 		ft_printf("map doesn't have player!!\n");
// 		break ;
// 	}
// 	ft_printf("\nChecking HAS PLAYER... = ");
// 	if (has_player(map.line) == true)
// 	{
// 		ft_printf(COLOR_CYAN);
// 		ft_printf("player found!!\n");
// 		ft_printf(COLOR_RESET);
// 	}
// 		else
// 			ft_printf("map doesn't have player!!\n");
// }