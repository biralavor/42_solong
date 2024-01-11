/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:46:04 by umeneses          #+#    #+#             */
/*   Updated: 2024/01/11 11:11:59 by umeneses         ###   ########.fr       */
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
# define BUFFERSIZE 30
# define SPACESHIP "./textures/ref-space-shuttle-redux.png"
# define SPACEFIELD "./textures/ref-background-hsl-70.png"
# define DEATH "./textures/ref-death-icon-50.png"
# define BOUNDARY "./textures/asteroid-35px-hsl.png"
# define ASTRONAUT "./textures/astronaut-38px.png"
# define EARTH "./textures/earth-40px.png"
# define GRAY_COLOR printf("\033[0;36m")
# define RESET_COLOR printf("\033[0m")

typedef struct s_game
{
	mlx_t			*mlx;
	mlx_image_t		*play_img;
	mlx_image_t		*cvs_img;
	int				totalmoves;
	void			*window;
	int				img_w;
	int				img_h;
	mlx_texture_t	*ship;
	mlx_image_t		*ship_img;
	mlx_texture_t	*background;
	mlx_image_t		*back_img;
	mlx_texture_t	*enemy;
	mlx_image_t		*enemy_img;
	mlx_texture_t	*border;
	mlx_image_t		*border_img;
	mlx_texture_t	*astro;
	mlx_image_t		*astro_img;
	mlx_texture_t	*earth;
	mlx_image_t		*earth_img;
}					t_game;


void	*ft_memset(void *str, int c, size_t size);
void	load_texture(t_game *game);

#endif