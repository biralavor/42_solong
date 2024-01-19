/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_builder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:50:18 by umeneses          #+#    #+#             */
/*   Updated: 2024/01/19 16:35:13 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**map_builder(int32_t fd, t_game *game)
{
	game->selected_map = map_reader(fd);
	if (!game->selected_map)
	{
		free(game);
		return (1);
	}
	game->map = ft_split((const char *)game->selected_map, '\n');
	return (&game->selected_map);
}
