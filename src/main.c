/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:47:07 by umeneses          #+#    #+#             */
/*   Updated: 2024/01/03 15:51:49 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/codam/include/MLX42/MLX42.h"
#include "../headers/so_long.h"

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 24 | b << 16 | a);
}

void ft_randomize(void* param)
{
	for (int32_t i = 0; i < image->width; ++i)
	{
		for (int32_t y = 0; y < image->height; ++y)
		{
			uint32_t color = ft_pixel(
				rand() % 0xFF, // R
				rand() % 0xFF, // G
				rand() % 0xFF, // B
				rand() % 0xFF  // A
			);
			mlx_put_pixel(image, i, y, color);
		}
	}
}

void ft_hook(void* param)
{
	mlx_t*		mlx = param;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
			image->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
			image->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		image->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		image->instances[0].x += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_W))
			image->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_S))
			image->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_A))
		image->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_D))
		image->instances[0].x += 5;
}

void my_keyhook(mlx_key_data_t keydata, void* param)
{
	static t_player	moves;

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
}

void my_scrollhook(double xdelta, double ydelta, void* param)
{
	mlx_key_data_t keydata;

	// Simple up or down detection.
	if (ydelta > 0)
		puts("Up!");
	else if (ydelta < 0)
		puts("Down!");
	// Can also detect a mousewheel that go along the X (e.g: MX Master 3)
	if (keydata.key == MLX_KEY_LEFT_SHIFT && ydelta > 0)
		puts("Sliiiide to the left!");
	else if (keydata.key == MLX_KEY_LEFT_SHIFT && ydelta < 0)
		puts("Sliiiide to the right!");
}

int32_t main(int32_t argc, const char* argv[])
{
	mlx_t*	mlx;

	// Gotta error check this stuff
	if (!(mlx = mlx_init(WIDTH, HEIGHT, "42_Astronauts_Sooo_Long_Game", true)))
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (!(image = mlx_new_image(mlx, 4, 4)))
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	
	mlx_image_to_window(mlx, image, 0, 0);
	mlx_put_pixel(image, 10, 10, 0xFF0000FF);
	mlx_scroll_hook(mlx, &my_scrollhook, NULL);
	mlx_loop_hook(mlx, ft_randomize, mlx);
	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_key_hook(mlx, &my_keyhook, NULL);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
