/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwloskow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 21:32:16 by zwloskow          #+#    #+#             */
/*   Updated: 2025/12/06 15:12:22 by zwloskow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	player_dir_we(t_data *data)
{
	if (data->map.player.dir == 'E')
	{
		data->player.dir_x = 1.0;
		data->player.dir_y = 0.0;
		data->player.plane_x = 0.0;
		data->player.plane_y = 0.66;
	}
	if (data->map.player.dir == 'W')
	{
		data->player.dir_x = -1.0;
		data->player.dir_y = 0.0;
		data->player.plane_x = 0.0;
		data->player.plane_y = -0.66;
	}
}

void	init_player(t_data *data)
{
	data->player.x = data->map.player.x;
	data->player.y = data->map.player.y;
	player_dir_we(data);
	if (data->map.player.dir == 'N')
	{
		data->player.dir_x = 0.0;
		data->player.dir_y = -1.0;
		data->player.plane_x = 0.66;
		data->player.plane_y = 0.0;
	}
	if (data->map.player.dir == 'S')
	{
		data->player.dir_x = 0.0;
		data->player.dir_y = 1.0;
		data->player.plane_x = -0.66;
		data->player.plane_y = 0.0;
	}
}

void	initializing(t_data	*data)
{
	init_player(data);
	data->screen_w = 680 * 2;
	data->screen_h = 420 * 2;
}

int	game_loop(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	frame_counter(data);
	handle_keys(data);
	raycasting(data);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
	{
		print_error("Usage: ./cub3D map.cub");
		return (1);
	}
	ft_bzero(&data, sizeof(data));
	parse_cub(av[1], &data);
	initializing(&data);
	data.mlx = mlx_init();
	if (!data.mlx)
		close_window(&data);
	data.win = mlx_new_window(data.mlx, data.screen_w, data.screen_h, "cub3D");
	if (!data.win)
		close_window(&data);
	load_all_textures(&data);
	mlx_hook(data.win, 2, (1L << 0), key_press, &data);
	mlx_hook(data.win, 3, (1L << 1), key_release, &data);
	mlx_hook(data.win, 17, 0, close_window, &data);
	mlx_loop_hook(data.mlx, game_loop, &data);
	mlx_loop(data.mlx);
	return (0);
}
