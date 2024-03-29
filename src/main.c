/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:47:07 by umeneses          #+#    #+#             */
/*   Updated: 2024/02/23 18:06:48 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	map_init(char **argv, t_game *game)
{
	if (map_extension_approved(argv) == true &&			\
			map_opener(argv, game->map) == true)
			if (map_size_approved(game->map) == true &&		\
			map_contents_checker(game->map) == true)
				return (true);
	ft_putendl_fd("It didn't initialize correctly.\n", STDOUT_FILENO);
	return (false);
}

void	game_init(t_game *game)
{
	game->mlx = mlx_init(WIDTH, HEIGHT, "42_Astronauts_So_Long_Game", true);
	// displaying_sprites(game->mlx, game->sprites, game->map);
	mlx_loop(game->mlx);
}

void	game_end(t_game *game)
{
	// mlx_delete_texture(game->sprites->back_tt);
	// mlx_delete_image(game->mlx, game->sprites->back);
	// mlx_delete_texture(game->sprites->border_tt);
	// mlx_delete_image(game->mlx, game->sprites->border);
	// mlx_delete_texture(game->sprites->player_tt);
	// mlx_delete_image(game->mlx, game->sprites->player);
	// mlx_delete_texture(game->sprites->coin_tt);
	// mlx_delete_image(game->mlx, game->sprites->coin);
	// mlx_delete_texture(game->sprites->exit_tt);
	// mlx_delete_image(game->mlx, game->sprites->exit);
	// free(game->sprites);
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
			matrix_printer(game->map);
			// game_init(game);
			// game_end(game);
		}
		free_map(game->map);
		free (game);
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

// mlx_loop_hook(game->mlx, play_random_color, game->mlx);
// mlx_key_hook(game->mlx, keyb_wasd_arrow, NULL);
// mlx_key_hook(game->mlx, &movecounter, NULL);