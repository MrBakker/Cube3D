/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   frame.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbakker <jbakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/06 14:38:50 by jbakker       #+#    #+#                 */
/*   Updated: 2024/12/11 14:10:55 by jbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static t_ray	*shoot_rays(t_cube3d *cube)
{
	double	angle_delta;
	t_ray	*rays;
	t_ray	h_ray;
	t_ray	v_ray;
	int		i;

	rays = (t_ray *)malloc(sizeof(t_ray) * cube->window.width);
	if (!rays)
		return (NULL);
	i = -1;
	while (++i < cube->window.width)
	{
		angle_delta = asin((i - (double)cube->window.width / 2.0) / \
			sqrt(pow(cube->render.depth, 2) + \
			pow((i - (double)cube->window.width / 2.0), 2)));
		h_ray = gen_horizontal_ray(&cube->player, angle_delta);
		v_ray = gen_vertical_ray(&cube->player, angle_delta);
		raycast(&h_ray, &cube->map);
		raycast(&v_ray, &cube->map);
		rays[i] = v_ray;
		if ((h_ray.dist < v_ray.dist && h_ray.is_valid) || \
			(h_ray.is_valid && !v_ray.is_valid))
			rays[i] = h_ray;
	}
	return (rays);
}

static void	draw_walls_3d(t_image *image, t_ray *rays, t_cube3d *cube)
{
	int		i;

	i = -1;
	while (++i < cube->window.width)
		if (rays[i].is_valid)
			draw_screen_slice(image, &rays[i], cube, i);
}

static int	update_screen(t_cube3d *cube, t_ray *rays)
{
	t_image	img;

	img.img = mlx_new_image(cube->window.mlx, cube->window.width, \
		cube->window.height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
		&img.line_length, &img.endian);
	draw_walls_3d(&img, rays, cube);
	draw_minimap(&img, cube, rays);
	mlx_put_image_to_window(cube->window.mlx, cube->window.win, img.img, 0, 0);
	mlx_destroy_image(cube->window.mlx, img.img);
	if (show_fps(cube) == FAILURE)
		return (big_cube_close(cube), FAILURE);
	return (SUCCESS);
}

int	render_frame(void *param)
{
	t_cube3d	*cube;
	t_ray		*rays;

	cube = (t_cube3d *)param;
	fps_counter(cube);
	handle_doors(cube);
	handle_keys(cube);
	rays = shoot_rays(cube);
	if (!rays)
		return (big_cube_close(cube), FAILURE);
	if (update_screen(cube, rays) == FAILURE)
		return (big_cube_close(cube), FAILURE);
	free(rays);
	return (SUCCESS);
}
