/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_builder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:50:18 by umeneses          #+#    #+#             */
/*   Updated: 2024/01/24 16:27:35 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	map_builder(char **argv, t_map map)
{

	ft_printf("\nft MAP BUILDER loading...\n");
	ft_printf("\nargv = %s\n", argv[1]);
	map.fd = open(argv[1], O_RDONLY);
	ft_printf("\nft MAP SIZE CHECK loading...\n");
	map.index = 0;
	map_size_check(map);

	// game->selected_map = map_reader(game->fd);
	ft_printf("\ngame map = ft_split init\n");
	// game->map = ft_split((const char *)game->selected_map, '\n');
	return (0);
}


