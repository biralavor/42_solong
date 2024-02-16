/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bira <bira@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:47:07 by umeneses          #+#    #+#             */
/*   Updated: 2024/02/16 10:47:45 by bira             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int32_t main(int32_t argc, char **argv)
{
	t_game	*game;

	game = (t_game *)ft_calloc(1, sizeof(t_game));
	game->map = (t_map *)ft_calloc(1, sizeof(t_map));
	if (argc == 2)
	{
		if (map_extension_approved(argv) == true &&		\
			map_opener(argv, game->map) == true &&		\
			map_size_approved(game->map) == true &&		\
			map_contens_checker(game->map) == true)
		{
			// map_build_matrix(argv, game->map);
			ft_printf("\nmap approved!\n");
			// free (&game.map->line);
			// close (&game.map->fd);
		}
	}
	else if (argc > 2)
		return (ft_putendl_fd("Error\nToo many arguments, buddy.", \
				STDOUT_FILENO), EXIT_FAILURE);
	else
		return (ft_putendl_fd("Ops!\nWhere is your map?", \
				STDOUT_FILENO), EXIT_FAILURE);
	return (0);
}

// game = structures_init();
// game->mlx = mlx_init(WIDTH, HEIGHT, "42_Astronauts_So_Long_Game", true);
// load_texture(game);
// ui_stats_canvas(game);
// game->ship_img = mlx_new_image(game->mlx, 48, 39);
// if (!game->mlx || !game->ship_img)
// {
// 	mlx_close_window(game->mlx);
// 	error();
// }
// if (mlx_image_to_window(game->mlx, game->ship_img, 50, 50) == -1)
// {
// 	mlx_close_window(game->mlx);
// 	error();
// }
// mlx_loop_hook(game->mlx, play_random_color, game->mlx);
// mlx_key_hook(game->mlx, keyb_wasd_arrow, NULL);
// mlx_key_hook(game->mlx, &movecounter, NULL);
// mlx_loop(game->mlx);
// mlx_close_window(game->mlx);
// mlx_terminate(game->mlx);