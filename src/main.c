/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:47:07 by umeneses          #+#    #+#             */
/*   Updated: 2024/02/19 17:04:44 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	map_init(char **argv, t_game *game)
{
	if (map_extension_approved(argv) == true &&			\
			map_opener(argv, game->map) == true &&		\
			map_size_approved(game->map) == true &&		\
			map_contents_checker(game->map) == true)
			return (true);
	ft_putendl_fd("Your Map didn't initalize correctly.\n", STDOUT_FILENO);
	return (false);
}

void	game_init(t_game *game)
{
	game->mlx = mlx_init(WIDTH, HEIGHT, "42_Astronauts_So_Long_Game", true);
	// displaying_sprites(game);
	mlx_loop(game->mlx);
}

void	game_end(t_game *game)
{
	free_map(game->map);
	free (game);
	mlx_close_window(game->mlx);
	mlx_terminate(game->mlx);
}

int32_t	main(int32_t argc, char **argv)
{
	t_game	*game;

	if (argc == 2)
	{
		game = (t_game *)ft_calloc(1, sizeof(t_game));
		game->map = (t_map *)ft_calloc(1, sizeof(t_map));
		if (map_init(argv, game) == true)
		{
			ft_printf("\nmap approved!\n");
			matrix_printer(game->map);
		}
		game_init(game);
		game_end(game);
		exit (EXIT_SUCCESS);
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
