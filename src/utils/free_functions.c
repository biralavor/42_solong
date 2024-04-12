/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:11:16 by umeneses          #+#    #+#             */
/*   Updated: 2024/04/12 14:41:03 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_map *map)
{
	free_matrix(map->matrix);
	free(map);
}

void	free_matrix(char **matrix)
{
	int	index;

	index = 0;
	while (matrix[index] != NULL)
	{
		free(matrix[index]);
		matrix[index] = NULL;
		index++;
	}
	free(matrix);
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
