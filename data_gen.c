/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   data_gen.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbakker <jbakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/06 17:20:18 by jbakker       #+#    #+#                 */
/*   Updated: 2024/12/10 00:39:45 by jbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

// Temp function to create a test map
void	create_test_map(t_cube3d *cube3d)
{
	cube3d->map.textures[NORTH] = load_texture_from_name(cube3d, "textures/north.xpm");
	cube3d->map.textures[EAST] = load_texture_from_name(cube3d, "textures/east.xpm");
	cube3d->map.textures[SOUTH] = load_texture_from_name(cube3d, "textures/south.xpm");
	cube3d->map.textures[WEST] = load_texture_from_name(cube3d, "textures/west.xpm");
	const int grid_size = 10;
	int map[10][10] = {
		{2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
		{2, 1, 1, 1, 2, 2, 1, 1, 1, 2},
		{2, 2, 2, 1, 1, 1, 4, 1, 1, 2},
		{2, 1, 2, 1, 2, 2, 1, 1, 1, 2},
		{2, 1, 2, 1, 1, 2, 1, 1, 1, 2},
		{2, 1, 2, 2, 1, 1, 1, 2, 1, 2},
		{2, 1, 1, 2, 1, 2, 2, 2, 1, 2},
		{2, 2, 1, 1, 1, 1, 2, 2, 1, 2},
		{2, 1, 1, 2, 2, 1, 1, 1, 1, 2},
		{2, 2, 2, 2, 2, 2, 2, 2, 2, 2}
	};
	int **m = (int **)malloc(sizeof(int *) * grid_size);
	int i = -1;
	int j = -1;
	for (i = 0; i < grid_size; i++)
	{
		m[i] = (int *)malloc(sizeof(int) * grid_size);
		for (j = 0; j < grid_size; j++)
		{
			m[i][j] = map[i][j];
			if (m[i][j] == PLAYER_START_POS)
			{
				cube3d->player.x = j * TILE_SIZE + TILE_SIZE / 2;
				cube3d->player.y = i * TILE_SIZE + TILE_SIZE / 2;
			}
		}
	}
	cube3d->player.dir = -HALF_PI;
	cube3d->map.map = m;
	cube3d->map.floor_color = rgb_to_int(50, 0, 0);
	cube3d->map.ceiling_color = rgb_to_int(0, 0, 50);
	cube3d->map.map_width = grid_size;
	cube3d->map.map_height = grid_size;
}
