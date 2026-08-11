/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <iskaraag@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 17:02:41 by zwloskow          #+#    #+#             */
/*   Updated: 2025/12/10 16:45:51 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/*
L(t) = P + tD
*/

void	move_forward(t_data *data)
{
	double	nx;
	double	ny;

	nx = data->player.x + data->player.dir_x * data->fps.move_speed;
	ny = data->player.y + data->player.dir_y * data->fps.move_speed;
	if (can_move(&data->map, nx, data->player.y))
		data->player.x = nx;
	if (can_move(&data->map, data->player.x, ny))
		data->player.y = ny;
}

void	move_backward(t_data *data)
{
	double	nx;
	double	ny;

	nx = data->player.x - data->player.dir_x * data->fps.move_speed;
	ny = data->player.y - data->player.dir_y * data->fps.move_speed;
	if (can_move(&data->map, nx, data->player.y))
		data->player.x = nx;
	if (can_move(&data->map, data->player.x, ny))
		data->player.y = ny;
}

void	move_left(t_data *data)
{
	double	nx;
	double	ny;

	nx = data->player.x - data->player.plane_x * data->fps.move_speed;
	ny = data->player.y - data->player.plane_y * data->fps.move_speed;
	if (can_move(&data->map, nx, data->player.y))
		data->player.x = nx;
	if (can_move(&data->map, data->player.x, ny))
		data->player.y = ny;
}

void	move_right(t_data *data)
{
	double	nx;
	double	ny;

	nx = data->player.x + data->player.plane_x * data->fps.move_speed;
	ny = data->player.y + data->player.plane_y * data->fps.move_speed;
	if (can_move(&data->map, nx, data->player.y))
		data->player.x = nx;
	if (can_move(&data->map, data->player.x, ny))
		data->player.y = ny;
}
