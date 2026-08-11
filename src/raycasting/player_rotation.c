/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwloskow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 14:58:25 by zwloskow          #+#    #+#             */
/*   Updated: 2025/12/04 19:27:14 by zwloskow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/*
ROTATION MATRIX
[ cos(a) -sin(a) ]
[ sin(a)  cos(a) ]
*/

void	rotate_right(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->player.dir_x;
	data->player.dir_x = data->player.dir_x * cos(data->fps.rot_speed)
		- data->player.dir_y * sin(data->fps.rot_speed);
	data->player.dir_y = old_dir_x * sin(data->fps.rot_speed)
		+ data->player.dir_y * cos(data->fps.rot_speed);
	old_plane_x = data->player.plane_x;
	data->player.plane_x = data->player.plane_x * cos(data->fps.rot_speed)
		- data->player.plane_y * sin(data->fps.rot_speed);
	data->player.plane_y = old_plane_x * sin(data->fps.rot_speed)
		+ data->player.plane_y * cos(data->fps.rot_speed);
}

void	rotate_left(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->player.dir_x;
	data->player.dir_x = data->player.dir_x * cos(-data->fps.rot_speed)
		- data->player.dir_y * sin(-data->fps.rot_speed);
	data->player.dir_y = old_dir_x * sin(-data->fps.rot_speed)
		+ data->player.dir_y * cos(-data->fps.rot_speed);
	old_plane_x = data->player.plane_x;
	data->player.plane_x = data->player.plane_x * cos(-data->fps.rot_speed)
		- data->player.plane_y * sin(-data->fps.rot_speed);
	data->player.plane_y = old_plane_x * sin(-data->fps.rot_speed)
		+ data->player.plane_y * cos(-data->fps.rot_speed);
}
