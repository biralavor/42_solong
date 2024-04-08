/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 18:51:01 by umeneses          #+#    #+#             */
/*   Updated: 2024/04/08 18:51:05 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	map_init(char **argv, t_game *game)
{
	if (map_opener(argv, game->map)
		&& map_reader(argv, game->map))
	{
		if (!map_too_tiny(game->map)
			&& !map_too_big(game->map))
		{
			free (game->map->buffer);
			if (map_size_approved(game->map)
				&& map_contents_checker(game->map))
				return (true);
		}
	}
	ft_putendl_fd("It didn't initialize correctly.\n", STDOUT_FILENO);
	return (false);
}

void	game_init(t_game *game)
{
	game->mlx = mlx_init(WIDTH, HEIGHT, "42_Astronauts_So_Long_Game", true);
	render_fixedsprites(game->mlx, game->sprites, game->map);
	render_movingsprites(game->mlx, game->sprites, game->map);
	mlx_key_hook(game->mlx, &frame_update, game);
	mlx_loop(game->mlx);
}

void	free_all_mlx_usage(t_game *game)
{
	mlx_delete_texture(game->sprites->back_tt);
	mlx_delete_texture(game->sprites->border_tt);
	mlx_delete_texture(game->sprites->player_tt);
	mlx_delete_texture(game->sprites->coin_tt);
	mlx_delete_texture(game->sprites->exit_tt);
	mlx_delete_image(game->mlx, game->sprites->back);
	mlx_delete_image(game->mlx, game->sprites->border);
	mlx_delete_image(game->mlx, game->sprites->player);
	mlx_delete_image(game->mlx, game->sprites->coin);
	mlx_delete_image(game->mlx, game->sprites->exit);
	mlx_terminate(game->mlx);
}
