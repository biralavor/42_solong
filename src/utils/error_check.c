/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:22:01 by umeneses          #+#    #+#             */
/*   Updated: 2024/01/22 19:03:58 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_check(char **argv)
{
	size_t	extension_len;
	size_t	filename_len;
	char	extension_char;
	char	*extension_name;
	char	*filename;
	size_t	index;

	index = 0;
	filename_len = ft_strlen(argv[1]);
	filename = argv[1];
	ft_printf("inside function filename_len = %d\n", filename_len);
	ft_printf("inside function filename = %s\n", argv[1]);
	extension_name = ft_strnstr(argv[1], ".", filename_len);
	while (extension_name != '\0')
	{
		if (extension_name[index] == '.')
		{
			if (extension_name[++index] == 'b')
			{
				if (extension_name[++index] == 'e')
				{
					if (extension_name[++index] == 'r')
						break;
				}
			}
		}
		else
			ft_printf("\nstrRchar error\n");
	}
}

// change to boll