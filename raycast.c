/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycast.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbakker <jbakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/07 17:31:49 by jbakker       #+#    #+#                 */
/*   Updated: 2024/12/10 01:40:29 by jbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

t_ray	gen_horizontal_ray(t_player *player, double angle_delta)
{
	t_ray	ray;
	double	a_tan;

	ft_bzero(&ray, sizeof(t_ray));
	ray.angle = normalize_angle(player->dir + angle_delta);
	ray.origin_x = player->x;
	ray.origin_y = player->y;
	a_tan = -1 / tan(ray.angle);
	if (ray.angle > PI)
	{
		ray.y_pos = floor(player->y / TILE_SIZE) * TILE_SIZE - 0.0001;
		ray.step_y = -TILE_SIZE;
	}
	else if (ray.angle < PI)
	{
		ray.y_pos = floor(player->y / TILE_SIZE) * TILE_SIZE + TILE_SIZE;
		ray.step_y = TILE_SIZE;
	}
	ray.step_x = -ray.step_y * a_tan;
	ray.x_pos = (player->y - ray.y_pos) * a_tan + player->x;
	ray.is_valid = (ray.angle != 0 && ray.angle != PI);
	ray.side = (ray.angle > PI) * SOUTH + (ray.angle < PI) * NORTH;
	return (ray);
}

t_ray	gen_vertical_ray(t_player *player, double angle)
{
	t_ray	ray;
	double	n_tan;

	ft_bzero(&ray, sizeof(t_ray));
	ray.angle = normalize_angle(player->dir + angle);
	ray.origin_x = player->x;
	ray.origin_y = player->y;
	n_tan = -tan(ray.angle);
	if (ray.angle > HALF_PI && ray.angle < ONE_HALF_PI)
	{
		ray.x_pos = floor(player->x / TILE_SIZE) * TILE_SIZE - 0.0001;
		ray.step_x = -TILE_SIZE;
	}
	else if (ray.angle < HALF_PI || ray.angle > ONE_HALF_PI)
	{
		ray.x_pos = floor(player->x / TILE_SIZE) * TILE_SIZE + TILE_SIZE;
		ray.step_x = TILE_SIZE;
	}
	ray.step_y = -ray.step_x * n_tan;
	ray.y_pos = (player->x - ray.x_pos) * n_tan + player->y;
	ray.is_valid = (ray.angle != HALF_PI && ray.angle != ONE_HALF_PI);
	ray.side = (ray.angle < HALF_PI || ray.angle > ONE_HALF_PI) * WEST + \
		(ray.angle > HALF_PI && ray.angle < ONE_HALF_PI) * EAST;
	return (ray);
}

void	raycast(t_ray *ray, t_map *map)
{
	int	max_search_depth;

	if (!ray->is_valid)
		return ;
	max_search_depth = map->map_width + map->map_height;
	while (max_search_depth--)
	{
		if (get_map_object(map, ray->x_pos, ray->y_pos) == WALL)
		{
			ray->hit = WALL;
			ray->dist = distance(ray->origin_x, ray->origin_y, \
				ray->x_pos, ray->y_pos);
			return ;
		}
		ray->x_pos += ray->step_x;
		ray->y_pos += ray->step_y;
	}
	ray->is_valid = 0;
}

void	print_ray(t_ray *ray)
{
	printf("\nRay:\nAngle: %f\n", ray->angle);
	printf("Distance: %f\n", ray->dist);
	printf("Hit: %d\n", ray->hit);
	printf("Side: %d\n", ray->side);
	printf("Valid: %d\n", ray->is_valid);
	printf("Origin: %d, %d\n", ray->origin_x, ray->origin_y);
	printf("Position: %f, %f\n", ray->x_pos, ray->y_pos);
	printf("Step: %f, %f\n", ray->step_x, ray->step_y);
}