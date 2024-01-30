/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contents_validation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:38:49 by umeneses          #+#    #+#             */
/*   Updated: 2024/01/30 15:03:48 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	*map_items_checker(t_map *map)
{
	if (has_player(map) == true)
	{
		ft_printf("player = true\n");
	}
	return (false);
}

bool	*has_player(t_map *map)
{
	char	*tofind;
	char	*line;
	int		i;
	int		j;

	tofind = "P";
	i = 0;
	j = 0;
	ft_printf("has_player map.width = %d\n", map->width);
	ft_printf("has_player map.height = %d\n", map->height);
	// ft_printf("matrix = %c %c\n", map->matrix[i][j]);
	// while (i >= map->width)
	// {
	// 	ft_printf("matrix = %s\n", map->matrix[i][j]);
	// 	i++;
	// 	while (j >= map->height)
	// 		ft_printf("matrix = %s\n", map->matrix[i][j]);
	// 	j++;
	// }
	
	// while (map->matrix[i, j] <= map->matrix[map->width, map->height])
	// {
	// 	line = ft_strnstr(map->matrix[i], tofind, map->width);
	// 	if (line != tofind)
	// 	{
	// 		ft_putendl_fd("Error\nPlayer not found!\n", STDOUT_FILENO);
	// 		return (false);
	// 	}
	// 	i++;
	// 	j++;
	// }
	return (true);
}

bool	has_wall(char *line)
{
	char	*tofind;
	int		index;

	index = ft_strlen(line);
	tofind = "1";
	ft_printf("index = %d\n", index);
	ft_printf("tofind = %s\n", tofind);
	ft_printf("line[0] = %s\n", line[0]);
	ft_printf("line[index] = %s\n", line[index]);
	if ((line[0] == tofind[1]) && (line[index] == tofind[1]))
		return (true);
	return (false);
}
