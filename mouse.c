/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mouse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbakker <jbakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/08 16:21:27 by jbakker       #+#    #+#                 */
/*   Updated: 2024/12/11 16:07:58 by jbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	handle_mouse_move(int x, int y, void *param)
{
	t_cube3d	*cube;
	float		dx;

	if (!MOUSE)
		return (SUCCESS);
	(void)y;
	cube = (t_cube3d *)param;
	dx = x - cube->inputs.mouse_x;
	cube->inputs.mouse_x = x;
	cube->player.dir = normalize_angle \
		(cube->player.dir + (float)dx * (float)MOUSE_SENSITIVITY);
	if (x < INFINITE_MOUSE_GAP)
		cube->inputs.mouse_inf_dir = -1;
	else if (x > cube->window.width - INFINITE_MOUSE_GAP)
		cube->inputs.mouse_inf_dir = 1;
	else
		cube->inputs.mouse_inf_dir = 0;
	return (SUCCESS);
}
