/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_allocation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 19:24:16 by umeneses          #+#    #+#             */
/*   Updated: 2024/01/30 15:00:57 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**map_allocation(char **matrix, char *line, size_t size)
{
	size_t	index;
	char	**matrix_temp;
	
	index = 0;	
	matrix_temp = ft_calloc(size + 2, sizeof(char *));
	if (!matrix_temp)
	{
		ft_putendl_fd("\nMemory Map allocation error.\n", STDOUT_FILENO);
		free(matrix);
	}
	if (!matrix)
		matrix = ft_calloc(2, sizeof(char *));
	else
	{
		while (index < size)
		{
			matrix_temp[index] = ft_strdup(matrix[index]);
			index++;
		}
	}
	matrix_temp[index] = line;
	free(matrix);
	return (matrix_temp);
}
