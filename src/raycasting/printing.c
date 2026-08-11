/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwloskow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 21:23:37 by zwloskow          #+#    #+#             */
/*   Updated: 2025/12/06 14:03:33 by zwloskow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	frame_counter(t_data *data)
{
	struct timeval	current_time;
	double			elapsed;

	gettimeofday(&current_time, NULL);
	elapsed = (current_time.tv_sec - data->fps.prev_frame.tv_sec)
		+ (current_time.tv_usec - data->fps.prev_frame.tv_usec) / 1000000.0;
	data->fps.elapsed = elapsed;
	data->fps.prev_frame = current_time;
	data->fps.move_speed = 2.5 * elapsed;
	data->fps.rot_speed = 1.0 * elapsed;
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (!data || !data->img.addr)
		return ;
	if (x < 0 || y < 0 || x >= data->screen_w || y >= data->screen_h)
		return ;
	dst = data->img.addr + (y * data->img.line_length + x
			* (data->img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_c_and_f(t_data *data, int draw_start, int draw_end, int x)
{
	int	y;
	int	floor_color;
	int	ceiling_color;

	floor_color = (data->floor.r << 16) | (data->floor.g << 8)
		| (data->floor.b);
	ceiling_color = (data->ceilc.r << 16) | (data->ceilc.g << 8)
		| (data->ceilc.b);
	y = 0;
	while (y < draw_start)
	{
		my_mlx_pixel_put(data, x, y, ceiling_color);
		y++;
	}
	y = draw_end + 1;
	while (y < data->screen_h)
	{
		my_mlx_pixel_put(data, x, y, floor_color);
		y++;
	}
}

void	printer(t_data *data, int draw_start, int draw_end, int x)
{
	int	color;

	draw_c_and_f(data, draw_start, draw_end, x);
	while (draw_start <= draw_end)
	{
		data->ray.tex_y = (int)data->ray.tex_pos & (data->ray.curr_tex.h - 1);
		data->ray.tex_pos += data->ray.tex_step;
		color = get_tex_color(&data->ray.curr_tex,
				data->ray.tex_x, data->ray.tex_y);
		my_mlx_pixel_put(data, x, draw_start, color);
		draw_start++;
	}
}

void	draw_line(t_data *data, int x)
{
	int	line_h;
	int	draw_start;
	int	draw_end;

	if (!data->img.img || !data->img.addr)
		return ;
	if (data->ray.perpwalldist <= 0.000001)
		data->ray.perpwalldist = 0.000001;
	line_h = (int)(data->screen_h / data->ray.perpwalldist);
	draw_start = data->screen_h / 2 - line_h / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = data->screen_h / 2 + line_h / 2;
	if (draw_end > data->screen_h)
		draw_end = data->screen_h - 1;
	data->ray.tex_step = (double)data->ray.curr_tex.h / (double)line_h;
	data->ray.tex_pos = (draw_start - data->screen_h / 2 + line_h / 2)
		* data->ray.tex_step;
	printer(data, draw_start, draw_end, x);
}
