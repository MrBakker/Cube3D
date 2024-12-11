/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbakker <jbakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/06 14:20:16 by jbakker       #+#    #+#                 */
/*   Updated: 2024/12/11 18:56:28 by jbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	big_cube_close(t_cube3d *cube3d)
{
	int	i;

	if (!cube3d)
		exit(0);
	i = -1;
	while (++i < 6)
		free_texture(cube3d, cube3d->map.textures[i]);
	free_xpmgif(cube3d, cube3d->visuals.right_arrows);
	free_xpmgif(cube3d, cube3d->visuals.left_arrows);
	destory_window(cube3d);
	free_map(&cube3d->map);
	exit(0);
}
