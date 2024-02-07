/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bira <bira@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:38:49 by umeneses          #+#    #+#             */
/*   Updated: 2024/02/07 08:40:18 by bira             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	map_extension_checker(char **argv)
{
	size_t	index;
	size_t	filename_len;
	size_t	extension_len;
	char	*extension_name;

	index = 0;
	filename_len = ft_strlen(argv[1]);
	extension_name = ft_strnstr(argv[1], ".", filename_len);
	extension_len = ft_strlen(extension_name);
	while (extension_name != (void *)0)
	{
		if (extension_len == 4)
			if (extension_name[index] == '.')
				if (extension_name[++index] == 'b')
					if (extension_name[++index] == 'e')
						if (extension_name[++index] == 'r')
							return (true);
		return (ft_putendl_fd("\nGame Map file extension too long.\n \
							It needs to be '.ber'\n", STDOUT_FILENO), false);
		break ;
	}
	return (false);
}

bool	map_size_checker(t_map *map)
{
	map->width = 0;
	map->height = 0;
	map->line = ft_get_next_line(map->fd);
	while (map->line)
	{
		if (map->width == 0)
			map->width = (ft_strlen(map->line) - 2);
		if ((map_bad_format(map) == false) && (map_too_big(map) == false))
		{
			ft_printf("\ninside size checker map->height = %d\n", map->height);
			ft_printf("inside size checker map->width = %d\n", map->width);
			ft_printf("inside size checker map->width (str) = %s\n", map->line);
			map->matrix = map_allocation(map->matrix, map->line, map->height);
			map->height++;
			map->line = ft_get_next_line(map->fd);
		}
		else
		{
			return (false);
			break ;
		}
	}
	if ((map_too_tiny(map) == false))
	{
		map->size = map->height * map->width;
		ft_printf("inside too tiny map->size = %d\n", map->size);
		ft_printf("inside too tiny map->width = %d\n", map->width);
		ft_printf("inside too tiny map->height = %d\n", map->height);
		ft_printf("inside too tiny map->fd TAIL = %d\n", map->fd);
		ft_printf("inside too tiny map_matrix[0] = %s",map->matrix[0]);
		ft_printf("inside too tiny map_matrix[1] = %s",map->matrix[1]);
		ft_printf("inside too tiny map_matrix[2] = %s",map->matrix[2]);
		ft_printf("inside too tiny map_matrix[n] = . . . \n");
		ft_printf("inside too tiny map_matrix[%d] = %s", map->height - 3, map->matrix[map->height - 3]);
		ft_printf("inside too tiny map_matrix[%d] = %s", map->height - 2, map->matrix[map->height - 2]);
		ft_printf("inside too tiny map_matrix[%d] = %s", map->height - 1, map->matrix[map->height - 1]);
		ft_printf("\nmap size checker = true\n");
		close(map->fd);
	}
	return (true);
}

/* TODO why it doesn't recognize the last MAP CHAR in lastest height, if the map IS bad format???*/

bool	map_bad_format(t_map *map)
{
	ft_printf("\nbad format map->width = %d\n", map->width);
	ft_printf("bad format ft_strlen(map->line -2) = %d\n", ft_strlen(map->line) - 2);
	ft_printf("map-line is = %s", map->line);
	if ((map->width != ft_strlen(map->line) - 2) && map->line[map->width] == '\0')
	{
		ft_putendl_fd("\nError\nMap requirements doesn't match.\n", \
				STDOUT_FILENO);
		return (true);
	}
	return (false);
}

bool	map_too_big(t_map *map)
{
	if (map->width > MAX_MAP_WIDTH || map->height > MAX_MAP_HEIGHT)
	{
		ft_putendl_fd("\nError\nMap is too big.\n", STDOUT_FILENO);
		return (true);
	}
	return (false);
}

bool	map_too_tiny(t_map *map)
{
	if (map->height <= MIN_MAP_HEIGHT)
	{
		ft_putendl_fd("\nError\nMap is too tiny.\n", STDOUT_FILENO);
		return (true);
	}
	return (false);
}
