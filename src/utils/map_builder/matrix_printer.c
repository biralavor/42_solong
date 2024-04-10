/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_printer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:56:35 by umeneses          #+#    #+#             */
/*   Updated: 2024/04/10 19:30:53 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	matrix_printer(t_map *map)
{
	int32_t	y;

	y = -1;
	ft_printf("\nThis is your MAP:\n");
	while (++y <= map->height - 1)
		ft_printf("%s\n", map->matrix[y]);
}
