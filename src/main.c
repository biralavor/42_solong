/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:47:07 by umeneses          #+#    #+#             */
/*   Updated: 2024/01/11 11:18:08 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static void error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 24 | b << 16 | a);
}

void play_random_color(void* param)
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

void keyb_wasd_arrow(void* param)
{
	t_game*	game;
	
	game = param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, MLX_KEY_UP))
			game->play_img->instances[0].y -= 5;
	if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
			game->play_img->instances[0].y += 5;
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		game->play_img->instances[0].x -= 5;
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		game->play_img->instances[0].x += 5;
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
			game->play_img->instances[0].y -= 5;
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
			game->play_img->instances[0].y += 5;
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		game->play_img->instances[0].x -= 5;
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		game->play_img->instances[0].x += 5;
}

void movecounter(mlx_key_data_t keydata, void* param)
{
	static t_game	moves;

	if ((keydata.key == MLX_KEY_W | keydata.key == MLX_KEY_UP) \
		&& keydata.action == MLX_PRESS)
			printf("\nLet's Go!!! \
			\nTotal Moves = %i", ++moves.totalmoves);
	if ((keydata.key == MLX_KEY_S | keydata.key == MLX_KEY_DOWN) \
		&& keydata.action == MLX_PRESS)
		printf("\nOh, Gosh! Pulling back now! \
			\nTotal Moves = %i", ++moves.totalmoves);
	if ((keydata.key == MLX_KEY_A | keydata.key == MLX_KEY_LEFT) \
		&& keydata.action == MLX_PRESS)
		printf("\nDodging game_tleft! \
			\nTotal Moves = %i", ++moves.totalmoves);
	if ((keydata.key == MLX_KEY_D | keydata.key == MLX_KEY_RIGHT) \
		&& keydata.action == MLX_PRESS)
		printf("\nSliding right! \
			\nTotal Moves = %i", ++moves.totalmoves);
	// mlx_put_string(data->mlx, data->combstr[str_img], x, 0)
}

// void ui_stats_canvas(t_game *game)
// {
// 	// set new image	
// 	game->cvs_img = mlx_new_image(game->mlx, (WIDTH % 10 * HEIGHT), (HEIGHT % 10) * 10);
// 	// set color foreground image
// 	ft_memset(game->cvs_img->pixels, 150, game->cvs_img->width * game->cvs_img->height * BPP);
// 	mlx_image_to_window(game->mlx, game->cvs_img, 0, 0);
// }

// void load_texture(mlx_t* mlx, mlx_texture_t* ship, mlx_image_t* ship_img)
// {
// 	ship = mlx_load_png(SPACESHIP);
// 	background = mlx_load_png(SPACEFIELD);
// 	enemy = mlx_load_png(DEATH);
// 	border = mlx_load_png(BOUNDARY);
// 	astro = mlx_load_png(ASTRONAUT);
// 	earth = mlx_load_png(EARTH);
// 	if (!ship || !background || !enemy || !border || !astro || !earth)
// 		puts(mlx_strerror(mlx_errno));
// 	// Convert texture to a displayable image
// 	ship_img = mlx_texture_to_image(mlx, ship);
// 	back_img = mlx_texture_to_image(mlx, background);
// 	enemy_img = mlx_texture_to_image(mlx, enemy);
// 	border_img = mlx_texture_to_image(mlx, border);
// 	astro_img = mlx_texture_to_image(mlx, astro);
// 	earth_img = mlx_texture_to_image(mlx, earth);
// 	if (!ship_img || (mlx_image_to_window(mlx, ship_img, 400, 100) < 0) || \
// 		!back_img || (mlx_image_to_window(mlx, back_img, 200, 200) < 0) || \
// 		!enemy_img || (mlx_image_to_window(mlx, enemy_img, 300, 400) < 0) || \
// 		!border_img || (mlx_image_to_window(mlx, border_img, 0, 300) < 0) || \
// 		!astro_img || (mlx_image_to_window(mlx, astro_img, 100, 350) < 0) || \
// 		!earth_img || (mlx_image_to_window(mlx, earth_img, 250, 450) < 0))
// 		puts(mlx_strerror(mlx_errno));
// }

int32_t main(int32_t argc, const char* argv[])
{
	t_game	*game;

	// Gotta error check this stuff
	if (!(game->mlx = mlx_init(WIDTH, HEIGHT, "42_Astronauts_So_Long_Game", true)))
		error();
	if (!(game->play_img = mlx_new_image(game->mlx, 4, 4)))
	{
		mlx_close_window(game->mlx);
		error();
	}
	if (mlx_image_to_window(game->mlx, game->play_img, 0, 0) == -1)
	{
		mlx_close_window(game->mlx);
		error();
	}
	// ui_stats_canvas(game);
	// load_texture(game);
	// mlx_loop_hook(game->mlx, play_random_color, game->mlx);
	mlx_loop_hook(game->mlx, keyb_wasd_arrow, game->mlx);
	mlx_key_hook(game->mlx, &movecounter, NULL);
	mlx_loop(game->mlx);
	mlx_close_window(game->mlx);
	// mlx_delete_image(game->mlx, game->play_img);
	// mlx_delete_image(game->mlx, game->cvs_img);
	// mlx_delete_image(game->mlx, game->ship_img);
	// mlx_delete_texture(game->ship);
	// mlx_delete_image(game->mlx, game->back_img);
	// mlx_delete_texture(game->background);
	// mlx_delete_image(game->mlx, game->enemy_img);
	// mlx_delete_texture(game->enemy);
	// mlx_delete_image(game->mlx, game->border_img);
	// mlx_delete_texture(game->border);
	mlx_terminate(game->mlx);
	return (EXIT_SUCCESS);
}
