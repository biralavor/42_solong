/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 10:08:04 by umeneses          #+#    #+#             */
/*   Updated: 2024/04/10 12:25:39 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	frame_update(mlx_key_data_t key, t_game *game)
{
	ft_collectables(game);
	if (key.action == MLX_PRESS)
	{
		if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		{
			write(1, "\n\nN00OOOOOOO00!\n\n", 18);
			write(1, "\\¯\\_(ツ)_/¯/\n\n", 18);
			mlx_close_window(game->mlx);
			return ;
		}
		keyb_wasd_arrow(key, game);
	}
	end_game(game);
}

void	show_exit(t_game *game)
{
	if (game->userdata->totalcoins == game->map->coin_index)
	{
		ft_printf("\n\nGREAT! You've saved all Astronauts!\n");
		ft_printf("\nLet's go back home!\n");
		game->sprites->exit->instances->enabled = true;
	}
}

void	end_game(t_game *game)
{
	if ((game->userdata->y_pos
			== game->sprites->exit->instances->y / PIXEL_SIZE)
		&& (game->userdata->x_pos
			== game->sprites->exit->instances->x / PIXEL_SIZE)
		&& game->sprites->exit->instances->enabled == true)
	{
		ft_printf("\n\nYou have arrived >>> 🌎\n");
		ft_printf("\nCONGRATULATIONS! You WON!\n\n");
		mlx_close_window(game->mlx);
	}
}
