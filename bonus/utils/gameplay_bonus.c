/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 10:08:04 by umeneses          #+#    #+#             */
/*   Updated: 2025/03/13 14:54:43 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	frame_update(mlx_key_data_t key, t_game *game)
{
	game->userdata->y_pos = game->sprites->player->instances->y / PIXEL_SIZE;
	game->userdata->x_pos = game->sprites->player->instances->x / PIXEL_SIZE;
	if (key.action == MLX_PRESS)
	{
		if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		{
			ft_printf(RED);
			write(1, "\nN00OOOOOOO00!\n", 16);
			write(1, "\\¯\\_(ツ)_/¯/\n\n", 16);
			mlx_close_window(game->mlx);
			return ;
		}
		keyb_wasd_arrow(key, game);
	}
	coins_update(game);
	end_game(game);
}

void	coins_update(t_game *game)
{
	int32_t	index;
	int32_t	coin_y;
	int32_t	coin_x;

	index = 0;
	while (index < game->map->coin_index)
	{
		coin_x = game->sprites->coin->instances[index].x / PIXEL_SIZE;
		coin_y = game->sprites->coin->instances[index].y / PIXEL_SIZE;
		if ((game->userdata->y_pos == coin_y && game->userdata->x_pos == coin_x)
			&& game->sprites->coin->instances[index].enabled == true)
		{
			++game->userdata->totalcoins;
			ft_printf(GRE"\a\nYou've saved an Astronaut!\n"RESET);
			game->sprites->coin->instances[index].enabled = false;
			show_exit(game);
		}
		index++;
	}
}

void	show_exit(t_game *game)
{
	if (game->userdata->totalcoins == game->map->coin_index)
	{
		ft_printf(GRE"\nGREAT! You've saved all Astronauts!\n");
		ft_printf(YEL"Your last mission >>> "CYA"Let's go back home!\n"RESET);
		game->sprites->exit->instances->enabled = true;
	}
}

void	end_game(t_game *game)
{
	if (game->userdata->shield == 0)
	{
		ft_printf(YEL"\nYou've lost all your shield!\n");
		ft_printf(RED"\nGAME OVER! (╥﹏╥)\n");
		mlx_close_window(game->mlx);
	}
	if ((game->userdata->y_pos
			== game->sprites->exit->instances->y / PIXEL_SIZE)
		&& (game->userdata->x_pos
			== game->sprites->exit->instances->x / PIXEL_SIZE)
		&& game->sprites->exit->instances->enabled == true)
	{
		ft_printf(GRE"\nAll Astronauts have arrived safely >>> 🌎\n");
		ft_printf("\a\nCONGRATULATIONS! You WON!"CYA"\n\n\\( ﾟヮﾟ)/🏆\n\n");
		mlx_close_window(game->mlx);
	}
}
