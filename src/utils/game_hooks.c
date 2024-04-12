/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:52:24 by umeneses          #+#    #+#             */
/*   Updated: 2024/04/12 13:08:32 by umeneses         ###   ########.fr       */
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
		ft_printf("\n\nLet's Go!\n\nFuel = %i",
			++game->userdata->totalmoves);
		coins_counter(game);
	}
	if (ft_strncmp(key, "DOWN", 5) == 0)
	{
		ft_printf("\n\nOh, Gosh! Pulling back now!\n\nFuel = %i",
			++game->userdata->totalmoves);
		coins_counter(game);
	}
	if (ft_strncmp(key, "LEFT", 5) == 0)
	{
		ft_printf("\n\nDodging left!\n\nFuel = %i",
			++game->userdata->totalmoves);
		coins_counter(game);
	}
	if (ft_strncmp(key, "RIGHT", 6) == 0)
	{
		ft_printf("\n\nSliding right!\n\nFuel = %i",
			++game->userdata->totalmoves);
		coins_counter(game);
	}
}

void	coins_counter(t_game *game)
{
	ft_printf("  && Lost Astronauts = %i/%i",
		game->userdata->totalcoins, game->map->coin_index);
}
