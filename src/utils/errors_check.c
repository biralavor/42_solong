/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:22:01 by umeneses          #+#    #+#             */
/*   Updated: 2024/01/25 17:51:10 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	err_msg_free(int i, char *msg, int stage, t_map *map)
{
	if (stage >= 1)
	{
		free_map(map);
		if (stage == 2)
		{
			/* free mlx + all mlx used hooks */
		}
	}
	ft_printf("%s", msg);
	exit (i);
}
