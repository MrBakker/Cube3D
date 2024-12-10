/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbakker <jbakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/06 14:20:16 by jbakker       #+#    #+#                 */
/*   Updated: 2024/12/10 02:35:54 by jbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	free_map(t_map *map)
{
	int	i;

	i = -1;
	while (++i < map->map_height)
		free(map->map[i]);
	free(map->map);
}

void	destroy_textures(t_cube3d *cube3d)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (cube3d->map.textures[i])
		{
			mlx_destroy_image(cube3d->window.mlx, cube3d->map.textures[i]->img);
			free(cube3d->map.textures[i]);
		}
	}
}

void	destory_window(t_cube3d *cube3d)
{
	mlx_destroy_window(cube3d->window.mlx, cube3d->window.win);
	mlx_destroy_display(cube3d->window.mlx);
	free(cube3d->window.mlx);
}

int	big_cube_close(t_cube3d *cube3d)
{
	if (!cube3d)
		exit(0);
	destroy_textures(cube3d);
	destory_window(cube3d);
	free_map(&cube3d->map);
	ft_printf("%sClean exit; cya!%s\n", GREEN, DEFAULT);
	exit(0);
}
