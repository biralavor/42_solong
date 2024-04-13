/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:47:07 by umeneses          #+#    #+#             */
/*   Updated: 2024/04/12 21:09:50 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

bool	map_extension_approved(char **argv)
{
	size_t	index;
	size_t	filename_len;
	size_t	extension_len;
	char	*extension_name;

	index = 0;
	filename_len = ft_strlen(argv[1]);
	extension_name = ft_strnstr(argv[1], ".", filename_len);
	if (extension_name != (void *)0)
	{
		extension_len = ft_strlen(extension_name);
		while (extension_name != (void *)0)
		{
			if (extension_len == 4)
				if ((extension_name[index] == '.')
					&& (extension_name[++index] == 'b')
					&& (extension_name[++index] == 'e')
					&& (extension_name[++index] == 'r'))
					return (true);
			break ;
		}
	}
	ft_putendl_fd("\nError.\nYour MAP file extension is invalid."
		"\nIt needs to be '.ber'\n", STDOUT_FILENO);
	return (false);
}

t_game	*structures_init(t_game *game)
{
	game = ft_calloc(1, sizeof(t_game));
	game->map = ft_calloc(1, sizeof(t_map));
	game->sprites = ft_calloc(1, sizeof(t_sprite));
	game->userdata = ft_calloc(1, sizeof(t_userdata));
	game->userdata->totalshield = 3;
	game->userdata->shield = 3;
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
