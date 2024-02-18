/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_builder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bira <bira@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:50:18 by umeneses          #+#    #+#             */
/*   Updated: 2024/02/18 16:06:26 by bira             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* TODO: parse map information to Graphics*/

bool	xx_xxx(t_map *map, char tofind, int limiter)
{
	int32_t	found;
	int32_t	x;
	int32_t	y;

	found = 0;
	y = -1;
	while ((++y <= map->height - 1) && map->matrix)
	{
		x = -1;
		while (++x <= map->width - 1)
		{
			if (tofind == map->matrix[y][x])
				found++;
		}
		if ((y == map->height - 1) && (x == map->width))
			break ;
	}


	if ((found > limiter) || (tofind == 'C' && found == 0))
	{
		ft_putendl_fd("\nError\nXXXXXX.\n", \
						STDOUT_FILENO);
		return (false);
	}
	map->coin_index = found;
	return (true);
}
