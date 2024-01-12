/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading_images.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:35:34 by umeneses          #+#    #+#             */
/*   Updated: 2024/01/12 17:52:01 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void load_texture(t_game *game)
{
	// game->ship = mlx_load_png(SPACESHIP);
	game->background = mlx_load_png(SPACEFIELD);
	game->enemy = mlx_load_png(DEATH);
	game->border = mlx_load_png(BOUNDARY);
	game->astro = mlx_load_png(ASTRONAUT);
	game->earth = mlx_load_png(EARTH);
	if (!game->background || !game->enemy || !game->border || !game->astro || !game->earth)
		puts(mlx_strerror(mlx_errno));
	// Convert texture to a displayable image
	// game->ship_img = mlx_texture_to_image(game->mlx, game->ship);
	game->back_img = mlx_texture_to_image(game->mlx, game->background);
	game->enemy_img = mlx_texture_to_image(game->mlx, game->enemy);
	game->border_img = mlx_texture_to_image(game->mlx, game->border);
	game->astro_img = mlx_texture_to_image(game->mlx, game->astro);
	game->earth_img = mlx_texture_to_image(game->mlx, game->earth);
	if (!game->back_img || (mlx_image_to_window(game->mlx, game->back_img, 200, 200) < 0) || \
		!game->enemy_img || (mlx_image_to_window(game->mlx, game->enemy_img, 300, 400) < 0) || \
		!game->border_img || (mlx_image_to_window(game->mlx, game->border_img, 0, 300) < 0) || \
		!game->astro_img || (mlx_image_to_window(game->mlx, game->astro_img, 100, 350) < 0) || \
		!game->earth_img || (mlx_image_to_window(game->mlx, game->earth_img, 250, 450) < 0))
		{
			// mlx_delete_image(game->mlx, game->play_img);
			// mlx_delete_image(game->mlx, game->cvs_img);
			// mlx_delete_image(game->mlx, game->ship_img);
			// mlx_delete_image(game->mlx, game->ship_img);
			// mlx_delete_texture(game->ship);
			// mlx_delete_image(game->mlx, game->back_img);
			// mlx_delete_texture(game->background);
			// mlx_delete_image(game->mlx, game->enemy_img);
			// mlx_delete_texture(game->enemy);
			// mlx_delete_image(game->mlx, game->border_img);
			// mlx_delete_texture(game->border);
			// mlx_delete_image(game->mlx, game->astro_img);
			// mlx_delete_texture(game->astro);
			// mlx_delete_image(game->mlx, game->earth_img);
			// mlx_delete_texture(game->earth);
			free(game);
			puts(mlx_strerror(mlx_errno));
		}
}
