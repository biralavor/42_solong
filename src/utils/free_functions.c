/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bira <bira@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:11:16 by umeneses          #+#    #+#             */
/*   Updated: 2024/02/16 19:20:58 by bira             ###   ########.fr       */
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
}

void	free_images(t_game *game)
{
	// mlx_delete_image(game->mlx, XXXX);
}

void	free_textures(t_game *game)
{
	// mlx_delete_texture(game->mlx, XXXX);
}