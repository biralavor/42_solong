/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:46:04 by umeneses          #+#    #+#             */
/*   Updated: 2024/01/05 18:19:01 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SO_LONG_H
# define SO_LONG_H

# include "../libs/codam/include/MLX42/MLX42.h"
# include "../libs/libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

# define WIDTH 512
# define HEIGHT 512
# define BPP sizeof(int32_t)
# define GRAY_COLOR printf("\033[0;36m")
# define RESET_COLOR printf("\033[0m")

typedef struct s_player
{
	int	totalmoves;
}		t_player;

static mlx_image_t* image;
mlx_image_t*		cvs_img;
mlx_image_t*		ship_img;
mlx_texture_t*		ship_texture;

void	*ft_memset(void *str, int c, size_t size);

#endif