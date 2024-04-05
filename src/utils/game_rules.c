/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 12:19:44 by umeneses          #+#    #+#             */
/*   Updated: 2024/04/05 18:19:20 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_collectables(t_game *game)
{
	int32_t	index;
	int32_t	coin_y;
	int32_t	coin_x;

	index = 0;
	game->userdata->y_pos = game->sprites->player->instances->y / PIXEL_SIZE;
	game->userdata->x_pos = game->sprites->player->instances->x / PIXEL_SIZE;
	while (index < game->map->coin_index)
	{
		coin_x = game->sprites->coin->instances[index].x / PIXEL_SIZE;
		coin_y = game->sprites->coin->instances[index].y / PIXEL_SIZE;
		// ft_printf("\nCoin[%i]_pos_y[%i]x[%i]", index, coin_y, coin_x);
		if ((game->userdata->y_pos == coin_y && game->userdata->x_pos == coin_x) 
			&& game->sprites->coin->instances[index].enabled == true)
		{
			++game->userdata->totalcoins;
			ft_printf("\nYou've saved an Astronaut! (%i/%i)\n",
			game->userdata->totalcoins, game->map->coin_index);
			game->sprites->coin->instances[index].enabled = false;
			show_exit(game);
		}
		index++;
	}
}

void	future_player_pos(mlx_key_data_t key, t_game *game)
{
	if ((key.key == MLX_KEY_UP) || (key.key == MLX_KEY_W))
		game->userdata->future_y_pos -= 1;
	if ((key.key == MLX_KEY_DOWN) || (key.key == MLX_KEY_S))
		game->userdata->future_y_pos += 1;
	if ((key.key == MLX_KEY_LEFT) || (key.key == MLX_KEY_A))
		game->userdata->future_x_pos -= 1;
	if ((key.key == MLX_KEY_RIGHT) || (key.key == MLX_KEY_D))
		game->userdata->future_x_pos += 1;
}

bool	is_wall(mlx_key_data_t key, t_game *game)
{
	int32_t	index;
	int32_t	wall_y;
	int32_t	wall_x;

	ft_printf("\nPlayer_y[%i]x[%i]", game->userdata->y_pos, game->userdata->x_pos);
	future_player_pos(key, game);
	ft_printf("\n\nFuturePlayer_y[%i]x[%i]", game->userdata->future_y_pos, 
											game->userdata->future_x_pos);
	index = 0;
	wall_y = 0;
	wall_x = 0;
	while (index < game->map->border_index)
	{
		wall_y = game->sprites->border->instances[index].y / PIXEL_SIZE;
		wall_x = game->sprites->border->instances[index].x / PIXEL_SIZE;
		// ft_printf("\nWall[%i]_pos_y[%i]x[%i]", index, wall_y, wall_x);
		if (game->userdata->future_y_pos == wall_y 
			&& game->userdata->future_x_pos == wall_x) 
		{
			ft_printf("\n\nYou've hit a Meteor!\nWATCH OUT!\n\n");
			return (true);
		}
		index++;
	}
	return (false);
}
