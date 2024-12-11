/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fps.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbakker <jbakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/08 02:46:39 by jbakker       #+#    #+#                 */
/*   Updated: 2024/12/11 17:08:02 by jbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

double	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((double)time.tv_sec + (double)time.tv_usec / 1000000.);
}

void	fps_counter(t_cube3d *cube)
{
	cube->performance.last_frame_time = cube->performance.current_frame_time;
	cube->performance.current_frame_time = get_time();
	cube->performance.delta_time = cube->performance.current_frame_time - \
		cube->performance.last_frame_time;
	cube->performance.fps = 1 / cube->performance.delta_time;
}

int	show_fps(t_cube3d *cube)
{
	char	*fps_str;
	char	*output_str;

	if (!FPS)
		return (SUCCESS);
	fps_str = ft_itoa((int)cube->performance.fps);
	if (!fps_str)
		return (FAILURE);
	output_str = ft_strjoin("FPS: ", fps_str);
	if (!output_str)
		return (free(fps_str), FAILURE);
	mlx_string_put(cube->window.mlx, cube->window.win, \
		cube->window.width - 65, 30, rgb_to_int(120, 120, 120), output_str);
	return (free(fps_str), free(output_str), SUCCESS);
}

double	get_time_diff(t_cube3d *cube)
{
	return (get_time() - cube->performance.current_frame_time);
}
