/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:47:07 by umeneses          #+#    #+#             */
/*   Updated: 2024/04/06 16:15:23 by umeneses         ###   ########.fr       */
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

void	free_all_sprites(t_game *game)
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

int32_t	main(int32_t argc, char **argv)
{
	static t_game	*game;

	if (argc == 2)
	{
		if (map_extension_approved(argv))
		{
			game = ft_calloc(1, sizeof(t_game));
			game->map = ft_calloc(1, sizeof(t_map));
			game->sprites = ft_calloc(1, sizeof(t_sprite));
			game->userdata = ft_calloc(1, sizeof(t_userdata));
			game->userdata->totalmoves = 0;
			game->userdata->totalcoins = 0;
			game->userdata->y_pos = 0;
			game->userdata->x_pos = 0;
			if (map_init(argv, game))
			{
				ft_printf("\nmap init = ok\n");
				matrix_printer(game->map);
				game_init(game);
				free_all_sprites(game);
			}
			free(game->userdata);
			free(game->sprites);
			free_map(game->map);
			free (game);
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
// ui_stats_canvas(game);

// mlx_loop_hook(game->mlx, play_random_color, game->mlx);
