/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   door.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbakker <jbakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/11 12:32:18 by jbakker       #+#    #+#                 */
/*   Updated: 2024/12/11 15:06:03 by jbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static int	is_in_player_door_view(t_player *player, double angle)
{
	double	d;

	d = normalize_angle(player->dir - angle + PI) - PI;
	return (d < FOV / D360 * PI && d > -FOV / D360 * PI);
}

void	handle_doors(t_cube3d *cube)
{
	const int	xdelta[8] = {1, 1, 0, -1, -1, -1, 0, 1};
	const int	ydelta[8] = {0, 1, 1, 1, 0, -1, -1, -1};
	t_point		next_pos;
	int			map_object;
	int			i;

	if (cube->inputs.space != KEY_IS_PRESSED)
		return ;
	cube->inputs.space = KEY_IS_WAITING;
	if (get_map_object(&cube->map, cube->player.x, cube->player.y) & \
		~(EMPTY | PLAYER_START_POS))
		return ;
	i = -1;
	while (++i < 8)
	{
		if (is_in_player_door_view(&cube->player, i / 8. * TWO_PI))
		{
			next_pos.x = cube->player.x + xdelta[i] * TILE_SIZE;
			next_pos.y = cube->player.y + ydelta[i] * TILE_SIZE;
			map_object = get_map_object(&cube->map, next_pos.x, next_pos.y);
			if (map_object & (OPEN_DOOR | CLOSED_DOOR))
				set_map_object(&cube->map, next_pos.x, next_pos.y, \
					map_object ^ (OPEN_DOOR | CLOSED_DOOR));
		}
	}
}
