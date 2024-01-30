/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_builder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:50:18 by umeneses          #+#    #+#             */
/*   Updated: 2024/01/30 16:49:04 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* TODO = 2 blocks ARE definitely lost here. Search and destroy it! */

bool	*map_build_matrix(char **argv, t_map *map)
{
	map->fd = open(argv[1], O_RDONLY);
	ft_printf("inside matrix map->size = %d\n", map->size);
	ft_printf("inside matrix map->width = %d\n", map->width);
	ft_printf("inside matrix map->height = %d\n", map->height);
	ft_printf("map->fd = %d\n", map->fd);
	ft_printf("\nrunning matrix now->->->\n");
	if (map->fd == -1)
	{
		ft_putendl_fd("Error!\nInvalid map file, building Matrix T.T", \
						STDOUT_FILENO);
		close(map->fd);
		return (false);
	}

	/* START CHECKING MATRIX */
	ft_printf("\nprinting matrix now\n");
	int32_t x = 0;
	while (x <= map->height - 1)
	{
		int32_t	y = 0;
		while (y <= map->width)
		{
			ft_printf("%c", map->matrix[x][y]);
			y++;
		}
		x++;
	}
	/* END CHECKING MATRIX */

	ft_printf("\nend of matrix \n");
	// free (map->line);
	// free (map->matrix);
	// close (map->fd);
	ft_printf("map matrix = done\n");
	return (true);
}
