/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:38:49 by umeneses          #+#    #+#             */
/*   Updated: 2024/04/06 16:18:15 by umeneses         ###   ########.fr       */
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
		break ;
	}
	ft_putendl_fd("\nError.\nYour MAP file extension is invalid.\n"
					"It needs to be '.ber'\n", STDOUT_FILENO);
	return (false);
}

bool	map_too_tiny(t_map *map)
{
	int32_t	index;

	index = -1;
	while (++index < (map->bytes_read))
	{
		if (map->buffer[index] == '\n')
		{
			map->linebreak_index++;
			if (index < MIN_MAP_WIDTH)
			{
				ft_putendl_fd("\nError\nYour Map is too tiny.", STDOUT_FILENO);
				return (true);
				break ;
			}
		}
	}
	if (map->linebreak_index + 1 < MIN_MAP_HEIGHT)
	{
		ft_putendl_fd("\nError\nYour Map is too tiny.", STDOUT_FILENO);
		return (true);
	}
	return (false);
}

bool	map_too_big(t_map *map)
{
	int32_t	index;

	if (map->linebreak_index + 1 > MAX_MAP_HEIGHT)
	{
		ft_putendl_fd("\nError\nYour MAP is too big.", STDOUT_FILENO);
		return (true);
	}
	index = 0;
	while (map->buffer[index] != '\n')
	{
		index++;
		if (map->buffer[index] == '\0')
		{
			if ((index + 1) > MAX_MAP_WIDTH - 1)
			{
				ft_putendl_fd("\nError\n1---Your Map is too big.", STDOUT_FILENO);
				return (true);
			}
		}
	}
	return (false);
}

bool	map_bad_format(t_map *map)
{
	if (map->height >= 1)
	{
		if (map->first_lenght != map->width)
		{
			ft_putendl_fd("\nError\nYour MAP isn't rectangular.", \
							STDOUT_FILENO);
			return (true);
		}
	}
	return (false);
}

bool	map_size_approved(t_map *map)
{
	char	*toremove;
	char	*gnl_temp;

	toremove = "\n";
	gnl_temp = ft_get_next_line(map->fd);
	map->line = ft_strtrim(gnl_temp, toremove);
	free (gnl_temp);
	if (map->line != NULL)
		map->first_lenght = ft_strlen(map->line) - 1;
	while (map->line != NULL)
	{
		map->width = ft_strlen(map->line) - 1;
		if (map_bad_format(map) == false)
		{
			map->matrix = map_allocation(map->matrix, map->line, map->height);
			map->height++;
			map->size = map->height * map->width;
			gnl_temp = ft_get_next_line(map->fd);
			map->line = ft_strtrim(gnl_temp, toremove);
			free (gnl_temp);
		}
		else
		{
			free(map->line);
			return (close(map->fd), false);
			break ;
		}
	}
	free(map->line);
	close(map->fd);
	return (true);
}
