/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbakker <jbakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/07 17:54:04 by jbakker       #+#    #+#                 */
/*   Updated: 2024/12/11 13:15:24 by jbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	get_map_object(t_map *map, double x, double y)
{
	double	coord_x;
	double	coord_y;

	if (x == NAN || y == NAN || x == INFINITY || y == INFINITY || \
		x == -INFINITY || y == -INFINITY)
		return (UNKNOWN);
	coord_x = x / (double)TILE_SIZE;
	coord_y = y / (double)TILE_SIZE;
	if (coord_x < 0 || (int)coord_x >= map->map_width || coord_y < 0 || \
		(int)coord_y >= map->map_height)
		return (UNKNOWN);
	return (map->map[(int)coord_y][(int)coord_x]);
}

void	set_map_object(t_map *map, double x, double y, int object)
{
	double	coord_x;
	double	coord_y;

	if (x == NAN || y == NAN || x == INFINITY || y == INFINITY || \
		x == -INFINITY || y == -INFINITY)
		return ;
	coord_x = x / (double)TILE_SIZE;
	coord_y = y / (double)TILE_SIZE;
	if (coord_x < 0 || (int)coord_x >= map->map_width || coord_y < 0 || \
		(int)coord_y >= map->map_height)
		return ;
	map->map[(int)coord_y][(int)coord_x] = object;
}

int	is_valid_map_position(t_map *map, int x, int y)
{
	return (x >= 0 && x < map->map_width * TILE_SIZE && \
		y >= 0 && y < map->map_height * TILE_SIZE);
}

int	is_in_bounds_of_minimap(int x, int y, void *unused)
{
	(void)unused;
	return (x >= MINIMAP_BORDER_OFFSET + MINIMAP_BORDER_SIZE && \
		x < MINIMAP_SIZE + MINIMAP_BORDER_OFFSET + MINIMAP_BORDER_SIZE && \
		y >= MINIMAP_BORDER_OFFSET + MINIMAP_BORDER_SIZE && \
		y < MINIMAP_SIZE + MINIMAP_BORDER_OFFSET + MINIMAP_BORDER_SIZE);
}
