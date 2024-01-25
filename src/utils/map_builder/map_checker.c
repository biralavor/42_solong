/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:50:18 by umeneses          #+#    #+#             */
/*   Updated: 2024/01/25 16:54:23 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	map_check(char **argv, t_map map)
{
	map.fd = open(argv[1], O_RDONLY);
	if (map_size_check(map) == true)
	{
		map.fd = open(argv[1], O_RDONLY);
		map.width = 0;
		while (map.line)
		{
			map.line = ft_get_next_line(map.fd);
			if (map.line == (void *)0)
				break ;
			if (map.width == 0)
				map.width = (ft_strlen(map.line) - 1);
			map.height++;
			ft_printf("map.line = %s\n", map.line);
			ft_printf("map.width = %d\n", map.width);
			ft_printf("map.height = %d\n", map.height);
			// if (has_wall(map.line) == true)
			// {
			// 	ft_printf(COLOR_CYAN);
			// 	ft_printf("wall found!!\n");
			// 	ft_printf(COLOR_RESET);
			// }
			// else
			// 	ft_printf("map doesn't have player!!\n");
			// ft_printf("\nChecking HAS PLAYER... = ");
		// 	if (has_player(map.line) == true)
		// 	{
		// 		ft_printf(COLOR_CYAN);
		// 		ft_printf("player found!!\n");
		// 		ft_printf(COLOR_RESET);
		// 	}
		// 	else
		// 		ft_printf("map doesn't have player!!\n");
		}
		// game->selected_map = map_reader(game->fd);
		// ft_printf("\ngame map = ft_split init\n");
		// game->map = ft_split((const char *)game->selected_map, '\n');
		return (true);
	}
	close(map.fd);
	return (false);
}


