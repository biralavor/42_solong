/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contents_validation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:38:49 by umeneses          #+#    #+#             */
/*   Updated: 2024/01/30 18:12:32 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	*map_contens_checker(t_map *map)
{
	ft_printf("\nEntering MAP_ITEMS_CHECKER:\n");
	if (has_specific_char(map, "P") == true)
		ft_printf("\nPlayer = true\n");
	if (has_specific_char(map, "C") == true)
		ft_printf("\nCollectable = true\n");
	if (has_specific_char(map, "E") == true)
		ft_printf("\nExit = true\n");
	return (false);
}

bool	*has_specific_char(t_map *map, char *tofind)
{
	char		*line;
	int32_t		x;

	x = 0;
	while (x <= map->height - 1)
	{
		line = ft_strnstr(map->matrix[x], tofind, map->width - 1);
		while (!line)
		{
			x++;
			line = ft_strnstr(map->matrix[x], tofind, map->width - 1);
			if (x == map->height - 1)
			{
				ft_putendl_fd("\nError\nPlayer not found!\n", STDOUT_FILENO);
				return (false);
			}
		}
		break ;
	}
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
