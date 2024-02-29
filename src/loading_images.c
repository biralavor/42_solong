/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading_images.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:35:34 by umeneses          #+#    #+#             */
/*   Updated: 2024/02/29 16:53:31 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	loading_png(const char *imagepath, mlx_texture_t **texture)
{
	*texture = mlx_load_png(imagepath);
	if (!*texture)
	{
		mlx_delete_texture(*texture);
		return(false);
	}
	return (true);
}

bool	preparing_image(mlx_t *mlx, mlx_texture_t **texture, mlx_image_t **image)
{
	*image = mlx_texture_to_image(mlx, *texture);
	if (!*image)
	{
		mlx_delete_image(mlx, *image);
		return(false);
	}
	return (true);
}

void	displaying_sprites(mlx_t *mlx, t_sprite *sprites, t_map *map)
{
	t_sprite *sprites_temp;

	sprites_temp = (t_sprite *)ft_calloc(1, sizeof(t_sprite));
	if (!sprites_temp)
		free (sprites_temp);
	sprites = sprites_temp;
	if ((loading_png(SPACEFIELD, &sprites->back_tt) == true) && \
		(preparing_image(mlx, &sprites->back_tt, &sprites->back) == true))
		parse_imgtomap(map, 'b', mlx, &sprites->back);
	if ((loading_png(BOUNDARY, &sprites->border_tt) == true) && \
		(preparing_image(mlx, &sprites->border_tt, &sprites->border) == true))
		parse_imgtomap(map, '1', mlx, &sprites->border);
	if ((loading_png(SPACESHIP, &sprites->player_tt) == true) && \
		(preparing_image(mlx, &sprites->player_tt, &sprites->player) == true))
		parse_imgtomap(map, 'P', mlx, &sprites->player);
	if ((loading_png(ASTRONAUT, &sprites->coin_tt) == true) && \
		(preparing_image(mlx, &sprites->coin_tt, &sprites->coin) == true))
		parse_imgtomap(map, 'C', mlx, &sprites->coin);
	if ((loading_png(EARTH, &sprites->exit_tt) == true) && \
		(preparing_image(mlx, &sprites->exit_tt, &sprites->exit) == true))
		parse_imgtomap(map, 'E', mlx, &sprites->exit);
	free(sprites_temp);
}
