/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_builder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:50:18 by umeneses          #+#    #+#             */
/*   Updated: 2024/01/29 19:52:38 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* TODO = 2 blocks ARE definitely lost here. Search and destroy it! */

bool	*map_build_matrix(char **argv, t_map *map)
{
	map->fd = open(argv[1], O_RDONLY);
	ft_printf("\ninside matrix map.line = %s\n", map->line);
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
	/* START MEMORY ALLOCATION */
	map->matrix = ft_calloc(2, sizeof(char *));
	map->index = 0;	
	while (map->index < map->height)
	{
		map->matrix[map->index] = ft_calloc(2, sizeof(char *));
		map->index++;
	}
	/* END MEMORY ALLOCATION */
	map->matrix = ft_split(ft_get_next_line(map->fd), '\n');
	if ((map->matrix == (void *)0) || !map->matrix)
	{
		ft_putendl_fd("\nMemory Map allocation error.\n", STDOUT_FILENO);
		free (map->matrix);
		close (map->fd);
		return (false);
	}
	/* START CHECKING MATRIX */
	int32_t x = 0;
	int32_t	y = 0;
	ft_printf("\nprinting matrix now\n");
	while (x <= map->height)
	{
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
	return (true);
}
