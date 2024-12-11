/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cube3d.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbakker <jbakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/10 01:50:13 by jbakker       #+#    #+#                 */
/*   Updated: 2024/12/11 15:02:31 by jbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "mlx_linux/mlx.h"
#include "libft/libft.h"
#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>

// Game features
#define MINIMAP 1
#define FPS 1
#define MOUSE 0

// Program state
#define FAILURE 1
#define SUCCESS 0

// Window configurations
#define W_WIDTH 960
#define W_HEIGHT 640

// Mlx events
#define KEY_DOWN 2
#define KEY_UP 3
#define MOUSE_DOWN 4
#define MOUSE_UP 5
#define MOUSE_MOVE 6
#define EXIT 17

// Mlx masks
#define M_KEY_PRESS 1
#define M_KEY_RELEASE 2
#define M_MOTION_NOTIFY 64

// Keycodes
#define KEY_W 119
#define KEY_A 97
#define KEY_S 115
#define KEY_D 100
#define KEY_SPACE 32
#define KEY_ESC 65307
#define KEY_LEFT 65361
#define KEY_RIGHT 65363

// terminal colors
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define BLUE "\033[0;34m"
#define DEFAULT "\033[0m"

// Math constants
#define HALF_PI 1.57079632679
#define PI 3.14159265359
#define ONE_HALF_PI 4.71238898038
#define TWO_PI 6.28318530718
#define D360 360.0

// Game settings
#define MOVE_SPEED 100
#define ROTATE_SPEED 1.5
#define TILE_SIZE 64
#define FOV 80
#define MOUSE_SENSITIVITY 0.005
#define INFINITE_MOUSE_GAP 30

// Directions (texture indexes)
#define TINORTH 0
#define TIEAST 1
#define TISOUTH 2
#define TIWEST 3
#define TIDOOR 4
#define TIDOOR_WALL 5

// Map identifiers
#define UNKNOWN 0
#define EMPTY 1
#define WALL 2
#define PLAYER_START_POS 4
#define CLOSED_DOOR 8
#define OPEN_DOOR 16

// Minimap
#define MINIMAP_SCALE 2
#define MINIMAP_SIZE 150
#define MINIMAP_BORDER_SIZE 3
#define MINIMAP_BORDER_OFFSET 10
#define MINIMAP_PLAYER_SIZE 5

// Keyboard
#define KEY_IS_RELEASED 0
#define KEY_IS_PRESSED 1
#define KEY_IS_WAITING 2

typedef struct s_window
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
}	t_window;

typedef struct s_inputs
{
	short	w;
	short	a;
	short	s;
	short	d;
	short	left;
	short	right;
	short	space;
	short	mouse_x;
	short	mouse_inf_dir;
}	t_inputs;

typedef struct s_texture
{
	void	*img;
	char	*addr;
	char	*path;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_texture;

// map --> a list of rows, so map[y][x]
typedef struct s_map
{
	t_texture	*textures[6];
	int			floor_color;
	int			ceiling_color;
	int			map_width;
	int			map_height;
	int			**map;
}	t_map;

typedef struct s_player
{
	double	x;
	double	y;
	double	dir;
}	t_player;

typedef struct s_peformance
{
	double		last_frame_time;
	double		current_frame_time;
	double		delta_time;
	double		fps;
}	t_performance;

typedef struct s_render
{
	double	half_screen_width;
	double	half_screen_height;
	double	half_fov;
	double	depth;
}	t_render;

typedef struct s_cube3d
{
	t_window		window;
	t_inputs		inputs;
	t_player		player;
	t_map			map;
	t_performance	performance;
	t_render		render;
}	t_cube3d;

typedef struct s_ray
{
	double	angle;
	double	dist;
	int		hit;
	int		side;
	int		is_valid;
	int		origin_x;
	int		origin_y;
	double	x_pos;
	double	y_pos;
	double	step_x;
	double	step_y;
}	t_ray;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image;

typedef struct s_point
{
	double	x;
	double	y;
}	t_point;

typedef struct s_line
{
	t_point	p1;
	t_point	p2;
	int		color;
}	t_line;

// data_gen.c --> TEMPOARY
void		create_test_map(t_cube3d *cube3d);

// door.c
void		handle_doors(t_cube3d *cube);

// exit.c
void		free_map(t_map *map);
void		destroy_textures(t_cube3d *cube3d);
void		destory_window(t_cube3d *cube3d);
int			big_cube_close(t_cube3d *cube3d);

// floor_ceiling.c
void		draw_ceiling(t_image *image, t_cube3d *cube, int max_y, int x);
void		draw_floor(t_image *image, t_cube3d *cube, int min_y, int x);

// fps.c
void		fps_counter(t_cube3d *cube);
int			show_fps(t_cube3d *cube);
double		get_time_diff(t_cube3d *cube);

// frame.c
int			render_frame(void *param);

// keyboard.c
int			handle_keypress(int keycode, void *param);
int			handle_key_realease(int keycode, void *param);
int			handle_keys(t_cube3d *cube);

// main.c
int			main(int argc, char **argv);

// map.c
int			get_map_object(t_map *map, double x, double y);
void		set_map_object(t_map *map, double x, double y, int object);
int			is_valid_map_position(t_map *map, int x, int y);
int			is_in_bounds_of_minimap(int x, int y, void *unused);

// minimap.c
void		draw_minimap(t_image *image, t_cube3d *cube, t_ray *rays);

// mouse.c
int			handle_mouse_move(int x, int y, void *param);

// raycast.c
t_ray		gen_horizontal_ray(t_player *player, double angle_delta);
t_ray		gen_vertical_ray(t_player *player, double angle);
void		raycast(t_ray *ray, t_map *map);
void		print_ray(t_ray *ray);

// screen.c
int			is_in_bounds_of_screen(int x, int y, void *window);
void		put_pixel(t_image *data, int x, int y, int color);
void		draw_circle(t_image *data, t_point p, int r, int color);
void		draw_line(t_image *image, t_line line, void *payload, \
				int (*bound_check)(int, int, void *));
void		draw_ray_2d(t_image *image, t_ray *ray, t_window *window);

// texture.c
t_texture	*load_texture_from_name(t_cube3d *cube3d, char *name);
void		draw_screen_slice(t_image *image, t_ray *ray, t_cube3d *cube, \
				int x);

// utils.c
double		min(double a, double b);
int			max(int a, int b);
int			rgb_to_int(int r, int g, int b);
double		distance(double x1, double y1, double x2, double y2);
double		normalize_angle(double angle);
