/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <iskaraag@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 14:09:35 by zwloskow          #+#    #+#             */
/*   Updated: 2025/12/10 16:37:36 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include <sys/time.h>
# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"

# define KEY_W 119
# define KEY_S 115
# define KEY_A 97
# define KEY_D 100
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_ESC 65307

# define MAP_WIDTH 640
# define MAP_HEIGHT 480

typedef enum e_hit_side
{
	VERTICAL_WALL,
	HORIZONTAL_WALL
}	t_hit_side;

typedef struct s_keys
{
	int	w;
	int	a;
	int	s;
	int	d;
	int	left;
	int	right;
	int	esc;
}	t_keys;

typedef struct s_player
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	char	dir;
}	t_player;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		w;
	int		h;
}	t_img;

typedef struct s_ray
{
	double	camera_x;
	double	raydir_x;
	double	raydir_y;

	int		map_x;
	int		map_y;

	double	sidedist_x;
	double	sidedist_y;

	double	deltadist_x;
	double	deltadist_y;

	int		step_x;
	int		step_y;

	int		hit;
	int		side;

	double	perpwalldist;

	double	wall_x;
	t_img	curr_tex;
	int		tex_x;
	int		tex_y;
	double	tex_pos;
	double	tex_step;
}	t_ray;

typedef struct s_fps
{
	struct timeval	prev_frame;
	double			elapsed;
	double			move_speed;
	double			rot_speed;
}	t_fps;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_tex
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	t_img	n_tex;
	t_img	s_tex;
	t_img	w_tex;
	t_img	e_tex;
}	t_tex;

typedef struct s_map
{
	char		**grid;
	int			width;
	int			height;
	t_player	player;
}	t_map;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_img		img;
	int			screen_w;
	int			screen_h;
	t_player	player;
	t_keys		keys;
	t_map		map;
	t_ray		ray;
	t_fps		fps;
	t_tex		tex;
	t_rgb		floor;
	t_rgb		ceilc;
}	t_data;

/***** SRC/MAP/ *****/
//map_check.c
int		is_map_closed(t_map *m);
//map_normalize.c
char	**normalize_map(char **raw);
//map_player.c
int		find_player(t_map *m);

/***** SRC/PARSE/ *****/
//parse_color.c
int		parse_rgb(t_rgb *c, char *line);
void	parse_color_line(t_data *data, char *line);
//parse_map.c
char	**map_add_line(char **map, char *line);
char	**collect_map(int fd);
t_map	parse_map_from_fd(int fd);
//parse_tex.c
void	parse_texture_line(t_tex *tex, char *line);
//parse_utils.c
int		is_map_line(char *l);
//parse.c
void	parse_cub(char *file, t_data *data);

/***** SRC/RAYCASTING/ *****/
//destroy_images.c
void	destroy_images(t_data *data);
int		close_window(void *param);
//key_handlers.c
int		handle_keys(void *param);
int		key_press(int keycode, void *param);
int		key_release(int keycode, void *param);
//player_movement.c
void	move_forward(t_data *data);
void	move_backward(t_data *data);
void	move_left(t_data *data);
void	move_right(t_data *data);
//player_rotation.c
void	rotate_left(t_data *data);
void	rotate_right(t_data *data);
//printing.c
void	frame_counter(t_data *data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw_c_and_f(t_data *data, int draw_start, int draw_end, int x);
void	printer(t_data *data, int draw_start, int draw_end, int x);
void	draw_line(t_data *data, int x);
//raycasting.c
void	init_ray(t_data *data, int x);
void	calculate_step(t_player *player, t_ray *ray);
void	dda(t_data *data, t_ray *ray);
void	calculate_dist(t_data *data, t_ray *ray);
void	raycasting(t_data *data);
//textures.c
void	load_texture_file(t_data *d, t_img *text, char *path);
void	load_all_textures(t_data *d);
int		get_tex_color(t_img *tex, int x, int y);

/***** SRC/UTILS/ *****/
//error.c
void	print_error(char *msg);
//free.c
void	free_split(char **arr);
void	free_texture_paths(t_tex *tex);
//movement_utils.c
int		is_walkable_cell(char c);
int		can_move(t_map *map, double new_x, double new_y);

/***** main.c *****/
void	player_dir_we(t_data *data);
void	init_player(t_data *data);
void	initializing(t_data	*data);
int		game_loop(void *param);

#endif
