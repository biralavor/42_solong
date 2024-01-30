/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:38:49 by umeneses          #+#    #+#             */
/*   Updated: 2024/01/30 12:43:11 by umeneses         ###   ########.fr       */
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
	map->bad_format = false;
	map->line = ft_get_next_line(map->fd);
	ft_printf("map->fd HEAD of SizeChecker = %d\n", map->fd);
	ft_printf("\nmap_line = %s\n", map->line);
	ft_printf("\nmap_size_checker() results:\n");
	while (map->line)
	{
		if (map->width == 0)
			map->width = (ft_strlen(map->line) - 1);
		if ((map->width != ft_strlen(map->line) - 1) && \
				map->line[map->width] != '\0')
			map->bad_format = true;
		map->matrix = mem_alloc(map->matrix, map->line, map->height);
		map->height++;
		map->line = ft_get_next_line(map->fd);
	}
	if (map->bad_format == true)
	{
		ft_putendl_fd("\nError\nMap requirements doesn't match.\n", \
						STDOUT_FILENO);
		return (false);
	}
	if (map->width > MAX_MAP_WIDTH || map->height > MAX_MAP_HEIGHT)
	{
		ft_putendl_fd("\nError\nMap is too big.\n", STDOUT_FILENO);
		return (false);
	}
	map->size = map->height * map->width;
	ft_printf("map->size = %d\n", map->size);
	ft_printf("map->width = %d\n", map->width);
	ft_printf("map->height = %d\n", map->height);
	ft_printf("map->fd TAIL = %d\n", map->fd);
	ft_printf("map_matrix[2] = %s\n",map->matrix[2]);
	close(map->fd);
	return (true);
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
