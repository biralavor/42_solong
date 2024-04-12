/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_builder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:50:18 by umeneses          #+#    #+#             */
/*   Updated: 2024/04/09 15:08:46 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parse_imgtomap(t_map *map, char toparse, mlx_t *mlx, mlx_image_t *img)
{
	map->read_y = -1;
	while ((++map->read_y <= map->height - 1) && map->matrix)
	{
		map->read_x = -1;
		while (++map->read_x <= map->width)
		{
			if (toparse == map->matrix[map->read_y][map->read_x])
			{
				if (mlx_resize_image(img, PIXEL_SIZE, PIXEL_SIZE))
					mlx_image_to_window(mlx, img, (map->read_x * PIXEL_SIZE), \
									(map->read_y * PIXEL_SIZE));
			}
		}
	}
}

void	parse_backtomap(t_map *map, char toparse, mlx_t *mlx, mlx_image_t *img)
{
	map->read_y = -1;
	if (toparse == 'b')
	{
		while (++map->read_y < HEIGHT)
		{
			map->read_x = -1;
			while (++map->read_x < WIDTH)
			{
				if (mlx_resize_image(img, PIXEL_SIZE, PIXEL_SIZE))
					mlx_image_to_window(mlx, img, (map->read_x * PIXEL_SIZE), \
										(map->read_y * PIXEL_SIZE));
			}
		}
	}
}
