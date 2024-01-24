/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_builder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:50:18 by umeneses          #+#    #+#             */
/*   Updated: 2024/01/24 14:13:21 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*map_builder(char **argv, t_map map)
{
	char	*gnl_temp;

	gnl_temp = "";
	map.fd = open(argv[1], O_RDONLY);
	map.index = 0;
	ft_printf("\nEntering into MAP BUILDER\n");
	while (gnl_temp)
	{
		ft_printf(COLOR_CYAN);
		ft_printf("GNL MAP BUILDER %i = ", map.index);
		gnl_temp = ft_get_next_line(map.fd);
		ft_printf("%s", gnl_temp);
		free(gnl_temp);
		map.index++;
	}
	ft_get_next_line(map.fd);
	// game->selected_map = map_reader(game->fd);
	ft_printf("\ngame map = ft_split init\n");
	// game->map = ft_split((const char *)game->selected_map, '\n');
	return (0);
}
