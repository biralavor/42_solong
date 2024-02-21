/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_builder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:50:18 by umeneses          #+#    #+#             */
/*   Updated: 2024/02/21 16:35:13 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parse_imgtomap(t_map *map, char toparse, mlx_t *mlx, mlx_image_t *img)
{
	int32_t	x;
	int32_t	y;

	y = -1;
	while ((++y <= map->height - 1) && map->matrix)
	{
		x = -1;
		while (++x <= map->width)
		{
			if (toparse == map->matrix[y][x])
			{
				ft_printf("matrix[%d][%d] = %c\n", y, x, map->matrix[y][x]);
				mlx_resize_image(img, PIXEL_SIZE, PIXEL_SIZE) == true;
				mlx_image_to_window(mlx, img, y * PIXEL_SIZE, x * PIXEL_SIZE);
			}
		}
	}
}
