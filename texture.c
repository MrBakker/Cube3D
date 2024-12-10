/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   texture.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbakker <jbakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/06 16:25:43 by jbakker       #+#    #+#                 */
/*   Updated: 2024/12/10 02:43:21 by jbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

t_texture	*load_texture_from_name(t_cube3d *cube3d, char *name)
{
	t_texture	*texture;

	texture = malloc(sizeof(t_texture));
	if (!texture)
		return (NULL);
	texture->path = name;
	if (ft_endswith(name, ".xpm"))
		texture->img = mlx_xpm_file_to_image(cube3d->window.mlx, \
			name, &texture->width, &texture->height);
	else
		return (free(texture), NULL);
	if (!texture->img)
		return (free(texture), NULL);
	texture->addr = mlx_get_data_addr(texture->img, &texture->bits_per_pixel, \
		&texture->line_length, &texture->endian);
	return (texture);
}

static int	get_texture_color(t_texture *texture, double x, double y)
{
	char	*dst;

	dst = texture->addr + (int)((int)y * texture->line_length + \
		(int)x * (texture->bits_per_pixel / 8));
	return (*(int *)dst);
}

static void	draw_ceiling(t_image *image, t_cube3d *cube, int max_y, int x)
{
	int	y;

	y = -1;
	while (++y < max_y)
		put_pixel(image, x, y, cube->map.ceiling_color);
}

static void	draw_floor(t_image *image, t_cube3d *cube, int min_y, int x)
{
	int	y;

	y = min_y - 1;
	while (++y < cube->window.height)
		put_pixel(image, x, y, cube->map.floor_color);
}

void	draw_screen_slice(t_image *image, t_ray *r, t_cube3d *cube, int x)
{
	double		l_h;
	double		line_origin;
	double		texy;
	double		texx;
	int			y;

	l_h = (TILE_SIZE * cube->window.height) / \
		(cos(normalize_angle(r->angle - cube->player.dir)) * r->dist);
	texx = (r->side == NORTH || r->side == SOUTH) * fmod(r->x_pos, TILE_SIZE) \
		+ (r->side == EAST || r->side == WEST) * fmod(r->y_pos, TILE_SIZE);
	if (r->side == EAST || r->side == NORTH)
		texx = TILE_SIZE - texx;
	texx = texx / TILE_SIZE * cube->map.textures[r->side]->width;
	line_origin = cube->window.height / 2 - l_h / 2;
	y = max(0, line_origin + 0.9999999999) - 1;
	draw_ceiling(image, cube, y + 1, x);
	while (++y < line_origin + l_h && y < cube->window.height)
	{
		texy = (y - line_origin) / l_h * \
			cube->map.textures[r->side]->height;
		put_pixel(image, x, y, \
			get_texture_color(cube->map.textures[r->side], texx, texy));
	}
	draw_floor(image, cube, y, x);
}
