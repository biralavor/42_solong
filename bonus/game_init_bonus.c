/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 18:51:01 by umeneses          #+#    #+#             */
/*   Updated: 2024/04/12 23:16:46 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	game_init(t_game *game)
{
	game->mlx = mlx_init(WIDTH, HEIGHT, "42_Astronauts_So_Long_Game", true);
	if (game->mlx == NULL)
	{
		ft_putendl_fd("MLX library not working.\n", STDOUT_FILENO);
		return ;
	}
	render_fixedsprites(game->mlx, game->sprites, game->map);
	render_movingsprites(game->mlx, game->sprites, game->map);
	canvas_hud(game);
	mlx_key_hook(game->mlx, (mlx_keyfunc)frame_update, game);
	mlx_loop(game->mlx);
}

void	canvas_hud(t_game *game)
{
	const char	*mission_control;

	mission_control = "Mission Control >>>> SAVE THE ASTRONAUTS!";
	game->hud->mission_txt = mlx_put_string(game->mlx, mission_control, \
		0, HEIGHT - (HEIGHT * 0.1));
}
