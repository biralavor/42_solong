/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_builder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:50:18 by umeneses          #+#    #+#             */
/*   Updated: 2024/02/05 13:32:16 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* TODO = 2 blocks ARE definitely lost here. Search and destroy it! */

bool	map_build_matrix(char **argv, t_map *map)
{
	ft_printf("inside matrix map->size = %d\n", map->size);
	ft_printf("inside matrix map->width = %d\n", map->width);
	ft_printf("inside matrix map->height = %d\n", map->height);
	ft_printf("map->fd = %d\n", map->fd);
	ft_printf("\nrunning matrix now->->->\n");

	/* START CHECKING MATRIX */
	ft_printf("\nprinting matrix now\n");
	matrix_printer(map);
	ft_printf("\nend of matrix \n");
	/* END CHECKING MATRIX */

	// free (map->line);
	// free (map->matrix);
	// close (map->fd);
	ft_printf("map matrix = done\n");
	return (true);
}

	// 	ft_putendl_fd("Error!\nMatrix not built T.T", \
	// 					STDOUT_FILENO);