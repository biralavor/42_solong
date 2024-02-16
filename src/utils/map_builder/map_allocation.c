/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_allocation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bira <bira@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 19:24:16 by umeneses          #+#    #+#             */
/*   Updated: 2024/02/16 13:53:11 by bira             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**map_allocation(char **matrix, char *line, size_t size)
{
	size_t	index;
	char	**matrix_temp;
	
	index = 0;
	if (!matrix)
		matrix = ft_calloc(2, sizeof(char *));
	if (!line || line[0] == '\0' || line == "")
		matrix_temp[index] = NULL;
	else
	{
		matrix_temp = ft_calloc(size + 2, sizeof(char *));
		if (!matrix_temp)
		{
			if (matrix)
				free(matrix);	
			ft_putendl_fd("\nMemory Map allocation error.\n", STDOUT_FILENO);
			return (NULL);
		}
		while (index < size)
		{
			matrix_temp[index] = ft_strdup(matrix[index]);
			if (!matrix_temp[index] || (matrix_temp[index] == NULL))
			{
				free (matrix_temp);
				return (NULL);
			}
			index++;
		}
		matrix_temp[index] = line;
	}
	free(matrix);
	return (matrix_temp);
}
