/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:22:01 by umeneses          #+#    #+#             */
/*   Updated: 2024/02/27 13:54:20 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	wall_err_msg(void)
{
	ft_putendl_fd("\nError\nYour MAP has a breach on the Wall!\n",
		STDOUT_FILENO);
	return (0);
}
