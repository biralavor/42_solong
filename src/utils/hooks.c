/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:52:24 by umeneses          #+#    #+#             */
/*   Updated: 2024/04/09 16:23:38 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	keyb_wasd_arrow(mlx_key_data_t key, t_game *game)
{
	game->userdata->future_y_pos = game->userdata->y_pos;
	game->userdata->future_x_pos = game->userdata->x_pos;
	if (!is_wall(key, game))
	{
		if ((key.key == MLX_KEY_UP) || (key.key == MLX_KEY_W))
		{
			game->sprites->player->instances->y -= PIXEL_SIZE;
			user_counter("UP", game);
		}
		if ((key.key == MLX_KEY_DOWN) || (key.key == MLX_KEY_S))
		{
			game->sprites->player->instances->y += PIXEL_SIZE;
			user_counter("DOWN", game);
		}
		if ((key.key == MLX_KEY_LEFT) || (key.key == MLX_KEY_A))
		{
			game->sprites->player->instances->x -= PIXEL_SIZE;
			user_counter("LEFT", game);
		}
		if ((key.key == MLX_KEY_RIGHT) || (key.key == MLX_KEY_D))
		{
			game->sprites->player->instances->x += PIXEL_SIZE;
			user_counter("RIGHT", game);
		}
	}
}

void	user_counter(char *key, t_game *game)
{
	if (ft_strncmp(key, "UP", 3) == 0)
	{
		ft_printf("\nLet's Go!\nUsed Gas = %i",
			++game->userdata->totalmoves);
		coins_counter(game);
	}
	if (ft_strncmp(key, "DOWN", 5) == 0)
	{
		ft_printf("\nOh, Gosh! Pulling back now!\nUsed Gas = %i",
			++game->userdata->totalmoves);
		coins_counter(game);
	}
	if (ft_strncmp(key, "LEFT", 5) == 0)
	{
		ft_printf("\nDodging left!\nUsed Gas = %i",
			++game->userdata->totalmoves);
		coins_counter(game);
	}
	if (ft_strncmp(key, "RIGHT", 6) == 0)
	{
		ft_printf("\nSliding right!\nUsed Gas = %i",
			++game->userdata->totalmoves);
		coins_counter(game);
	}
}

void	coins_counter(t_game *game)
{
	ft_printf("  && Lost Astronauts = %i/%i",
		game->userdata->totalcoins, game->map->coin_index);
}

/*
void ui_stats_canvas(t_game *game)
{
	game->cvs_img = mlx_new_image(game->mlx, (WIDTH % 10 * HEIGHT), (HEIGHT % 10) * 10);
	// set color foreground image
	ft_memset(game->cvs_img->pixels, 140, game->cvs_img->width * game->cvs_img->height * BPP);
	mlx_image_to_window(game->mlx, game->cvs_img, 0, 0);
}

t_game *structures_init(void)
{
	static t_game game;
	return (&game);
}

// PUT PIXEL RANDOM COLOR
int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 24 | b << 16 | a);
}

void play_random_color(void *param)
{
	t_game	*game;

	game = param;
	for (int32_t i = 0; i < game->play_img->width; ++i)
	{
		for (int32_t y = 0; y < game->play_img->height; ++y)
		{
			uint32_t color = ft_pixel(
			rand() % 0xFF, // R
			rand() % 0xFF, // G
			rand() % 0xFF, // B
			rand() % 0xFF  // A
			);
			mlx_put_pixel(game->play_img, i, y, color);
		}
	}
}
// na MAIN:
// ui_stats_canvas(game);
// mlx_loop_hook(game->mlx, play_random_color, game->mlx);
*/