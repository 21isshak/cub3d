/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_images.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iskaraag <iskaraag@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 15:36:59 by iskaraag          #+#    #+#             */
/*   Updated: 2025/12/07 15:37:24 by iskaraag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	destroy_one_image(void *mlx, t_img *img)
{
	if (mlx && img->img)
	{
		mlx_destroy_image(mlx, img->img);
		img->img = NULL;
	}
}

void	destroy_images(t_data *data)
{
	if (!data)
		return ;
	destroy_one_image(data->mlx, &data->img);
	destroy_one_image(data->mlx, &data->tex.n_tex);
	destroy_one_image(data->mlx, &data->tex.s_tex);
	destroy_one_image(data->mlx, &data->tex.w_tex);
	destroy_one_image(data->mlx, &data->tex.e_tex);
}

int	close_window(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (!data)
		exit(0);
	destroy_images(data);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	free_texture_paths((&data->tex));
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	if (data->map.grid)
		free_split(data->map.grid);
	exit(0);
	return (0);
}
