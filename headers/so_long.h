/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:46:04 by umeneses          #+#    #+#             */
/*   Updated: 2024/04/12 16:27:10 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libs/libft/libft.h"
# include "../libs/codam/include/MLX42/MLX42.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdint.h>
# include <stdbool.h>

# define WIDTH 1024
# define HEIGHT 720
# define PIXEL_SIZE 32
# define MAX_MAP_WIDTH 30
# define MAX_MAP_HEIGHT 30
# define MIN_MAP_WIDTH 5
# define MIN_MAP_HEIGHT 5
/* Map definitions */
# define SPACESHIP "./textures/32px_ref-space-shuttle.png"
# define SPACEFIELD "./textures/32px_ref-background.png"
# define DEATH "./textures/32px_blackhole-portal.png"
# define BOUNDARY "./textures/32px_asteroid.png"
# define ASTRONAUT "./textures/32px_astronaut.png"
# define EARTH "./textures/32px_earth.png"
/* Sprite definitions */

typedef struct s_userdata
{
	int32_t			totalmoves;
	int32_t			y_pos;
	int32_t			x_pos;
	int32_t			future_y_pos;
	int32_t			future_x_pos;
	int32_t			totalcoins;
}					t_userdata;

typedef struct s_sprite
{
	mlx_texture_t	*back_tt;
	mlx_image_t		*back;
	mlx_texture_t	*border_tt;
	mlx_image_t		*border;
	mlx_texture_t	*player_tt;
	mlx_image_t		*player;
	mlx_texture_t	*coin_tt;
	mlx_image_t		*coin;
	mlx_texture_t	*exit_tt;
	mlx_image_t		*exit;
}					t_sprite;

typedef struct s_map
{
	char			**matrix;
	int32_t			fd;
	char			*buffer;
	int32_t			bytes_read;
	int32_t			linebreak_index;
	int32_t			index;
	int32_t			width;
	int32_t			height;
	int32_t			first_lenght;
	int				size;
	char			*line;
	int32_t			coin_index;
	int32_t			border_index;
	int32_t			read_y;
	int32_t			read_x;
}					t_map;

typedef struct s_game
{
	t_map			*map;
	t_sprite		*sprites;
	t_userdata		*userdata;
	mlx_t			*mlx;
	mlx_key_data_t	*keydata;
}					t_game;


t_game	*structures_init(t_game *game);
bool	map_extension_approved(char **argv);
/* main functions */

bool	map_init(char **argv, t_game *game);
bool	map_opener(char **argv, t_map *map);
bool	map_reader(char **argv, t_map *map);
/* map init functions */

bool	map_too_tiny(t_map *map);
bool	map_too_big(t_map *map);
/* map init validation functions */

bool	map_size_approved(t_map *map);
bool	map_bad_format(t_map *map);
char	*gnl_init(t_map *map);
/* map init validation of size and gnl functions */

char	**map_allocation(char **matrix, char *line, size_t size);
char	**alloc_init(char **matrix, char **matrix_tmp, char *line, size_t size);
/* map gnl init functions */

bool	map_contents_checker(t_map *map);
bool	has_walls(t_map *map);
bool	has_specific_char(t_map *map, char tofind, int limiter);
bool	is_char_locked(t_map *map);
bool	has_illegal_char(t_map *map);
void	how_many_walls(t_map *map);
/* map init validation of contents functions */

void	matrix_printer(t_map *map);
void	game_init(t_game *game);
void	free_all_mlx_usage(t_game *game);
void	free_map(t_map *map);
void	free_matrix(char **matrix);
/* game init functions */

bool	loading_png(char *imagepath, mlx_texture_t **texture);
bool	preparing_image(mlx_t *mlx, mlx_texture_t *texture, mlx_image_t **img);
void	parse_imgtomap(t_map *map, char toparse, mlx_t *mlx, mlx_image_t *img);
void	parse_backtomap(t_map *map, char toparse, mlx_t *mlx, mlx_image_t *img);
void	render_fixedsprites(mlx_t *mlx, t_sprite *sprites, t_map *map);
void	render_movingsprites(mlx_t *mlx, t_sprite *sprites, t_map *map);
/* game builder functions - parsing map into graphic */

void	frame_update(mlx_key_data_t key, t_game *game);
void	coins_update(t_game *game);
void	show_exit(t_game *game);
void	end_game(t_game *game);
/* gameplay functions */

void	keyb_wasd_arrow(mlx_key_data_t key, t_game *game);
void	user_counter(char *key, t_game *game);
void	coins_counter(t_game *game);
/* game hooks functions */

void	future_player_pos(mlx_key_data_t key, t_game *game);
bool	is_wall(mlx_key_data_t key, t_game *game);
/* game rules functions */

#endif