/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:52:24 by umeneses          #+#    #+#             */
/*   Updated: 2024/02/21 16:51:38 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void keyb_wasd_arrow(t_game *game, void* param)
{
	game = param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, (MLX_KEY_UP || MLX_KEY_W)))
			game->play_img->instances[0].y -= 5;
	if (mlx_is_key_down(game->mlx, (MLX_KEY_DOWN || MLX_KEY_S)))
			game->play_img->instances[0].y += 5;
	if (mlx_is_key_down(game->mlx, (MLX_KEY_LEFT || MLX_KEY_A)))
		game->play_img->instances[0].x -= 5;
	if (mlx_is_key_down(game->mlx, (MLX_KEY_RIGHT || MLX_KEY_D)))
		game->play_img->instances[0].x += 5;
}

// void movecounter(mlx_key_data_t keydata, void* param)
// {
// 	static t_game	game;

// 	if ((keydata.key == MLX_KEY_W | keydata.key == MLX_KEY_UP) \
// 		&& keydata.action == MLX_PRESS)
// 			printf("\nLet's Go!!! \
// 			\nTotal Moves = %i", ++game.totalmoves);
// 	if ((keydata.key == MLX_KEY_S | keydata.key == MLX_KEY_DOWN) \
// 		&& keydata.action == MLX_PRESS)
// 		printf("\nOh, Gosh! Pulling back now! \
// 			\nTotal Moves = %i", ++game.totalmoves);
// 	if ((keydata.key == MLX_KEY_A | keydata.key == MLX_KEY_LEFT) \
// 		&& keydata.action == MLX_PRESS)
// 		printf("\nDodging left! \
// 			\nTotal Moves = %i", ++game.totalmoves);
// 	if ((keydata.key == MLX_KEY_D | keydata.key == MLX_KEY_RIGHT) \
// 		&& keydata.action == MLX_PRESS)
// 		printf("\nSliding right! \
// 			\nTotal Moves = %i", ++game.totalmoves);
// 	// mlx_put_string(data->mlx, data->combstr[str_img], x, 0)
// }

// void ui_stats_canvas(t_game *game)
// {
// 	game->cvs_img = mlx_new_image(game->mlx, (WIDTH % 10 * HEIGHT), (HEIGHT % 10) * 10);
// 	// set color foreground image
// 	ft_memset(game->cvs_img->pixels, 140, game->cvs_img->width * game->cvs_img->height * BPP);
// 	mlx_image_to_window(game->mlx, game->cvs_img, 0, 0);
// }

// t_game *structures_init(void)
// {
// 	static t_game game;
// 	return (&game);
// }


/* PUT PIXEL RANDOM COLOR */
// int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
// {
//     return (r << 24 | g << 24 | b << 16 | a);
// }

// void play_random_color(void *param)
// {
// 	t_game	*game;

// 	game = param;
// 	for (int32_t i = 0; i < game->play_img->width; ++i)
// 	{
// 		for (int32_t y = 0; y < game->play_img->height; ++y)
// 		{
// 			uint32_t color = ft_pixel(
// 				rand() % 0xFF, // R
// 				rand() % 0xFF, // G
// 				rand() % 0xFF, // B
// 				rand() % 0xFF  // A
// 			);
// 			mlx_put_pixel(game->pl#include "so_long.h"ay_img, i, y, color);
// 		}
// 	}
// }