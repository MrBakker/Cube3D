/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keyboard.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbakker <jbakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/06 14:14:21 by jbakker       #+#    #+#                 */
/*   Updated: 2024/12/10 02:38:57 by jbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void	move_player(t_cube3d *cube, double angle_delta)
{
	double	new_x;
	double	new_y;

	new_x = cube->player.x + \
		cos(normalize_angle(cube->player.dir + angle_delta)) \
			* MOVE_SPEED * cube->performance.delta_time;
	new_y = cube->player.y + \
		sin(normalize_angle(cube->player.dir + angle_delta)) \
			* MOVE_SPEED * cube->performance.delta_time;
	if (get_map_object(&cube->map, new_x, new_y) & (EMPTY | PLAYER_START_POS))
	{
		cube->player.x = new_x;
		cube->player.y = new_y;
	}
	else if (get_map_object(&cube->map, new_x, new_y) == WALL)
	{
		if (get_map_object(&cube->map, new_x, cube->player.y) & \
			(EMPTY | PLAYER_START_POS))
			cube->player.x = new_x;
		if (get_map_object(&cube->map, cube->player.x, new_y) & \
			(EMPTY | PLAYER_START_POS))
			cube->player.y = new_y;
	}
}

int	handle_keypress(int keycode, void *param)
{
	t_cube3d	*cube;

	cube = (t_cube3d *)param;
	if (keycode == KEY_W)
		cube->inputs.w = 1;
	if (keycode == KEY_A)
		cube->inputs.a = 1;
	if (keycode == KEY_S)
		cube->inputs.s = 1;
	if (keycode == KEY_D)
		cube->inputs.d = 1;
	if (keycode == KEY_LEFT)
		cube->inputs.left = 1;
	if (keycode == KEY_RIGHT)
		cube->inputs.right = 1;
	if (keycode == KEY_ESC)
		big_cube_close(cube);
	return (SUCCESS);
}

int	handle_key_realease(int keycode, void *param)
{
	t_cube3d	*cube;

	cube = (t_cube3d *)param;
	if (keycode == KEY_W)
		cube->inputs.w = 0;
	if (keycode == KEY_A)
		cube->inputs.a = 0;
	if (keycode == KEY_S)
		cube->inputs.s = 0;
	if (keycode == KEY_D)
		cube->inputs.d = 0;
	if (keycode == KEY_LEFT)
		cube->inputs.left = 0;
	if (keycode == KEY_RIGHT)
		cube->inputs.right = 0;
	return (SUCCESS);
}

int	handle_keys(t_cube3d *cube)
{
	cube->player.dir = normalize_angle(cube->player.dir + ROTATE_SPEED * \
		cube->performance.delta_time * cube->inputs.mouse_inf_dir);
	if (cube->inputs.left)
		cube->player.dir = normalize_angle(cube->player.dir - \
			ROTATE_SPEED * cube->performance.delta_time);
	if (cube->inputs.right)
		cube->player.dir = normalize_angle(cube->player.dir + \
			ROTATE_SPEED * cube->performance.delta_time);
	if (cube->inputs.w)
		move_player(cube, 0);
	if (cube->inputs.a)
		move_player(cube, -HALF_PI);
	if (cube->inputs.s)
		move_player(cube, PI);
	if (cube->inputs.d)
		move_player(cube, HALF_PI);
	return (SUCCESS);
}
