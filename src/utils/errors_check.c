/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bira <bira@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:22:01 by umeneses          #+#    #+#             */
/*   Updated: 2024/02/07 08:44:35 by bira             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	wall_err_msg(void)
{
	ft_putendl_fd("\nError\nYour MAP has a breach on the Wall!\n", STDOUT_FILENO);
	exit;
	return (0);
}

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
