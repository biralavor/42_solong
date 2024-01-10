/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:47:07 by umeneses          #+#    #+#             */
/*   Updated: 2024/01/10 16:47:06 by umeneses         ###   ########.fr       */
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
	for (int32_t i = 0; i < play_img->width; ++i)
	{
		for (int32_t y = 0; y < play_img->height; ++y)
		{
			uint32_t color = ft_pixel(
				rand() % 0xFF, // R
				rand() % 0xFF, // G
				rand() % 0xFF, // B
				rand() % 0xFF  // A
			);
			mlx_put_pixel(play_img, i, y, color);
		}
	}
}

void keyb_wasd_arrow(void* param)
{
	mlx_t*		mlx = param;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
			play_img->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
			play_img->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		play_img->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		play_img->instances[0].x += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_W))
			play_img->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_S))
			play_img->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_A))
		play_img->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_D))
		play_img->instances[0].x += 5;
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
		printf("\nDodging left! \
			\nTotal Moves = %i", ++moves.totalmoves);
	if ((keydata.key == MLX_KEY_D | keydata.key == MLX_KEY_RIGHT) \
		&& keydata.action == MLX_PRESS)
		printf("\nSliding right! \
			\nTotal Moves = %i", ++moves.totalmoves);
	// mlx_put_string(data->mlx, data->combstr[str_img], x, 0)
}

void ui_stats_canvas(mlx_t* mlx, mlx_image_t* cvs_img)
{
	// set new image	
	cvs_img = mlx_new_image(mlx, (WIDTH % 10 * HEIGHT), (HEIGHT % 10) * 10);
	// set color foreground image
	ft_memset(cvs_img->pixels, 150, cvs_img->width * cvs_img->height * BPP);
	mlx_image_to_window(mlx, cvs_img, 0, 0);
}

void load_texture(mlx_t* mlx, mlx_texture_t* ship, mlx_image_t* ship_img)
{
	ship = mlx_load_png(SPACESHIP);
	background = mlx_load_png(SPACEFIELD);
	enemy = mlx_load_png(DEATH);
	border = mlx_load_png(BOUNDARY);
	astro = mlx_load_png(ASTRONAUT);
	earth = mlx_load_png(EARTH);
	if (!ship || !background || !enemy || !border || !astro || !earth)
		puts(mlx_strerror(mlx_errno));
	// Convert texture to a displayable image
	ship_img = mlx_texture_to_image(mlx, ship);
	back_img = mlx_texture_to_image(mlx, background);
	enemy_img = mlx_texture_to_image(mlx, enemy);
	border_img = mlx_texture_to_image(mlx, border);
	astro_img = mlx_texture_to_image(mlx, astro);
	earth_img = mlx_texture_to_image(mlx, earth);
	if (!ship_img || (mlx_image_to_window(mlx, ship_img, 400, 100) < 0) || \
		!back_img || (mlx_image_to_window(mlx, back_img, 200, 200) < 0) || \
		!enemy_img || (mlx_image_to_window(mlx, enemy_img, 300, 400) < 0) || \
		!border_img || (mlx_image_to_window(mlx, border_img, 0, 300) < 0) || \
		!astro_img || (mlx_image_to_window(mlx, astro_img, 100, 350) < 0) || \
		!earth_img || (mlx_image_to_window(mlx, earth_img, 250, 450) < 0))
		puts(mlx_strerror(mlx_errno));
}

int32_t main(int32_t argc, const char* argv[])
{
	mlx_t*	mlx;

	// Gotta error check this stuff
	if (!(mlx = mlx_init(WIDTH, HEIGHT, "42_Astronauts_So_Long_Game", true)))
		error();
	if (!(play_img = mlx_new_image(mlx, 4, 4)))
	{
		mlx_close_window(mlx);
		error();
	}
	if (mlx_image_to_window(mlx, play_img, 0, 0) == -1)
	{
		mlx_close_window(mlx);
		error();
	}
	ui_stats_canvas(mlx, cvs_img);
	load_texture(mlx, ship, ship_img);
	mlx_loop_hook(mlx, play_random_color, mlx);
	mlx_loop_hook(mlx, keyb_wasd_arrow, mlx);
	mlx_key_hook(mlx, &movecounter, NULL);
	mlx_loop(mlx);
	mlx_close_window(mlx);
	mlx_delete_image(mlx, play_img);
	mlx_delete_image(mlx, cvs_img);
	mlx_delete_image(mlx, ship_img);
	mlx_delete_texture(ship);
	mlx_delete_image(mlx, back_img);
	mlx_delete_texture(background);
	mlx_delete_image(mlx, enemy_img);
	mlx_delete_texture(enemy);
	mlx_delete_image(mlx, border_img);
	mlx_delete_texture(border);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}

// mlx_scroll_hook(mlx, &my_scrollhook, NULL);

// void my_scrollhook(double xdelta, double ydelta, void* param)
// {
// 	mlx_key_data_t keydata;

// 	// Simple up or down detection.
// 	if (ydelta > 0)
// 		puts("Up!");
// 	else if (ydelta < 0)
// 		puts("Down!");
// 	// Can also detect a mousewheel that go along the X (e.g: MX Master 3)
// 	if (keydata.key == MLX_KEY_LEFT_SHIFT && ydelta > 0)
// 		puts("Sliiiide to the left!");
// 	else if (keydata.key == MLX_KEY_LEFT_SHIFT && ydelta < 0)
// 		puts("Sliiiide to the right!");
// }