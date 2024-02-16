/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bira <bira@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:38:49 by umeneses          #+#    #+#             */
/*   Updated: 2024/02/15 21:00:31 by bira             ###   ########.fr       */
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

bool	map_size_approved(t_map *map)
{
	map->height = 0;
	map->line = ft_get_next_line(map->fd);
	if (map->line != NULL)
		map->first_lenght = ft_strlen(map->line) - 1;
	while (map->line)
	{
		map->width = ft_strlen(map->line) - 1;
		if ((map_too_big(map) == false) && (map_too_tiny(map) == false) && (map_bad_format(map) == false))
		{
			ft_printf("\ninside size checker map->height = %d\n", map->height);
			ft_printf("inside size checker map->width = %d\n", map->width);
			ft_printf("inside size checker map->width (str) = %s\n", map->line);
			map->matrix = map_allocation(map->matrix, map->line, map->height);
			ft_printf("after alloc map_matrix[%d] = %s", map->height, map->matrix[map->height]);
			map->height++;
			map->size = map->height * map->width;
			map->line = ft_get_next_line(map->fd);
		}
		else
		{
			free(map->matrix);
			free(map->line);
			return (false);
			break ;
		}
	}
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
	
	map->matrix[map->height + 1] = '\0';
	return (true);
}

/* TODO why it doesn't recognize the last MAP CHAR in lastest height, if the map IS bad format???*/

bool	map_bad_format(t_map *map)
{
	if (map->height >= MIN_MAP_HEIGHT)
	{
		ft_printf("bad format map-line is = %s\n", map->line);
		ft_printf("bad format map->width (%d) map->height (%d) \n", map->width, map->height);
		ft_printf("bad format map->first_lenght = %d\n", map->first_lenght);
		ft_printf("bad format map_matrix-1[%d] = %s\n", map->height - 1, map->matrix[map->height - 1]);
		ft_printf("bad format map_matrix[%d] = %s\n", map->height, map->matrix[map->height]);
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
