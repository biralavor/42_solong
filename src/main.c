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

void	structures_init(t_game *game)
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
}

int32_t	main(int32_t argc, char **argv)
{
	static t_game	*game;

	if (argc == 2)
	{
		if (map_extension_approved(argv))
		{
			// structures_init(game);
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
			if (map_init(argv, game))
			{
				ft_printf("\nmap init = ok\n");
				matrix_printer(game->map);
				game_init(game);
				free_all_mlx_usage(game);
			}
			free(game->userdata);
			free(game->sprites);
			free_map(game->map);
			free (game);
		}
	}
	else if (argc > 2)
		return (ft_putendl_fd("Error\nToo many arguments, buddy.",
				STDOUT_FILENO), EXIT_FAILURE);
	else
		return (ft_putendl_fd("Ops!\nWhere is your map?",
				STDOUT_FILENO), EXIT_FAILURE);
	return (0);
}
