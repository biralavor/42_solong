/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:11:16 by umeneses          #+#    #+#             */
/*   Updated: 2024/04/01 16:01:51 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_map *map)
{
	int	index;
	
	index = -1;
	while (++index < map->height)
		free(map->matrix[index]);
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
		index++;
	}
	free(matrix);
}
