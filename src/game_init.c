/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 18:51:01 by umeneses          #+#    #+#             */
/*   Updated: 2024/04/12 16:20:15 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	mlx_key_hook(game->mlx, (mlx_keyfunc)frame_update, game);
	mlx_loop(game->mlx);
}
