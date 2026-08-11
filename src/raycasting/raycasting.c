/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwloskow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 18:05:25 by zwloskow          #+#    #+#             */
/*   Updated: 2025/12/06 13:45:06 by zwloskow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_ray(t_data *data, int x)
{
	data->ray.camera_x = 2.0 * (double)x / (double)data->screen_w - 1.0;
	data->ray.raydir_x = data->player.dir_x + data->player.plane_x
		* data->ray.camera_x;
	data->ray.raydir_y = data->player.dir_y + data->player.plane_y
		* data->ray.camera_x;
	data->ray.map_x = (int)data->player.x;
	data->ray.map_y = (int)data->player.y;
	if (data->ray.raydir_x == 0)
		data->ray.deltadist_x = 1e30;
	else
		data->ray.deltadist_x = fabs(1 / data->ray.raydir_x);
	if (data->ray.raydir_y == 0)
		data->ray.deltadist_y = 1e30;
	else
		data->ray.deltadist_y = fabs(1 / data->ray.raydir_y);
	data->ray.hit = 0;
}

void	calculate_step(t_player *player, t_ray *ray)
{
	if (ray->raydir_x < 0)
	{
		ray->step_x = -1;
		ray->sidedist_x = (player->x - ray->map_x) * ray->deltadist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->sidedist_x = (ray->map_x + 1.0 - player->x) * ray->deltadist_x;
	}
	if (ray->raydir_y < 0)
	{
		ray->step_y = -1;
		ray->sidedist_y = (player->y - ray->map_y) * ray->deltadist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->sidedist_y = (ray->map_y + 1.0 - player->y) * ray->deltadist_y;
	}
}

void	dda(t_data *data, t_ray *ray)
{
	(void)data;
	while (ray->hit == 0)
	{
		if (ray->sidedist_x < ray->sidedist_y)
		{
			ray->sidedist_x += ray->deltadist_x;
			ray->map_x += ray->step_x;
			ray->side = VERTICAL_WALL;
		}
		else
		{
			ray->sidedist_y += ray->deltadist_y;
			ray->map_y += ray->step_y;
			ray->side = HORIZONTAL_WALL;
		}
		if (data->map.grid[ray->map_y][ray->map_x] != '0')
			ray->hit = 1;
	}
}

void	calculate_dist(t_data *data, t_ray *ray)
{
	if (ray->side == VERTICAL_WALL)
	{
		ray->perpwalldist = ray->sidedist_x - ray->deltadist_x;
		ray->wall_x = data->player.y + ray->raydir_y * ray->perpwalldist;
		if (ray->raydir_x >= 0)
			ray->curr_tex = data->tex.w_tex;
		else
			ray->curr_tex = data->tex.e_tex;
	}
	else
	{
		ray->perpwalldist = ray->sidedist_y - ray->deltadist_y;
		ray->wall_x = data->player.x + ray->raydir_x * ray->perpwalldist;
		if (ray->raydir_y >= 0)
			ray->curr_tex = data->tex.n_tex;
		else
			ray->curr_tex = data->tex.s_tex;
	}
	ray->wall_x -= floor(ray->wall_x);
	ray->tex_x = (int)(ray->wall_x * (double)(ray->curr_tex.w));
	if (ray->side == VERTICAL_WALL && ray->raydir_x < 0)
		ray->tex_x = ray->curr_tex.w - ray->tex_x - 1;
	if (ray->side == HORIZONTAL_WALL && ray->raydir_y > 0)
		ray->tex_x = ray->curr_tex.w - ray->tex_x - 1;
}

void	raycasting(t_data *data)
{
	int		x;

	if (data->img.img)
		mlx_destroy_image(data->mlx, data->img.img);
	data->img.img = mlx_new_image(data->mlx, data->screen_w, data->screen_h);
	if (!data->img.img)
		return ;
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel,
			&data->img.line_length, &data->img.endian);
	x = 0;
	while (x < data->screen_w)
	{
		init_ray(data, x);
		calculate_step(&data->player, &data->ray);
		dda(data, &data->ray);
		calculate_dist(data, &data->ray);
		draw_line(data, x);
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}
