/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_allocation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 19:24:16 by umeneses          #+#    #+#             */
/*   Updated: 2024/02/29 11:54:13 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**map_allocation(char **matrix, char *line, size_t size)
{
	char	**matrix_tmp;

	if (!matrix)
		matrix = ft_calloc(2, sizeof(char *));
	if (!line || line[0] == '\0')
		matrix_tmp[0] = NULL;
	else
		matrix_tmp = alloc_init(matrix, matrix_tmp, line, size);
	free_matrix(matrix);
	return (matrix_tmp);
}

char	**alloc_init(char **matrix, char **matrix_tmp, char *line, size_t size)
{
	size_t	index;

	index = 0;
	matrix_tmp = ft_calloc(size + 2, sizeof(char *));
	if (!matrix_tmp)
	{
		if (matrix)
			free_matrix(matrix);
		ft_putendl_fd("\nMemory MAP allocation error.\n", STDOUT_FILENO);
		return (NULL);
	}
	while (index < size)
	{
		matrix_tmp[index] = ft_strdup(matrix[index]);
		if (!matrix_tmp[index] || (matrix_tmp[index] == NULL))
		{
			free_matrix(matrix_tmp);
			return (NULL);
		}
		index++;
	}
	matrix_tmp[index] = line;
	return (matrix_tmp);
}
