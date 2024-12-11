/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   floor_ceiling.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbakker <jbakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/11 14:55:56 by jbakker       #+#    #+#                 */
/*   Updated: 2024/12/11 14:56:20 by jbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	draw_ceiling(t_image *image, t_cube3d *cube, int max_y, int x)
{
	int	y;

	y = -1;
	while (++y < max_y)
		put_pixel(image, x, y, cube->map.ceiling_color);
}

void	draw_floor(t_image *image, t_cube3d *cube, int min_y, int x)
{
	int	y;

	y = min_y - 1;
	while (++y < cube->window.height)
		put_pixel(image, x, y, cube->map.floor_color);
}
