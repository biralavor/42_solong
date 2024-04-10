/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:38:49 by umeneses          #+#    #+#             */
/*   Updated: 2024/04/10 17:44:28 by umeneses         ###   ########.fr       */
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
	if (extension_name != (void *)0)
	{
		extension_len = ft_strlen(extension_name);
		while (extension_name != (void *)0)
		{
			if (extension_len == 4)
				if ((extension_name[index] == '.')
					&& (extension_name[++index] == 'b')
					&& (extension_name[++index] == 'e')
					&& (extension_name[++index] == 'r'))
					return (true);
			break ;
		}
	}
	ft_putendl_fd("\nError.\nYour MAP file extension is invalid."
		"\nIt needs to be '.ber'\n", STDOUT_FILENO);
	return (false);
}

bool	map_too_tiny(t_map *map)
{
	int32_t	index;

	index = -1;
	map->linebreak_index = 0;
	while (map->buffer[++index])
	{
		if (map->buffer[index] == '\n')
		{
			if (index < MIN_MAP_WIDTH)
			{
				ft_putendl_fd("\nError.\nYour Map is too tiny.", STDOUT_FILENO);
				ft_printf("MIN_MAP_WIDTH = %i\n\n", MIN_MAP_WIDTH);
				return (true);
			}
			map->linebreak_index++;
		}
		if ((index == map->bytes_read - 1)
			&& (map->linebreak_index + 1 < MIN_MAP_HEIGHT))
		{
			ft_putendl_fd("\nError.\nYour Map is too tiny.", STDOUT_FILENO);
			ft_printf("MIN_MAP_HEIGHT = %i\n\n", MIN_MAP_HEIGHT);
			return (true);
		}
	}
	return (false);
}

bool	map_too_big(t_map *map)
{
	int32_t	index;

	index = -1;
	while (map->buffer[++index] != '\n')
	{
		if (index > MAX_MAP_WIDTH)
		{
			ft_putendl_fd("\nError\nYour Map is too big.",
				STDOUT_FILENO);
			ft_printf("MAX_MAP_WIDTH = %i\n\n", MAX_MAP_WIDTH);
			return (true);
		}
		if (map->linebreak_index > MAX_MAP_HEIGHT)
		{
			ft_putendl_fd("\nError\nYour MAP is too big.", STDOUT_FILENO);
			ft_printf("MAX_MAP_HEIGHT = %i\n\n", MAX_MAP_HEIGHT);
			return (true);
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
