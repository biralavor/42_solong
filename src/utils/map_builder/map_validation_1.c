/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:38:49 by umeneses          #+#    #+#             */
/*   Updated: 2024/01/26 15:44:17 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	map_extension_check(char **argv)
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
}

bool	map_size_check(t_map *map)
{
	map->width = 0;
	map->height = 0;
	map->bad_format = false;
	map->line = "";
	while (map->line)
	{
		map->line = ft_get_next_line(map->fd);
		if (map->line == (void *)0)
			break ;
		if (map->width == 0)
			map->width = (ft_strlen(map->line) - 1);
		if ((map->width != ft_strlen(map->line) - 1) && \
				map->line[map->width] != '\0')
			map->bad_format = true;
		map->height++;
		free(map->line);
	}
	if (map->bad_format == true)
	{
		err_msg_free(1, "\nError\nMap requirements doesn't match.\n", 0, NULL);
		return (false);
	}
	if (map->width > MAX_MAP_WIDTH || map->height > MAX_MAP_HEIGHT)
	{
		err_msg_free(2, "\nError\nMap is too big.\n", 0, NULL);
		return (false);
	}
	map->size = map->height * map->width;
	ft_printf("map->size = %d\n", map->size);
	ft_printf("map->width = %d\n", map->width);
	ft_printf("map->height = %d\n", map->height);
	close(map->fd);
	return (true);
}

bool	has_player(char *line)
{
	char	*tofind;
	char	*result;

	ft_printf("has_player map.line = %s\n", line);
	tofind = "P";
	result = ft_strnstr(line, tofind, ft_strlen(line));
	if (result == tofind)
		return (true);
	return (false);
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
