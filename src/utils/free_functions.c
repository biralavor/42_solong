/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:11:16 by umeneses          #+#    #+#             */
/*   Updated: 2024/02/19 19:17:27 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_map *map)
{
	int	index;
	
	index = -1;
	while (++index < map->height)
		free(map->matrix[index]);
	free(map->matrix);
	free(map);
}

void	free_matrix(char ***matrix)
{
	int	index;

	index = 0;
	while ((index < matrix[index]) && (matrix[index] != NULL))
	{
		free(matrix[index]);
		index++;
	}
	free(matrix);
}

void	free_images(t_game *game, mlx_image_t* image)
{
	mlx_delete_image(game->mlx, image);
}
