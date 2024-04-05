/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 12:19:44 by umeneses          #+#    #+#             */
/*   Updated: 2024/04/05 15:56:28 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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



bool	is_wall(mlx_key_data_t key, t_game *game)
{
	int32_t	index;
	int32_t	y;
	int32_t	x;

	index = 0;
	y = -1;
	while (index < game->map->border_index)
	{
		
		if ((game->userdata->y_pos == game->sprites->border->instances[index].y / PIXEL_SIZE)
			&& (game->userdata->x_pos == game->sprites->border->instances[index].x / PIXEL_SIZE))
			{
				ft_printf("\n\nYou've hit a Meteor!\nWATCH OUT!\n\n");
				mlx_close_window(game->mlx);
				return (true);
			}
		index++;
	}
	ft_printf("\nborder_index: %i\n", game->map->border_index);
	ft_printf("is_wall index: %i\n", index);
	return (false);
}
