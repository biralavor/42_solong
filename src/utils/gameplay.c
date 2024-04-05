/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 10:08:04 by umeneses          #+#    #+#             */
/*   Updated: 2024/04/05 10:57:21 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	frame_update(mlx_key_data_t key, t_game *game)
{
	show_exit(game);

	ft_collectable(game);
	if (key.action == MLX_PRESS)
	{
		if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		{
			write(1, "\n\nN00OOOOOOO00!\n\n", 18);
			write(1, "\\¯\\_(ツ)_/¯/\n\n", 18);
			mlx_close_window(game->mlx);
			return ;
		}
		keyb_wasd_arrow(game);
	}
}

void	ft_collectable(t_game *game)
{
	int32_t	index;
	int32_t	coin_y;
	int32_t	coin_x;

	index = 0;
	game->userdata->y_pos = game->sprites->player->instances->y / PIXEL_SIZE;
	game->userdata->x_pos = game->sprites->player->instances->x / PIXEL_SIZE;
	ft_printf("\nPlayer_y[%i]x[%i]", game->userdata->y_pos, game->userdata->x_pos);
	while (index < game->map->coin_index)
	{
		coin_x = game->sprites->coin->instances[index].x / PIXEL_SIZE;
		coin_y = game->sprites->coin->instances[index].y / PIXEL_SIZE;
		ft_printf("\nCoin[%i]_pos_y[%i]x[%i]", index, coin_y, coin_x);
		if ((game->userdata->y_pos == coin_y && game->userdata->x_pos == coin_x) 
			&& game->sprites->coin->instances[index].enabled == true)
		{
			++game->userdata->totalcoins;
			ft_printf("\nYou've saved an Astronaut! (%i/%i)\n",
			game->userdata->totalcoins, game->map->coin_index);
			game->sprites->coin->instances[index].enabled = false;
		}
		index++;
	}
}

void	show_exit(t_game *game)
{
	if (game->userdata->totalcoins == game->map->coin_index)
	{
		ft_printf("\n\nGREAT! You've saved all Astronauts!\n");
		ft_printf("\nLet's go back home!\n");
		game->sprites->exit->instances->enabled = true;

		ft_printf("\nExit_pos_y[%i]x[%i]\n", 
					game->sprites->exit->instances->y / PIXEL_SIZE,
					game->sprites->exit->instances->x / PIXEL_SIZE);
	}
}
