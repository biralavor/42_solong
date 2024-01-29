/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:47:07 by umeneses          #+#    #+#             */
/*   Updated: 2024/01/29 14:36:57 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int32_t main(int32_t argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		if (map_extension_check(argv) == true)
		{
			ft_printf("extension = true\n");
			if (map_opener(argv, &game.map) == true)
				ft_printf("map opener = true\n");
			if (map_size_check(&game.map) == true)
				ft_printf("map size check = true\n");
			if (map_build_matrix(argv, &game.map) == true)
				ft_printf("map matrix = done\n");
			// if (map_reader(game.map) == true)
			// {
			// 	ft_printf("map reader = true\n");
			// }
			// if (map_check(argv, game.map) == true)
			// {
			// 	ft_printf("\n map approved! \n");
			// 	close (game.map->fd);
			// }
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