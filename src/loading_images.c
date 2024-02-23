/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading_images.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:35:34 by umeneses          #+#    #+#             */
/*   Updated: 2024/02/23 17:45:16 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// bool	loading_png(const char *imagepath, mlx_texture_t *texture)
// {
// 	texture = mlx_load_png(imagepath);
// 	if (!texture)
// 	{
// 		mlx_delete_texture(texture);
// 		return(false);
// 	}
// 	return (true);
// }

// bool	preparing_image(mlx_t *mlx, mlx_texture_t *texture, mlx_image_t *image)
// {
// 	image = mlx_texture_to_image(&mlx, &texture);
// 	if (!image)
// 	{
// 		mlx_delete_image(mlx, image);
// 		return(false);
// 	}
// 	return (true);
// }

// bool	are_sprites_ready(const char *imagepath, mlx_texture_t *texture, mlx_image_t *image, mlx_t *mlx)
// {
// 	if (loading_png(imagepath, texture) == true)
// 	{
// 		preparing_image(mlx, texture, image);
// 		return (true);
// 	}
// 	return (false);
// }

void	displaying_sprites(mlx_t *mlx, t_sprite *sprites, t_map *map)
{
	t_sprite *sprites_temp;
	
	sprites_temp = (t_sprite *)ft_calloc(1, sizeof(t_sprite));
	if (!sprites_temp)
		free (sprites_temp);
	sprites = sprites_temp;
	
	// if (loading_png(SPACEFIELD, sprites->back_tt) == true)
	// {
	// 	preparing_image(mlx, sprites->back_tt, sprites->back);
	// 	parse_imgtomap(map, '1', mlx, sprites->back);
	// }

	sprites->back_tt = mlx_load_png(SPACEFIELD);
	sprites->back = mlx_texture_to_image(mlx, sprites->back_tt);
	parse_imgtomap(map, '1', mlx, sprites->back);

	// sprites->border_tt = mlx_load_png(BOUNDARY);
	// sprites->border = mlx_texture_to_image(mlx, sprites->border_tt);
	// parse_imgtomap(map, '1', mlx, sprites->border);

	// sprites->back_tt = mlx_load_png(SPACEFIELD);
	// sprites->back = mlx_texture_to_image(mlx, sprites->back_tt);
	// parse_imgtomap(map, '0', mlx, sprites->back);

	// sprites->player_tt = mlx_load_png(SPACESHIP);
	// sprites->player = mlx_texture_to_image(mlx, sprites->player_tt);
	// parse_imgtomap(map, 'P', mlx, sprites->player);

	// sprites->coin_tt = mlx_load_png(ASTRONAUT);
	// sprites->coin = mlx_texture_to_image(mlx, sprites->coin_tt);
	// parse_imgtomap(map, 'C', mlx, sprites->coin);

	// sprites->exit_tt = mlx_load_png(EARTH);
	// sprites->exit = mlx_texture_to_image(mlx, sprites->exit_tt);
	// parse_imgtomap(map, 'E', mlx, sprites->exit);

	free(sprites_temp);
}
