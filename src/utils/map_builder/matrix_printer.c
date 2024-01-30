/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_printer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:56:35 by umeneses          #+#    #+#             */
/*   Updated: 2024/01/30 17:02:02 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	matrix_printer(t_map *map)
{
	int32_t x = 0;
	while (x <= map->height - 1)
	{
		int32_t	y = 0;
		while (++y <= map->width)
			ft_printf("%c", map->matrix[x][y]);
		x++;
	}
}