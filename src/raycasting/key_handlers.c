/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handlers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <iskaraag@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:31:49 by zwloskow          #+#    #+#             */
/*   Updated: 2025/12/07 15:37:13 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	handle_keys(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (data->keys.w)
		move_forward(data);
	if (data->keys.s)
		move_backward(data);
	if (data->keys.a)
		move_left(data);
	if (data->keys.d)
		move_right(data);
	if (data->keys.left)
		rotate_left(data);
	if (data->keys.right)
		rotate_right(data);
	if (data->keys.esc)
		close_window(data);
	return (0);
}

int	key_press(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keycode == KEY_W)
		data->keys.w = 1;
	if (keycode == KEY_A)
		data->keys.a = 1;
	if (keycode == KEY_S)
		data->keys.s = 1;
	if (keycode == KEY_D)
		data->keys.d = 1;
	if (keycode == KEY_LEFT)
		data->keys.left = 1;
	if (keycode == KEY_RIGHT)
		data->keys.right = 1;
	if (keycode == KEY_ESC)
		data->keys.esc = 1;
	return (0);
}

int	key_release(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keycode == KEY_W)
		data->keys.w = 0;
	if (keycode == KEY_A)
		data->keys.a = 0;
	if (keycode == KEY_S)
		data->keys.s = 0;
	if (keycode == KEY_D)
		data->keys.d = 0;
	if (keycode == KEY_LEFT)
		data->keys.left = 0;
	if (keycode == KEY_RIGHT)
		data->keys.right = 0;
	if (keycode == KEY_ESC)
		data->keys.esc = 0;
	return (0);
}
