/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:47:07 by umeneses          #+#    #+#             */
/*   Updated: 2024/04/10 16:05:32 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	map_init(char **argv, t_game *game)
{
	if (map_opener(argv, game->map) && map_reader(argv, game->map))
	{
		if (!map_too_tiny(game->map) && !map_too_big(game->map))
		{
			free (game->map->buffer);
			if (map_size_approved(game->map))
				if (map_contents_checker(game->map))
					return (true);
		}
	}
	ft_putendl_fd("It didn't initialize correctly.\n", STDOUT_FILENO);
	return (false);
}

t_game	*structures_init(t_game *game)
{
	game = ft_calloc(1, sizeof(t_game));
	game->map = ft_calloc(1, sizeof(t_map));
	game->sprites = ft_calloc(1, sizeof(t_sprite));
	game->userdata = ft_calloc(1, sizeof(t_userdata));
	game->userdata->totalmoves = 0;
	game->userdata->totalcoins = 0;
	game->userdata->y_pos = 0;
	game->userdata->x_pos = 0;
	game->map->coin_index = 0;
	game->map->read_y = -1;
	game->map->read_x = -1;
	return (game);
}

int32_t	main(int32_t argc, char **argv)
{
	static t_game	*game;

	if ((argc == 2) && (map_extension_approved(argv)))
	{
		game = structures_init(game);
		if (map_init(argv, game))
		{
			ft_printf("\nmap init = ok\n");
			matrix_printer(game->map);
			game_init(game);
			free_all_mlx_usage(game);
			free_map(game->map);
		}
		free(game->userdata);
		free(game->sprites);
		free (game);
	}
	else if (argc > 2)
		return (ft_putendl_fd("Error\nToo many arguments, buddy.",
				STDOUT_FILENO), EXIT_FAILURE);
	else
		return (ft_putendl_fd("Ops!\nWhere is your map?",
				STDOUT_FILENO), EXIT_FAILURE);
	return (0);
}
