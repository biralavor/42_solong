/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_rules_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 12:19:44 by umeneses          #+#    #+#             */
/*   Updated: 2025/03/12 12:01:06 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

	future_player_pos(key, game);
	index = 0;
	wall_y = 0;
	wall_x = 0;
	while (index < game->map->border_index)
	{
		wall_y = game->sprites->border->instances[index].y / PIXEL_SIZE;
		wall_x = game->sprites->border->instances[index].x / PIXEL_SIZE;
		if (game->userdata->future_y_pos == wall_y
			&& game->userdata->future_x_pos == wall_x)
		{
			game->userdata->shield--;
			ft_printf(RED"\n(ง ◉ _ ◉)ง WATCH OUT >>> " \
				YEL"You've hit an Asteroid! 💥\n"RESET);
			return (true);
		}
		index++;
	}
	return (false);
}

void	shield_warnings(t_game *game)
{
	shield_counter_printer(game);
	if (game->userdata->shield == 2)
		ft_printf(RED" <<< WARNING! >>> " \
			YEL"You have a breach in the hull!"RESET);
	if (game->userdata->shield == 1)
		ft_printf(RED" <<< GOSH! >>> "YEL"You only have one engine!"RESET);
	ft_printf("\n*************\n");
}

void	shield_counter_printer(t_game *game)
{
	int	total_shield;
	int	user_shield;
	int	idx;
	
	idx = -1;
	total_shield = game->userdata->totalshield * 2;
	user_shield = game->userdata->shield * 2;
	ft_printf(RESET"\n(");
	if (user_shield == total_shield)
	{
		while (++idx <= total_shield)
		write(1, "|", 1);
	}
	else
	{
		while (++idx < user_shield)
			ft_printf(RED"|"RESET);
		while (++idx <= total_shield)
			ft_printf(RESET"|");
	}
	ft_printf(RESET") "PUR"Spacecraft Shield"RESET);
}
