/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   xpmgif.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbakker <jbakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/11 16:44:18 by jbakker       #+#    #+#                 */
/*   Updated: 2024/12/11 18:50:04 by jbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static char	*get_gif_name(char *base_path, int index)
{
	char	*num;
	char	*temp;
	char	*frame_path;

	num = ft_itoa(index);
	if (!num)
		return (NULL);
	temp = ft_strjoin(base_path, num);
	if (!temp)
		return (free(num), NULL);
	frame_path = ft_strjoin(temp, ".xpm");
	free(num);
	free(temp);
	return (frame_path);
}

static t_texture	**load_gif_images(t_cube3d *cube, \
	char *base_path, int frame_count)
{
	t_texture	**frames;
	char		*frame_path;
	int			i;

	frames = (t_texture **)ft_calloc(frame_count, sizeof(t_texture *));
	if (!frames)
		return (NULL);
	i = -1;
	while (++i < frame_count)
	{
		frame_path = get_gif_name(base_path, i);
		if (!frame_path)
			return (free(frames), NULL);
		frames[i] = load_texture_from_name(cube, frame_path);
		free(frame_path);
		if (!frames[i])
			return (free(frames), NULL);
	}
	return (frames);
}

t_xpmgif	*load_xpmgif(t_cube3d *cube3d, char *base_path, \
	int frame_count, double frame_duration)
{
	t_xpmgif	*gif;
	int			i;

	gif = (t_xpmgif *)ft_calloc(1, sizeof(t_xpmgif));
	if (!gif)
		return (NULL);
	gif->frame_count = frame_count;
	gif->frames = load_gif_images(cube3d, base_path, frame_count);
	if (!gif->frames)
		return (free(gif), NULL);
	gif->width = gif->frames[0]->width;
	gif->height = gif->frames[0]->height;
	i = 0;
	while (++i < frame_count)
	{
		if (gif->frames[i]->width != gif->width || \
			gif->frames[i]->height != gif->height)
			return (free_xpmgif(cube3d, gif), NULL);
	}
	gif->frame_duration = frame_duration;
	gif->last_frame_time = -1;
	gif->current_frame = 0;
	gif->is_playing = 1;
	gif->transform = (t_transform){{0, 0}, 1, 1};
	return (gif);
}

void	play_xmpgif(t_cube3d *cube, t_image *image, t_xpmgif *gif)
{
	if (!gif->is_playing)
	{
		gif->last_frame_time = -1;
		return ;
	}
	if (gif->last_frame_time == -1)
		gif->last_frame_time = cube->performance.current_frame_time;
	if (gif->last_frame_time + gif->frame_duration <= \
		cube->performance.current_frame_time)
	{
		gif->last_frame_time += gif->frame_duration;
		gif->current_frame = (gif->current_frame + 1) % gif->frame_count;
	}
	draw_texture_to_screen(cube, image, \
		gif->frames[gif->current_frame], gif->transform);
	return ;
}

void	xmpgif_set_transform(t_xpmgif *gif, t_point pos, int width, int height)
{
	gif->transform.pos = pos;
	gif->transform.x_scale = (float)width / (float)gif->width;
	gif->transform.y_scale = (float)height / (float)gif->height;
}
