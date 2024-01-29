/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_builder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:50:18 by umeneses          #+#    #+#             */
/*   Updated: 2024/01/29 14:38:43 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	*map_build_matrix(char **argv, t_map *map)
{
	map->fd = open(argv[1], O_RDONLY);
	ft_printf("map->fd = %d\n", map->fd);
	ft_printf("inside matrix map.line = %s\n", map->line);
	ft_printf("inside matrix map->size = %d\n", map->size);
	ft_printf("inside matrix map->width = %d\n", map->width);
	ft_printf("inside matrix map->height = %d\n", map->height);
	ft_printf("\nrunning matrix now->->->\n");
	map->matrix = ft_split(ft_get_next_line(map->fd), '\n');
	if (map->matrix == (void *)0)
	{
		ft_putendl_fd("\nMap allocation error.\n", STDOUT_FILENO);
		return (false);
	}
	return (true);
}


// while (map.line)
// {
// 	if (has_wall(map.line) == true)
// 	{
// 		ft_printf("wall found!!\n");
// 	}
// 	else
// 	{
// 		ft_printf("map doesn't have player!!\n");
// 		break ;
// 	}
// 	ft_printf("\nChecking HAS PLAYER... = ");
// 	if (has_player(map.line) == true)
// 	{
// 		ft_printf("player found!!\n");
// 	}
// 		else
// 			ft_printf("map doesn't have player!!\n");
// }