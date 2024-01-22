/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:22:01 by umeneses          #+#    #+#             */
/*   Updated: 2024/01/22 18:25:49 by umeneses         ###   ########.fr       */
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
	ft_printf("extension_name pos%d ANTES WHILE = %c\n", index, extension_name[index]);
	while (extension_name != '\0')
	{
		if (extension_name[index] == '.')
		{
			ft_printf("extension_name pos%d = %c\n", index, extension_name[index]);
			index++;
			if (extension_name[index] == 'b')
			{
				ft_printf("extension_name pos%d = %c\n", index, extension_name[index]);
				index++;
				if (extension_name[index] == 'e')
				{
					ft_printf("extension_name pos%d = %c\n", index, extension_name[index]);
					index++;
					if (extension_name[index] == 'r')
					{
						ft_printf("extension_name pos%d = %c\n", index, extension_name[index]);
						break;
					}
				}
			}
		}
		else
			ft_printf("\nstrRchar error\n");
	}
	
	
}

// char	*ft_strnstr(const char *big, const char *tofind, size_t len)