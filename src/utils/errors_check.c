/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:22:01 by umeneses          #+#    #+#             */
/*   Updated: 2024/01/24 17:26:52 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	map_extension_check(char **argv)
{
	size_t	extension_len;
	size_t	filename_len;
	char	*extension_name;
	size_t	index;

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

void	map_size_check(t_map map)
{
	map.index = 0;
	map.width = 0;
	map.height = 0;
	map.bad_format = false;
	map.line = "";
	ft_printf("\ninside MAP SIZE CHECK:\n");
	while (map.line)
	{
		ft_printf(COLOR_CYAN);
		map.line = ft_get_next_line(map.fd);
		if (map.line == (void *)0)
			break ;
		ft_printf(COLOR_PURPLE);
		ft_printf("GNL SIZE CHECK %i = ", map.index);
		ft_printf("%s", map.line);
		if (map.width == 0)
			map.width = ft_strlen(map.line) - 1;
		ft_printf("map.width = %d, map.height = %d, map.line = %d\n", map.width, map.height, ft_strlen(map.line));
		if (map.width != ft_strlen(map.line) && map.line[map.height] != '\0')
		{
			map.bad_format = true;
		}
		map.height++;
		map.index++;
		free(map.line);
	}
	if (map.bad_format == true)
		err_msg_free(1, "\nError. Map requirements doesn't match.\n", 0, NULL);
	if (map.height > 30 || map.width > 30)
		err_msg_free(2, "\nError\nMap it too big.\n", 0, NULL);
	map.size = map.height * map.width;
	close(map.fd);
}

void	err_msg_free(int i, char *msg, int stage, t_game *game)
{
	if (stage >= 1)
	{
		free_map(game->map);
		if (stage == 2)
		{
			/* free mlx + all mlx used hooks */
		}
	}
	ft_printf("%s", msg);
	exit (i);
}