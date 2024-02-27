/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_allocation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 19:24:16 by umeneses          #+#    #+#             */
/*   Updated: 2024/02/27 13:55:01 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**map_allocation(char **matrix, char *line, size_t size)
{
	size_t	index;
	char	**matrix_temp;
	int		y;
	
	index = 0;
	y = 0;
	if (!matrix)
		matrix = ft_calloc(2, sizeof(char *));
	if (!line || line[0] == '\0')
		matrix_temp[index] = NULL;
	else
		matrix_temp = start_alloc(matrix, matrix_temp, line, index, size, y);
	free_matrix(&matrix);
	return (matrix_temp);
}

char	**start_alloc(char **matrix, char **matrix_temp, char *line, \
						size_t	index, size_t size, int y)
{
	matrix_temp = ft_calloc(size + 2, sizeof(char *));
	if (!matrix_temp)
	{
		if (matrix)
			free_matrix(&matrix);
		ft_putendl_fd("\nMemory MAP allocation error.\n", STDOUT_FILENO);
		return (NULL);
	}
	while (index < size)
	{
		matrix_temp[index] = ft_strdup(matrix[index]);
		if (!matrix_temp[index] || (matrix_temp[index] == NULL))
		{
			free_matrix(&matrix_temp);
			return (NULL);
		}
		index++;
	}
	matrix_temp[index] = line;
	return (matrix_temp);
}
