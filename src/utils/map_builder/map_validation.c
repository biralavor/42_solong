/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:38:49 by umeneses          #+#    #+#             */
/*   Updated: 2024/01/30 16:47:52 by umeneses         ###   ########.fr       */
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

bool	*map_size_checker(t_map *map)
{
	map->width = 0;
	map->height = 0;
	map->line = ft_get_next_line(map->fd);
	while (map->line)
	{
		if (map->width == 0)
			map->width = (ft_strlen(map->line) - 1);
		if (map_bad_format(map) == false)
		{
			if (map_too_big(map) == false)
			{
				map->matrix = map_allocation(map->matrix, map->line, \
												map->height);
				map->height++;
				map->line = ft_get_next_line(map->fd);
			}
		}
	}
	if ((map_too_tiny(map) == false))
	{
		map->size = map->height * map->width;
		ft_printf("map->size = %d\n", map->size);
		ft_printf("map->width = %d\n", map->width);
		ft_printf("map->height = %d\n", map->height);
		ft_printf("map->fd TAIL = %d\n", map->fd);
		ft_printf("map_matrix[0] = %s",map->matrix[0]);
		ft_printf("map_matrix[1] = %s",map->matrix[1]);
		ft_printf("map_matrix[2] = %s",map->matrix[2]);
		ft_printf("map_matrix[?] = . . . \n");
		ft_printf("map_matrix[?] = %s",map->matrix[map->height - 3]);
		ft_printf("map_matrix[?] = %s",map->matrix[map->height - 2]);
		ft_printf("map_matrix[?] = %s",map->matrix[map->height - 1]);
		ft_printf("\nmap size checker = true\n");
		close(map->fd);
	}
	return (true);
}

bool	map_bad_format(t_map *map)
{
	if ((map->width != ft_strlen(map->line) - 1) && \
			map->line[map->width] != '\0')
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
