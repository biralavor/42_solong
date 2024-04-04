/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 10:08:04 by umeneses          #+#    #+#             */
/*   Updated: 2024/04/04 15:31:38 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	frame_update(mlx_key_data_t key, t_game *game)
{
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
		ft_collectable(game);
	}
}

void	ft_collectable(t_game *game)
{
	int32_t	index;

	ft_printf("\nPlayer_pos[%i][%i]", game->map->matrix
	[game->sprites->player->instances->x / PIXEL_SIZE]
	[game->sprites->player->instances->y / PIXEL_SIZE]);
	index = 0;
	while (index <= game->map->coin_index)
	{
		// ft_printf("\nCoin[%i]_pos[%i][%i]", index,
		// game->map->matrix[game->sprites->coin->instances[index].x / PIXEL_SIZE]
		// [game->sprites->coin->instances[index].y / PIXEL_SIZE]);
		index++;
	}
	
	// ft_printf("y = %i\n", game->sprites->player->instances->x / PIXEL_SIZE);
	// if (game->map->matrix[game->sprites->player->instances->y]	\
		[game->sprites->player->instances->x] == 'C')
		// {
		// 	game->map->matrix[game->sprites->player->instances->y]	\
		// 	[game->sprites->player->instances->x] = '0';
		// 	ft_printf("\nYou've collected a coin!\nTotal Coins = %i",	\
		// 	++game->userdata->totalcoins);
		// }
}
