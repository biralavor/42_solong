/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading_images.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:35:34 by umeneses          #+#    #+#             */
/*   Updated: 2024/04/05 10:40:19 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	loading_png(char *imagepath, mlx_texture_t **texture)
{
	*texture = mlx_load_png(imagepath);
	if (!texture || texture == NULL)
		return (false);
	return (true);
}

bool	preparing_image(mlx_t *mlx, mlx_texture_t *texture, mlx_image_t **img)
{
	*img = mlx_texture_to_image(mlx, texture);
	if (!img || img == NULL)
		return (false);
	return (true);
}

void	render_fixedsprites(mlx_t *mlx, t_sprite *sprites, t_map *map)
{
	if (loading_png(SPACEFIELD, &sprites->back_tt)
		&& preparing_image(mlx, sprites->back_tt, &sprites->back)
		&& loading_png(BOUNDARY, &sprites->border_tt)
		&& preparing_image(mlx, sprites->border_tt, &sprites->border)
		&& loading_png(EARTH, &sprites->exit_tt)
		&& preparing_image(mlx, sprites->exit_tt, &sprites->exit))
		{
			parse_imgtomap(map, 'b', mlx, sprites->back);
			parse_imgtomap(map, '1', mlx, sprites->border);
			parse_imgtomap(map, 'E', mlx, sprites->exit);
		}
	else
		{
			ft_putendl_fd("Fixed Sprites didn't load correctly.\n", STDOUT_FILENO);
			return;
		}
	sprites->exit->instances[0].enabled = false;
}

void	render_movingsprites(mlx_t *mlx, t_sprite *sprites, t_map *map)
{
	if (loading_png(SPACESHIP, &sprites->player_tt)
		&& preparing_image(mlx, sprites->player_tt, &sprites->player)
		&& loading_png(ASTRONAUT, &sprites->coin_tt)
		&& preparing_image(mlx, sprites->coin_tt, &sprites->coin))
		{
			parse_imgtomap(map, 'P', mlx, sprites->player);
			parse_imgtomap(map, 'C', mlx, sprites->coin);
		}
	else
		{
			ft_putendl_fd("Moving Sprites didn't load correctly.\n", STDOUT_FILENO);
			return;
		}
}
