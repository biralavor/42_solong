/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bira <bira@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:38:49 by umeneses          #+#    #+#             */
/*   Updated: 2024/02/16 10:48:12 by bira             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	map_extension_approved(char **argv)
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
			if ((extension_name[index] == '.') && \
				(extension_name[++index] == 'b') && \
				(extension_name[++index] == 'e') && \
				(extension_name[++index] == 'r'))
					return (true);
		ft_putendl_fd("Error\nGame Map file extension too long.\n \
						It needs to be '.ber'\n", STDOUT_FILENO);
		return (false);
		break ;
	}
	return (false);
}

bool	map_size_approved(t_map *map)
{
	char	*toremove;

	toremove = "\n";
	map->height = 0;
	map->line = ft_strtrim(ft_get_next_line(map->fd), toremove);
	if (map->line != NULL)
		map->first_lenght = ft_strlen(map->line) - 1;
	while (map->line)
	{
		map->width = ft_strlen(map->line) - 1;
		if ((map_too_big(map) == false) && (map_too_tiny(map) == false) && (map_bad_format(map) == false))
		{
			map->matrix = map_allocation(map->matrix, map->line, map->height);
			map->height++;
			map->size = map->height * map->width;
			map->line = ft_strtrim(ft_get_next_line(map->fd), toremove);
		}
		else
		{
			free(map->matrix);
			free(map->line);
			return (false);
			break ;
		}
	}
	close(map->fd);
	return (true);
}

bool	map_bad_format(t_map *map)
{
	if (map->height >= 1)
	{
		ft_printf("ft_bad_format map-line = %s\n", map->line);
		ft_printf("ft_bad_format map->width (%d) at map->height (%d) \n", map->width, map->height);
		ft_printf("map->first_lenght = %d\n", map->first_lenght);
		if (map->first_lenght != map->width)
		{
			ft_putendl_fd("\nError\nYour Map isn't rectangular.\n", STDOUT_FILENO);
			return (true);
		}
	}
	return (false);
}

bool	map_too_big(t_map *map)
{
	if (map->line == NULL)
	{
		if (map->width > MAX_MAP_WIDTH || map->height > MAX_MAP_HEIGHT)
		{
			ft_putendl_fd("\nError\nMap is too big.\n", STDOUT_FILENO);
			return (true);
		}
	}
	return (false);
}

bool	map_too_tiny(t_map *map)
{
	if (map->line == NULL)
	{
		if ((map->height < MIN_MAP_HEIGHT) || (map->width < MIN_MAP_WIDTH))
		{
			ft_putendl_fd("\nError\nMap is too tiny.\n", STDOUT_FILENO);
			return (true);
		}
	}
	return (false);
}
