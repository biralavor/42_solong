/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:46:04 by umeneses          #+#    #+#             */
/*   Updated: 2024/01/30 15:01:11 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SO_LONG_H
# define SO_LONG_H

# include "../libs/libft/libft.h"
# include "../libs/codam/include/MLX42/MLX42.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdint.h>
# include <stdbool.h>

# define WIDTH 512
# define HEIGHT 512
# define MAX_MAP_WIDTH 30
# define MAX_MAP_HEIGHT 30
# define MIN_MAP_HEIGHT 3
/* Map definitions */
# define BPP sizeof(int32_t)
# define BUFFERSIZE 30
/* MLX definitions */
# define SPACESHIP "./textures/ref-space-shuttle-redux.png"
# define SPACEFIELD "./textures/ref-background-hsl-70.png"
# define DEATH "./textures/ref-death-icon-50.png"
# define BOUNDARY "./textures/asteroid-35px-hsl.png"
# define ASTRONAUT "./textures/astronaut-38px.png"
# define EARTH "./textures/earth-40px.png"
/* Sprite definitions */

typedef struct s_map
{
	char			**matrix;
	int32_t			fd;
	int32_t			index;
	int32_t			width;
	int32_t			height;
	int				size;
	char			*line;
	bool			bad_format;
}					t_map;

typedef struct s_sprite
{
	mlx_texture_t	*spr_texture;
	mlx_image_t		*spr_img;
}					t_sprite;

typedef struct s_game
{
	t_map			*map;
	mlx_t			*mlx;
	mlx_image_t		*play_img;
	mlx_image_t		*cvs_img;
	mlx_key_data_t	*keydata;
	int				totalmoves;
	void			*window;
	int				img_w;
	int				img_h;
}					t_game;

void	*ft_memset(void *str, int c, size_t size);
void	load_texture(t_game *game);

bool	*map_opener(char **argv, t_map *map);
bool	map_reader(t_map *map);
bool	*map_build_matrix(char **argv, t_map *map);
char	**map_allocation(char **matrix, char *line, size_t size);
/* map funtions */

bool	map_extension_checker(char **argv);
bool	*map_size_checker(t_map *map);
bool	map_bad_format(t_map *map);
bool	map_too_big(t_map *map);
bool	map_too_tiny(t_map *map);
void	err_msg_free(int i, char *msg, int stage, t_map *map);
void	free_map(t_map *map);
/* validation funtions */

bool	*has_player(t_map *map);
bool	has_wall(char *line);
/* validation map items */

#endif