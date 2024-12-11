/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   texture.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbakker <jbakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/06 16:25:43 by jbakker       #+#    #+#                 */
/*   Updated: 2024/12/11 18:38:34 by jbakker       ########   odam.nl         */
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

t_texture	*get_texture(t_cube3d *cube, t_ray *ray)
{
	const int	x_dir_diff[4] = {0, 1, 0, -1};
	const int	y_dir_diff[4] = {-1, 0, 1, 0};

	if (ray->hit & CLOSED_DOOR)
		return (cube->map.textures[TIDOOR]);
	if (get_map_object(&cube->map, ray->x_pos + x_dir_diff[ray->side], \
		ray->y_pos + y_dir_diff[ray->side]) & OPEN_DOOR)
		return (cube->map.textures[TIDOOR_WALL]);
	return (cube->map.textures[ray->side]);
}

static float	calculate_texture_x_pos(t_ray *ray, t_texture *texture)
{
	float	x;

	if (ray->side == TINORTH || ray->side == TISOUTH)
		x = fmod(ray->x_pos, TILE_SIZE);
	else
		x = fmod(ray->y_pos, TILE_SIZE);
	if (ray->side == TIEAST || ray->side == TINORTH)
		x = TILE_SIZE - x;
	return (x / TILE_SIZE * texture->width);
}

void	draw_screen_slice(t_image *image, t_ray *r, t_cube3d *cube, int x)
{
	t_texture	*tex;
	float		line_height;
	float		line_origin;
	t_point		texpt;
	int			y;

	tex = get_texture(cube, r);
	line_height = (TILE_SIZE * cube->window.height) / \
		(cos(normalize_angle(r->angle - cube->player.dir)) * r->dist);
	texpt.x = calculate_texture_x_pos(r, tex);
	line_origin = cube->window.height / 2 - line_height / 2;
	y = max(0, line_origin + 0.9999999999) - 1;
	draw_ceiling(image, cube, y + 1, x);
	while (++y < line_origin + line_height && y < cube->window.height)
	{
		texpt.y = (y - line_origin) / line_height * tex->height;
		*(unsigned int *)(image->addr + (y * image->line_length + \
			x * (image->bits_per_pixel >> 3))) = *(int *)(tex->addr + \
			(int)texpt.y * tex->line_length + \
			(int)texpt.x * (tex->bits_per_pixel >> 3));
	}
	draw_floor(image, cube, y, x);
}

void	draw_texture_to_screen(t_cube3d *cube, t_image *image, \
	t_texture *texture, t_transform transform)
{
	int	color;
	int	x;
	int	y;
	int	tx;
	int	ty;

	y = -1;
	while (++y < texture->height)
	{
		x = -1;
		while (++x < texture->width)
		{
			tx = transform.pos.x + x * transform.x_scale;
			ty = transform.pos.y + y * transform.y_scale;
			if (tx < 0 || tx >= cube->window.width || ty < 0 || \
				ty >= cube->window.height)
				continue ;
			color = *(unsigned int *)(texture->addr + y * texture->line_length \
				+ x * (texture->bits_per_pixel >> 3));
			if (color != XPM_TRANSPARENT)
				put_pixel(image, tx, ty, color);
		}
	}
}
