/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init_validation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:38:49 by umeneses          #+#    #+#             */
/*   Updated: 2024/04/12 16:15:10 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
