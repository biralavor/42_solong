/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:29:17 by umeneses          #+#    #+#             */
/*   Updated: 2024/01/30 15:03:41 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	*map_opener(char **argv, t_map *map)
{
	map->fd = open(argv[1], O_RDONLY);
	ft_printf("map->fd = %d\n", map->fd);
	if (map->fd == -1)
	{
		ft_putendl_fd("Error!\nInvalid map file T.T", STDOUT_FILENO);
		close(map->fd);
		return (false);
	}
	return (true);
}
