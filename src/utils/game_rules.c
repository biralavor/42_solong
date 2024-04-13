/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 12:19:44 by umeneses          #+#    #+#             */
/*   Updated: 2024/04/12 22:35:33 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
			ft_printf("\nWATCH OUT\nYou've hit a Meteor!\n\n");
			return (true);
		}
		index++;
	}
	return (false);
}
