/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:22:01 by umeneses          #+#    #+#             */
/*   Updated: 2024/01/23 10:53:15 by umeneses         ###   ########.fr       */
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
