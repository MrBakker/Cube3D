/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbakker <jbakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/06 14:14:24 by jbakker       #+#    #+#                 */
/*   Updated: 2024/12/11 18:57:43 by jbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static int	create_window(t_window *window)
{
	window->width = W_WIDTH;
	window->height = W_HEIGHT;
	window->mlx = mlx_init();
	if (!window->mlx)
		return (FAILURE);
	window->win = mlx_new_window(window->mlx, W_WIDTH, W_HEIGHT, "Cube3D");
	if (!window->win)
		return (mlx_destroy_display(window->mlx), free(window->mlx), FAILURE);
	return (SUCCESS);
}

static void	setup_hooks(t_cube3d *cube3d)
{
	mlx_hook(cube3d->window.win, KEY_DOWN, M_KEY_PRESS, \
		handle_keypress, (void *)cube3d);
	mlx_hook(cube3d->window.win, KEY_UP, M_KEY_RELEASE, \
		handle_key_realease, (void *)cube3d);
	mlx_hook(cube3d->window.win, EXIT, 0, \
		big_cube_close, (void *)cube3d);
	mlx_hook(cube3d->window.win, MOUSE_MOVE, M_MOTION_NOTIFY, \
		handle_mouse_move, (void *)cube3d);
	mlx_loop_hook(cube3d->window.mlx, render_frame, (void *)cube3d);
}

static void	calculate_render_data(t_render *render)
{
	render->half_screen_width = W_WIDTH / 2.;
	render->half_screen_height = W_HEIGHT / 2.;
	render->half_fov = FOV / D360 / 2. * TWO_PI;
	render->depth = sqrt(pow(render->half_screen_width / \
		sin(render->half_fov), 2) - pow((render->half_screen_width), 2));
}

static int	fetch_visuals(t_cube3d *cube)
{
	float	direction_size;

	direction_size = cube->window.height / 10.;
	cube->visuals.right_arrows = \
		load_xpmgif(cube, "textures/rightarrows/", 10, 0.05);
	if (!cube->visuals.right_arrows)
		return (FAILURE);
	xmpgif_set_transform(cube->visuals.right_arrows, (t_point) \
		{cube->window.width - direction_size, cube->window.height - \
		direction_size}, direction_size, direction_size);
	cube->visuals.left_arrows = \
		load_xpmgif(cube, "textures/leftarrow/", 10, 0.05);
	if (!cube->visuals.left_arrows)
		return (free_xpmgif(cube, cube->visuals.right_arrows), FAILURE);
	xmpgif_set_transform(cube->visuals.left_arrows, (t_point) \
		{0, cube->window.height - direction_size}, \
		direction_size, direction_size);
	return (SUCCESS);
}

int	main(int argc, char **argv)
{
	t_cube3d	cube3d;

	ft_bzero(&cube3d, sizeof(t_cube3d));
	(void)argc;
	(void)argv;
	// if (argc != 2)
	// 	return (ft_printf("Usage: %s <filename>\n", argv[0]), FAILURE);
	// if (!ft_endswith(argv[1], ".cub"))
	// 	return (ft_printf("%sError:%s Invalid file extension\n", 
	// 		RED, DEFAULT), FAILURE);
	if (create_window(&(cube3d.window)) == FAILURE)
		return (ft_printf("%sError:%s failed to create the window\n", \
			RED, DEFAULT), big_cube_close(&cube3d), FAILURE);
	create_test_map(&cube3d);
	if (fetch_visuals(&cube3d) == FAILURE)
		return (ft_printf("%sError:%s failed to load the animated sprites\n", \
		RED, DEFAULT), big_cube_close(&cube3d), FAILURE);
	setup_hooks(&cube3d);
	calculate_render_data(&cube3d.render);
	mlx_loop(cube3d.window.mlx);
}
