/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minimap.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbakker <jbakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/08 01:16:42 by jbakker       #+#    #+#                 */
/*   Updated: 2024/12/10 02:31:33 by jbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static int	get_map_color_representation(t_map *map, int x, int y)
{
	int	map_object;

	map_object = get_map_object(map, x, y);
	if (map_object == WALL)
		return (rgb_to_int(0, 0, 0));
	if (map_object == EMPTY)
		return (rgb_to_int(255, 255, 255));
	if (map_object == PLAYER_START_POS)
		return (rgb_to_int(245, 245, 245));
	return (rgb_to_int(252, 221, 215));
}

static void	draw_map(t_image *image, t_cube3d *cube)
{
	int	map_x;
	int	map_y;
	int	map_start_x;
	int	map_start_y;

	map_start_x = cube->player.x - (MINIMAP_SIZE / 2 * MINIMAP_SCALE);
	map_start_y = cube->player.y - (MINIMAP_SIZE / 2 * MINIMAP_SCALE);
	map_y = -1;
	while (++map_y < MINIMAP_SIZE)
	{
		map_x = -1;
		while (++map_x < MINIMAP_SIZE)
		{
			put_pixel(image, \
				MINIMAP_BORDER_OFFSET + MINIMAP_BORDER_SIZE + map_x, \
				MINIMAP_BORDER_OFFSET + MINIMAP_BORDER_SIZE + map_y, \
				get_map_color_representation(&cube->map, \
					map_start_x + map_x * MINIMAP_SCALE, \
					map_start_y + map_y * MINIMAP_SCALE));
		}
	}
}

static void	draw_border(t_image *image)
{
	int	x;
	int	y;

	x = -1;
	while (++x < MINIMAP_SIZE + MINIMAP_BORDER_SIZE * 2)
	{
		y = -1;
		while (++y < MINIMAP_SIZE + MINIMAP_BORDER_SIZE * 2)
		{
			if (x < MINIMAP_BORDER_SIZE || \
				x >= MINIMAP_SIZE + MINIMAP_BORDER_SIZE || \
				y < MINIMAP_BORDER_SIZE || \
				y >= MINIMAP_SIZE + MINIMAP_BORDER_SIZE)
				put_pixel(image, MINIMAP_BORDER_OFFSET + x, \
					MINIMAP_BORDER_OFFSET + y, rgb_to_int(79, 151, 255));
		}
	}
}

static void	draw_fov(t_image *image, t_cube3d *cube, t_ray *rays)
{
	int		i;
	double	end_x;
	double	end_y;

	i = -1;
	while (++i < cube->window.width && rays)
	{
		if (!rays[i].is_valid)
			continue ;
		end_x = (rays[i].x_pos - rays[i].origin_x) / MINIMAP_SCALE + \
			MINIMAP_BORDER_OFFSET + MINIMAP_BORDER_SIZE + MINIMAP_SIZE / 2;
		end_y = (rays[i].y_pos - rays[i].origin_y) / MINIMAP_SCALE + \
			MINIMAP_BORDER_OFFSET + MINIMAP_BORDER_SIZE + MINIMAP_SIZE / 2;
		draw_line(image, \
			(t_line){{MINIMAP_BORDER_OFFSET + MINIMAP_BORDER_SIZE + \
			MINIMAP_SIZE / 2, MINIMAP_BORDER_OFFSET + MINIMAP_BORDER_SIZE + \
			MINIMAP_SIZE / 2}, {end_x, end_y}, rgb_to_int(255, 0, 0)}, NULL, \
			is_in_bounds_of_minimap);
	}
	draw_circle(image, (t_point){MINIMAP_BORDER_OFFSET + MINIMAP_BORDER_SIZE + \
		MINIMAP_SIZE / 2, MINIMAP_BORDER_OFFSET + MINIMAP_BORDER_SIZE + \
		MINIMAP_SIZE / 2}, MINIMAP_PLAYER_SIZE, rgb_to_int(0, 255, 0));
}

void	draw_minimap(t_image *image, t_cube3d *cube, t_ray *rays)
{
	if (!MINIMAP)
		return ;
	draw_map(image, cube);
	draw_fov(image, cube, rays);
	draw_border(image);
}
