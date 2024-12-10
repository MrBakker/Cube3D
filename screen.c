/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   screen.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbakker <jbakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/07 18:25:04 by jbakker       #+#    #+#                 */
/*   Updated: 2024/12/10 01:45:49 by jbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	is_in_bounds_of_screen(int x, int y, void *window)
{
	t_window	*win;

	win = (t_window *)window;
	return (x >= 0 && x < win->width && y >= 0 && y < win->height);
}

void	put_pixel(t_image *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_circle(t_image *data, t_point p, int r, int color)
{
	int		i;
	int		j;
	double	dist;

	i = 0;
	while (i < 2 * r)
	{
		j = 0;
		while (j < 2 * r)
		{
			dist = sqrt((r - i) * (r - i) + (r - j) * (r - j));
			if (dist < r)
				put_pixel(data, p.x - r + i, p.y - r + j, color);
			j++;
		}
		i++;
	}
}

void	draw_line(t_image *image, t_line line, \
	void *payload, int (*bound_check)(int, int, void *))
{
	double	dx;
	double	dy;
	double	c;
	double	i;
	t_point	p;

	dx = line.p2.x - line.p1.x;
	dy = line.p2.y - line.p1.y;
	p = (t_point){line.p1.x, line.p1.y};
	c = sqrt(dx * dx + dy * dy);
	i = 0;
	while (i++ < c)
	{
		if (bound_check(p.x, p.y, payload))
			put_pixel(image, p.x, p.y, line.color);
		p.x += dx / c;
		p.y += dy / c;
	}
}

void	draw_ray_2d(t_image *image, t_ray *ray, t_window *window)
{
	draw_line(image, \
		(t_line){{ray->origin_x, ray->origin_y}, {ray->x_pos, ray->y_pos}, \
		rgb_to_int(255, 0, 0)}, window, is_in_bounds_of_screen);
	draw_circle(image, (t_point){ray->x_pos, ray->y_pos}, \
		3, rgb_to_int(0, 255, 0));
}
