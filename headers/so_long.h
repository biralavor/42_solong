/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:46:04 by umeneses          #+#    #+#             */
/*   Updated: 2024/01/18 16:58:12 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SO_LONG_H
# define SO_LONG_H

# include "../libs/libft/libft.h"
# include "../libs/codam/include/MLX42/MLX42.h"
# include "../libs/gnl/get_next_line.h"
# include "../libs/ft_printf/ft_printf.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdarg.h>
# include <stdint.h>
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
# define COLOR_RED "\033[0;31m"
// # define COLOR_GREEN ft_printf("\033[0;32m")
// # define COLOR_YELLOW ft_printf("\033[0;33m")
// # define COLOR_PURPLE ft_printf("\033[0;35m")
// # define COLOR_CYAN ft_printf("\033[0;36m")
// # define COLOR_RESET ft_printf("\033[0m")

typedef struct s_game
{
	mlx_t			*mlx;
	mlx_image_t		*play_img;
	mlx_image_t		*cvs_img;
	mlx_key_data_t	*keydata;
	int				totalmoves;
	void			*window;
	int				img_w;
	int				img_h;
	char			*selected_map;
	char			**map;
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
char	*read_map(int32_t fd);
char	**map_builder(int32_t fd, t_game *game);


#endif