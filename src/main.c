/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:47:07 by umeneses          #+#    #+#             */
/*   Updated: 2024/01/25 16:52:44 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int32_t main(int32_t argc, char **argv)
{
	t_game	game;
	t_map	map;
	char	*gnl_temp;

	map.index = 0;
	if (argc == 2)
	{
		if (map.fd == -1)
			return (ft_putendl_fd("Error!\nInvalid map file T.T", \
					STDOUT_FILENO), EXIT_FAILURE);
		if (map_extension_check(argv) == true && \
			map_check(argv, map) == true)
		{
			ft_printf(COLOR_CYAN);
			ft_printf("\n map approved! \n");
			// ft_printf("Reading Program: %s \n", argv[0]);
			// ft_printf("Reading map file using GNL: %s \n", argv[1]);
			// gnl_temp = "";
			// map.fd = open(argv[1], O_RDONLY);
			// while (gnl_temp)
			// {
			// 	ft_printf(COLOR_PURPLE);
			// 	ft_printf("GNL MAP MAIN %i = ", map.index);
			// 	gnl_temp = ft_get_next_line(map.fd);
			// 	ft_printf("%s", gnl_temp);
			// 	free(gnl_temp);
			// 	map.index++;
			// }
			// ft_printf(COLOR_CYAN);
			ft_printf(COLOR_RESET);
			close (map.fd);
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