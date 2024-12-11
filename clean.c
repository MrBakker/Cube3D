/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   clean.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbakker <jbakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/11 18:41:25 by jbakker       #+#    #+#                 */
/*   Updated: 2024/12/11 18:54:51 by jbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	free_texture(t_cube3d *cube, t_texture *texture)
{
	if (!texture)
		return ;
	mlx_destroy_image(cube->window.mlx, texture->img);
	free(texture);
}

void	free_xpmgif(t_cube3d *cube, t_xpmgif *gif)
{
	int	i;

	if (!gif)
		return ;
	i = -1;
	while (++i < gif->frame_count && gif->frames && gif->frames[i])
		free_texture(cube, gif->frames[i]);
	free(gif->frames);
	free(gif);
}

void	free_map(t_map *map)
{
	int	i;

	i = -1;
	if (!map->map)
		return ;
	while (++i < map->map_height && map->map[i])
		free(map->map[i]);
	free(map->map);
}

void	destory_window(t_cube3d *cube3d)
{
	mlx_destroy_window(cube3d->window.mlx, cube3d->window.win);
	mlx_destroy_display(cube3d->window.mlx);
	free(cube3d->window.mlx);
}
